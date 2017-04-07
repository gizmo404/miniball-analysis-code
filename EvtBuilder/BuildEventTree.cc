#include <iostream>
#include <iomanip>
#include <string>

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2S.h"
#include "TMath.h"

#include "CommandLineInterface.hh"
#include "BuiltEvent.hh"
#include "Calibration.hh"
#include "mbevts.hh"

#define GBINS 6000
#define GRANGE 6000
#define GMIN -1.0*GRANGE/GBINS
#define GMAX GRANGE+GMIN
#define GAMMA_ARRAY 250

using namespace std;

ClassImp(BuiltEvent)
ClassImp(AdcData)
ClassImp(DgfData)

//This function defines the Back strip position for the barrel
int StripPosBack(double frontene, double rearene){

	for (int i = 0; i < 16; i++){
	
		if( frontene/rearene <= 0.2 + 0.1125*(i+1) ) return i;

	}

	if( frontene/rearene >= 2 ) return 15;
	else return -1;
	
}

//This function transforms the energies into position for the barrel.
int *PosBBarrel(int quadr, vector<unsigned short> &adcval, double rear){
  
	int VLevel = 0;
	int mod = quadr;
	int stripmod = quadr;
	int firststrip = 0;

	if( (mod<0) || (rear<0) || (stripmod<0) || (firststrip<0) )
		cerr << "Error in Settings Quadrant " << quadr << " rear " << rear << " BStripMod " << stripmod << " BFirstStrip " << firststrip << endl;
  
	int *posBBarrel = new int[3]; // 0 = Multiplicity; 1 = PostFront; 2 = PostBack

	if( VLevel > 0 ) cout << "rear " << rear << endl;
 	int higheststrip = -1;
	int secondstrip = -1;
	//int thirdstrip = -1;
	double highestenergy = 0.;
	double secondenergy = 0.;
	double thirdenergy = 0.;
	double MinimalStripRatio = 0.75;
	double MinimalRearpRatio = 0.2;
  
	if( VLevel > 0 ) cout << "Quadrant " << quadr << " Module " << mod << endl;

	for( int i = firststrip; i < firststrip + 16; i++ ){

		if( adcval[i] > highestenergy ){
	
			secondstrip = higheststrip;
			higheststrip = i;

			thirdenergy = secondenergy;
			secondenergy = highestenergy;
			highestenergy = adcval[i];
			
		}
		
		else if( adcval[i] > secondenergy ){

			secondstrip = i;
			thirdenergy = secondenergy;
			secondenergy = adcval[i];

		}
		
	}
	
	if( VLevel > 0 ) cout << "3energy = " << thirdenergy << ". 2energy = " << secondenergy << ". 1energy = " << highestenergy << endl;
  
	if( higheststrip>-1 && ( highestenergy/rear > MinimalRearpRatio ) ) {

		if( (secondenergy/highestenergy > MinimalStripRatio ) && ( secondenergy/rear > MinimalRearpRatio ) ){

			if( VLevel > 0 ) {

				cout << "2energy = " << setprecision(2) << secondenergy << " 1energy = ";
				cout << setprecision(2) << highestenergy << " ratio = ";
				cout << setprecision(2) << secondenergy/highestenergy << endl;
				cout << "limit = " << setprecision(2) << MinimalStripRatio << endl;

			}
	  
			if( (thirdenergy/highestenergy > MinimalStripRatio) && (thirdenergy/rear > MinimalRearpRatio) ){ // three or more hits 	

				if( VLevel > 0 ) cout << "Multiplicity 3, energy 3 " << thirdenergy << endl;
				
				posBBarrel[0] = 3;
					
			}
				
			else {

				if( VLevel > 0 ) cout << "Multiplicity 2, energy 2 " << secondenergy << " energy 1 " << highestenergy << endl;

				posBBarrel[0] = 2;

			}
	  
			secondenergy = StripPosBack(adcval[secondstrip], rear); 
			highestenergy = StripPosBack(adcval[higheststrip], rear);
			
			// reconstruction hit
			if( TMath::Abs(higheststrip-secondstrip) == 1 && thirdenergy/rear < MinimalRearpRatio ) {

				posBBarrel[0] = 1;

			}
			
		}

		else {

			highestenergy = StripPosBack(adcval[higheststrip], rear);
			posBBarrel[0] = 1;
	  
			if( VLevel > 0 ) cout << "Multiplicity 1, energy " << highestenergy << endl;

		}
	
		posBBarrel[1] = higheststrip;
		posBBarrel[2] = highestenergy;
			
	}
		
	else {
		
		posBBarrel[0] = 0;

		if( VLevel > 0 ) cout << "Bad case" << endl;
			
	}
		
	if( VLevel>0 ) {
	
		cout << "rear " << rear << " highestenergy " << highestenergy;
		cout << " quadr " << quadr << " higheststrip " << higheststrip << endl;
		
	}

  	return posBBarrel;
  		
}


int main(int argc, char* argv[]) {

	vector<char*> InputFiles;
	string OutputFile;
	string CalibrationFile;
	bool NoPad = false;
	bool OnlyFBCD = false;
	bool VetoBCD = false;
	bool CheckParPos = false;
	bool verbose = false;
	CommandLineInterface* interface = new CommandLineInterface();

	interface->Add("-i", "inputfiles", &InputFiles );
	interface->Add("-o", "outputfile", &OutputFile );
	interface->Add("-np", "NoPadTriggering", &NoPad );
	interface->Add("-fcd", "OnlyFBCDTrig", &OnlyFBCD );
	interface->Add("-vbcd", "VetoBCD", &VetoBCD );
	interface->Add("-chpart", "CheckParPos", &CheckParPos );
	interface->Add("-c", "calibrationfile", &CalibrationFile );
	interface->Add("-vl", "verbose", &verbose );

	interface->CheckFlags(argc, argv);

	if( InputFiles.size() == 0 || OutputFile.size() == 0 ) {

		cerr << "You have to provide at least one input file and the output file!" << endl;
		exit(1);

	}

	if( CalibrationFile.size() == 0 ) {

		cout << "No Calibration File given, you have to provide one!" << endl;
		exit(1);

	}

	cout << "input file(s):" << endl;
	for( unsigned int i=0; i<InputFiles.size(); i++ ) {

		cout << InputFiles[i] << endl;
	
	}
	
	cout << "calibration file: " << CalibrationFile << endl;
	cout << "output file: " << OutputFile << endl;

	TChain* tr;
	tr = new TChain("tr");
	for( unsigned int i = 0; i < InputFiles.size(); i++ ) {
	
		tr->Add( InputFiles[i] );
		
	}

	if( tr == NULL ) {

		cout << "could not find tree caltr in file " << endl;

		for( unsigned int i=0; i < InputFiles.size(); i++ ) {

			cout << InputFiles[i] << endl;

		}
		
		return 3;

	}

	Calibration *Cal = new Calibration( CalibrationFile.c_str() );
	if(verbose) Cal->PrintCalibration();
  
	BuiltEvent* event = new BuiltEvent;

	tr->SetBranchAddress( "Event", &event );

	TFile* outfile = new TFile( OutputFile.c_str(), "recreate" );
	if( outfile->IsZombie() ) return 4;
	
	// Write to mb_evts tree
 	mbevts* write_mb_evts = new mbevts();
	mbevts* mb_evts[GAMMA_ARRAY];
	for( int i=0; i<GAMMA_ARRAY; i++ ) {
	
		mb_evts[i] = new mbevts();
		mb_evts[i]->Initialize();
		
	}
	TTree* g_clx = new TTree( "g_clx", "g_clx" );
	g_clx->Branch( "mbevts", "mbevts", &write_mb_evts );
 
	unsigned int i,j,k,l;
  
	// How many ticks need to align the prompt, in ticks.
	Double_t dtAdc[4] = {1.,0.,0.,0.};  // IS557
  
	// IS557
	Double_t tMinRandom = 15., tMaxRandom = 23;
	Double_t tMinPrompt = -26., tMaxPrompt = -18.;
 
	Double_t WeightPR = abs(tMinPrompt-tMaxPrompt)/abs(tMinRandom-tMaxRandom);
	
	if( verbose ) cout << "WeightPR: " << WeightPR << endl;
  
	double tdiffPG = 0.;

	// Which gates do you need in the particle detector.
	// Double_t GEMinAdc[4] = {200.,200.,200.,200.};
	// Double_t GEMaxAdc[4] = {4096.,4096.,4096.,4096.};

	// Which gates do you need in the gamma detector. 
	double GammaEnergy = 0.;
	double GammaEnergy2 = 0.;
	int GammaCtr = 0;
	int PartCtr = 0;
	double MaxSegEnergy = -99.;
	int MaxSegClu = -1;
	int MaxSegCore = -1;
	int MaxSegId = -1;
	int coinc_flag;
	Int_t dgf_num = 0;
	Int_t dgf_num2 = 0;
	Int_t dgf_ch = 0;
	Int_t dgf_ch2 = 0;
	Int_t dgf_en = 0;
	Int_t dgf_en2 = 0;
	long long dgf_t = 0;
	long long dgf_t2 = 0;
 
	Int_t RingPos1Chan = 18;
	Int_t RingPos2Chan = 19;
	Int_t RingEn1Chan = 16;
	Int_t RingEn2Chan = 17;
	Int_t StripPos1Chan = 22;
	Int_t StripPos2Chan = 23;
	Int_t StripEn1Chan = 20;
	Int_t StripEn2Chan = 21;
	Int_t CDPadChan = 24;
	Int_t BarrelTotEChan = 25;
  
	Double_t Threshold_CDRing_ID[4] = {300.,300.,300.,300.};
	Double_t Threshold_CDRing_E[4] = {100.,100.,100.,100.};
	Double_t Threshold_CDStrip_ID[4] = {300.,300.,300.,300.};
	Double_t Threshold_CDStrip_E[4] = {100.,100.,100.,100.};
	Double_t Threshold_FCDPad[4] = {500.,500.,500.,500.};
	Double_t Threshold_BBarrel[4] = {200.,100.,100.,100.};
	Double_t Threshold_BBarrelFront = 50.;
	Double_t LimtFBCD[4] = {800.,800.,800.,800.};
  
	Int_t DemuxRing = 0;
	Int_t DemuxStrip = 0;
  
	vector<unsigned short> cd_ringenergyhit1[4];
	vector<unsigned short> cd_ringenergyhit2[4];
	vector<unsigned short> cd_stripenergyhit1[4];
	vector<unsigned short> cd_stripenergyhit2[4];
	vector<unsigned short> cd_ringidhit1[4];
	vector<unsigned short> cd_ringidhit2[4];
	vector<unsigned short> cd_stripidhit1[4];
	vector<unsigned short> cd_stripidhit2[4];
  
	vector<unsigned int> Region; // 0: Top, 1: Bottom, 2: Left and 3; Right
	vector<unsigned int> Elem_fired; // 0: FCD, 1: Barrel, 2: BCD and 3: Pad
	vector<unsigned int> Chan_front; // Rings for CDs, Total Energy for Pad or Strips for Barrel
	vector<double> Ener_front;
	vector<unsigned int> Chan_back; // Strips for CDs and Total Energy for Barrel
	vector<double> Ener_back;
	vector<long long> time;
	vector<bool> laser;
  
	Int_t LastEntry = 0;
	Int_t LastAdc = 0;
  
	bool HitFCDPad = false;
	bool FCDPadTrig = false;
	bool HitBBarrel = false;
  
	Double_t EnergyBad = 0.;
	Double_t EnergyBarrelBack = 0.;
  
	int* ValuesPosBBarrel;
	int MultBBarrel = 0;
	int StripFront = 0;
	int StripBack = 0;
  
	vector<unsigned short> EnergyBarrelFront(16);
  
	// Check Code
	Int_t CounterAdcCDFired[4] = {0,0,0,0};
  
  
	// ------ Histograms ------ //

	// Histogram errors
	TH1::SetDefaultSumw2();
  
	// diagnostics
	TH1F* adc = new TH1F("adc","adc",8,-0.5,7.5);
	adc->GetXaxis()->SetTitle("Number of ADC's");
	TH1F* dgf = new TH1F("dgf","dgf",56,-0.5,55.5);
	dgf->GetXaxis()->SetTitle("Number of DGF's");
	TH1F* free_dgf = new TH1F("free_dgf","free_dgf",56,-0.5,55.5);
	free_dgf->GetXaxis()->SetTitle("Number of free DGF's");

	// time differences
	TH1F* tdiff = new TH1F("tdiff","tdiff",2000,-1000,1000);
	tdiff->GetXaxis()->SetTitle("time diff (particle - gamma) [us]");
	TH1F* gam_tdiff = new TH1F("gam_tdiff","gam_tdiff",2000,-100,100);
	gam_tdiff->GetXaxis()->SetTitle("time diff between one Dgf and the others [us]");

	// Total gamma - no Doppler correction
	TH1F* E_gam = new TH1F("E_gam","E_gam",GBINS,GMIN,GMAX);
	E_gam->GetXaxis()->SetTitle("Energy Gamma Rays [Channels]");

	// Gamma spectra for every segment - no Doppler correction
	TH1F* E_gam_seg[8][3][7];
	TDirectory *gam_dir = outfile->mkdir("E_gam_seg");
	gam_dir->cd();
	for( i = 0; i < 8; i++ ) {

		for( j = 0; j < 3; j++ ) {

			for( k = 0; k < 7; k++ ) {

				E_gam_seg[i][j][k] = new TH1F(Form("E_gam_%d_%d_%d",i,j,k),Form("E_gam_%d_%d_%d",i,j,k),GBINS,GMIN,GMAX);
				E_gam_seg[i][j][k]->GetXaxis()->SetTitle("Energy Gamma Rays [Channels]");

			}

		}

	}
	gDirectory->cd("/");
	
	TH1F* E_BeamDump = new TH1F("E_BeamDump","E_BeamDump",GBINS,GMIN,GMAX);
	E_BeamDump->GetXaxis()->SetTitle("Energy of the Beam Dump [keV]");
	TH1F* T_BeamDump = new TH1F("T_BeamDump","T_BeamDump",7200,0,7200);	
	T_BeamDump->GetXaxis()->SetTitle("Time of the Beam Dump [s]");

	// particle-spectra
	TH2F* FBCD_Rings_id_energy_hit1[4];
	TH2F* FBCD_Rings_id_energy_hit2[4];
	TH2F* FBCD_Strips_id_energy_hit1[4];
	TH2F* FBCD_Strips_id_energy_hit2[4];
	for( i = 0; i < 4; i++ ) {
	
		FBCD_Rings_id_energy_hit1[i] = new TH2F(Form("FBCD_Rings_id_energy_hit1_%d",i),Form("FBCD_Rings_id_energy_hit1_%d",i),1200,300,1500,4096,0,4096);
		FBCD_Rings_id_energy_hit1[i]->GetXaxis()->SetTitle("Energy ID MUX");
		FBCD_Rings_id_energy_hit1[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
		FBCD_Rings_id_energy_hit2[i] = new TH2F(Form("FBCD_Rings_id_energy_hit2_%d",i),Form("FBCD_Rings_id_energy_hit2_%d",i),1200,300,1500,4096,0,4096);
		FBCD_Rings_id_energy_hit2[i]->GetXaxis()->SetTitle("Energy ID MUX");
		FBCD_Rings_id_energy_hit2[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
		FBCD_Strips_id_energy_hit1[i] = new TH2F(Form("FBCD_Strips_id_energy_hit1_%d",i),Form("FBCD_Strips_id_energy_hit1_%d",i),1200,300,1500,4096,0,4096);
		FBCD_Strips_id_energy_hit1[i]->GetXaxis()->SetTitle("Energy ID MUX");
		FBCD_Strips_id_energy_hit1[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
		FBCD_Strips_id_energy_hit2[i] = new TH2F(Form("FBCD_Strips_energy_id_hit2_%d",i),Form("FBCD_Strips_id_energy_hit2_%d",i),1200,300,1500,4096,0,4096);
		FBCD_Strips_id_energy_hit2[i]->GetXaxis()->SetTitle("Energy ID MUX");
		FBCD_Strips_id_energy_hit2[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
	
	}

	Double_t nentries = tr->GetEntries();
	Int_t nbytes = 0;
	Int_t status;
	vector<int> DgfModule;
	
	// Test - comment out for runs
	//nentries = 10000;
	
	// Start loop over number of entries
	for( i = 0; i < nentries; i++ ) {
	
		status = tr->GetEvent(i);
		if( status == -1 ) {

			cerr << "Error occured, couldn't read entry " << i << " from tree ";
			cerr << tr->GetName() << " in file " << tr->GetFile()->GetName() << endl;
			return 5;
			
		}
		
		else if( status == 0 ) {

			cerr << "Error occured, entry " << i << " in tree " << tr->GetName();
			cerr << " in file " << tr->GetFile()->GetName() << " doesn't exist" << endl;
			return 6;

		}
		
		nbytes += status;

		// Sort out mb_evts
		for( j = 0; j < GammaCtr; j++ ) {
		
			mb_evts[j]->SearchCoin();  
			write_mb_evts->Initialize();
			write_mb_evts->CopyData( mb_evts[j] );
			if( write_mb_evts->pr_hits > 0 || write_mb_evts->rndm_hits > 0 ) g_clx->Fill(); 
			
		}
		
		// Reset
		for( j = 0; j < GAMMA_ARRAY; j++ ) {
		
			mb_evts[j]->Initialize();
		
		}
		GammaCtr = 0;


		DgfModule.clear();

		for( j = 0; j < event->NumberOfDgfs(); j++ ) {

			for( k = 0; k < DgfModule.size(); k++ ) 

				if( event->Dgf(j)->ModuleNumber() == DgfModule[k] ) break;
			
			if( k == DgfModule.size() ) DgfModule.push_back( event->Dgf(j)->ModuleNumber() );

		}
	
		for( j = 0; j < 4; j++ ) {

			cd_ringenergyhit1[j].clear();
			cd_ringenergyhit2[j].clear();
			cd_stripenergyhit1[j].clear();
			cd_stripenergyhit2[j].clear();
			cd_ringidhit1[j].clear();
			cd_ringidhit2[j].clear();
			cd_stripidhit1[j].clear();
			cd_stripidhit2[j].clear();

		}
	
		Region.clear();
		Elem_fired.clear();
		Chan_front.clear();
		Ener_front.clear();
		Chan_back.clear();
		Ener_back.clear();
		time.clear();
		laser.clear();
	  
		adc->Fill( event->NumberOfAdcs() );
		dgf->Fill( DgfModule.size() );
		  
		if( event->NumberOfAdcs() == 0 ) {
	
			free_dgf->Fill( DgfModule.size() );

			for( j = 0; j < event->NumberOfDgfs(); j++ ) {

				for( k = j+1; k < event->NumberOfDgfs(); k++ ) {

					gam_tdiff->Fill(dgf_t - event->Dgf(k)->Time());

				}

			}

		}

		// Only Gammas
		for( j = 0; j < event->NumberOfDgfs(); j++ ) {

			dgf_num = event->Dgf(j)->ModuleNumber();
			dgf_ch  = event->Dgf(j)->Channel();
			dgf_en  = event->Dgf(j)->Energy();
			dgf_t   = event->Dgf(j)->Time();
				
			if( 0 <= dgf_num && dgf_num < 48 && 0 <= dgf_ch && dgf_ch < 4 ) {

				GammaEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );

				if( dgf_num % 2 == 0 && dgf_ch < 3 ) { // cores plus seg1 and seg2

					E_gam_seg[dgf_num/6][dgf_num%6/2][dgf_ch]->Fill( GammaEnergy );
					if( dgf_ch ) E_gam->Fill( GammaEnergy );

				} // even DGF number

				else {

					E_gam_seg[dgf_num/6][dgf_num%6/2][dgf_ch+3]->Fill( GammaEnergy );

				} // odd DGF number
					
			}

			else if( dgf_num == 53 && dgf_ch == 0 ) {

				GammaEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );
				E_BeamDump->Fill(Cal->DgfEnergy(53,0,dgf_en));
				T_BeamDump->Fill((dgf_t)/40000000);

			}

		}
		
		// Only Particles
		for( j = 0; j < event->NumberOfAdcs(); j++ ) {

			HitFCDPad = false;
			HitBBarrel = false;
			EnergyBarrelFront.assign( EnergyBarrelFront.size(), 0 );

			for( k = 0; k < event->Adc(j)->SubEvent()->Size(); k++ ) {

				if( 0 <= event->Adc(j)->ModuleNumber() && event->Adc(j)->ModuleNumber() < 4
					&& 0 <= event->Adc(j)->SubEvent()->AdcChannel(k) && event->Adc(j)->SubEvent()->AdcChannel(k) < 26 ) {

					if( event->Adc(j)->SubEvent()->AdcChannel(k) < 16 ) {

						if( event->Adc(j)->SubEvent()->AdcValue(k) > Threshold_BBarrelFront && event->Adc(j)->SubEvent()->AdcValue(k) < 3840)

							EnergyBarrelFront[event->Adc(j)->SubEvent()->AdcChannel(k)] = event->Adc(j)->SubEvent()->AdcValue(k);
					
					}

					else if( event->Adc(j)->SubEvent()->AdcChannel(k) == CDPadChan ) {

						if( event->Adc(j)->SubEvent()->AdcValue(k) > Threshold_FCDPad[event->Adc(j)->ModuleNumber()] ) {

							HitFCDPad = true;
							EnergyBad = event->Adc(j)->SubEvent()->AdcValue(k);

						}

					}
					
					else if( event->Adc(j)->SubEvent()->AdcChannel(k) == BarrelTotEChan ) {

						if( event->Adc(j)->SubEvent()->AdcValue(k) > Threshold_BBarrel[event->Adc(j)->ModuleNumber()]
							&& event->Adc(j)->SubEvent()->AdcValue(k) < 3840 ) {

							HitBBarrel = true;
							EnergyBarrelBack = event->Adc(j)->SubEvent()->AdcValue(k);

						}

					}

					else if( event->Adc(j)->SubEvent()->AdcChannel(k) == RingEn1Chan ) 
						cd_ringenergyhit1[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == RingEn2Chan)
						cd_ringenergyhit2[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == RingPos1Chan)
						cd_ringidhit1[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == RingPos2Chan)
						cd_ringidhit2[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == StripEn1Chan)
						cd_stripenergyhit1[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == StripEn2Chan)
						cd_stripenergyhit2[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == StripPos1Chan)
						cd_stripidhit1[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

					else if(event->Adc(j)->SubEvent()->AdcChannel(k) == StripPos2Chan)
						cd_stripidhit2[event->Adc(j)->ModuleNumber()].push_back(event->Adc(j)->SubEvent()->AdcValue(k));

				} // good adc
			
			} // k
		  
			LastEntry = cd_ringenergyhit1[event->Adc(j)->ModuleNumber()].size() - 1;

			if( HitBBarrel ) {

				ValuesPosBBarrel = PosBBarrel(event->Adc(j)->ModuleNumber(), EnergyBarrelFront, EnergyBarrelBack);
				MultBBarrel = ValuesPosBBarrel[0];
				StripFront = ValuesPosBBarrel[1];
				StripBack = ValuesPosBBarrel[2];

				if( MultBBarrel == 0 ) HitBBarrel = false;

			} // HitBBarrel
		  
			// New Particle structure
			LastAdc = event->Adc(j)->ModuleNumber();
		
			// Veto if the Pad is not in the trigger
			if( !NoPad && HitFCDPad ) FCDPadTrig = true;
			else FCDPadTrig = false;

			// Only hit in one of the CDs And veto if the Pad is not in the trigger
			if( !FCDPadTrig && ( !HitBBarrel || OnlyFBCD ) && cd_ringenergyhit1[LastAdc].size() > 0 && LastAdc < 4) {

				LastEntry = cd_ringenergyhit1[LastAdc].size() - 1;
				CounterAdcCDFired[LastAdc]++;

				DemuxRing = Cal->PosFBCDRing(LastAdc,cd_ringidhit1[LastAdc][LastEntry]);
				DemuxStrip = Cal->PosFBCDStrip(LastAdc,cd_stripidhit1[LastAdc][LastEntry]);

				if( cd_ringidhit1[LastAdc][LastEntry] > Threshold_CDRing_ID[LastAdc]
					&& cd_ringenergyhit1[LastAdc][LastEntry] > Threshold_CDRing_E[LastAdc]
					&& cd_stripidhit1[LastAdc][LastEntry] > Threshold_CDStrip_ID[LastAdc]
					&& cd_stripenergyhit1[LastAdc][LastEntry] > Threshold_CDStrip_E[LastAdc]
					&& ( cd_ringidhit1[LastAdc][LastEntry] < LimtFBCD[LastAdc] && cd_stripidhit1[LastAdc][LastEntry] < LimtFBCD[LastAdc] )
					&& ( cd_ringidhit1[LastAdc][LastEntry] < 3840 && cd_stripidhit1[LastAdc][LastEntry] < 3840 )
					&& ( cd_ringenergyhit1[LastAdc][LastEntry] < 3840 && cd_stripenergyhit1[LastAdc][LastEntry] < 3840 )
					&& DemuxRing < 16 && DemuxStrip < 16 ) {

					// The FCD was fired
					if( cd_ringidhit2[LastAdc][LastEntry] < Threshold_CDRing_ID[LastAdc]
						&& cd_stripidhit2[LastAdc][LastEntry] < Threshold_CDStrip_ID[LastAdc] ) { 

						// 1 ring and 1 strip fired, no reconstruction energy
						Region.push_back(LastAdc);
						Elem_fired.push_back(0);
						Chan_front.push_back(DemuxRing);
						Ener_front.push_back(Cal->AdcEnergy(LastAdc, Chan_front.back(), cd_ringenergyhit1[LastAdc][LastEntry]));
						Chan_back.push_back(DemuxStrip);
						Ener_back.push_back(cd_stripenergyhit1[LastAdc][LastEntry]);

						time.push_back(event->Adc(j)->Time() + dtAdc[LastAdc]);
						laser.push_back(event->Adc(j)->LaserOn());
					
					}
				
				}
			
				else if( cd_ringidhit1[LastAdc][LastEntry] > Threshold_CDRing_ID[LastAdc]
					&& cd_ringenergyhit1[LastAdc][LastEntry] > Threshold_CDRing_E[LastAdc]
					&& cd_stripidhit1[LastAdc][LastEntry] > Threshold_CDStrip_ID[LastAdc]
					&& cd_stripenergyhit1[LastAdc][LastEntry] > Threshold_CDStrip_E[LastAdc]
					&& ( cd_ringidhit1[LastAdc][LastEntry] > LimtFBCD[LastAdc] && cd_stripidhit1[LastAdc][LastEntry] > LimtFBCD[LastAdc] )
					&& ( cd_ringidhit1[LastAdc][LastEntry] < 3840 && cd_stripidhit1[LastAdc][LastEntry] < 3840 )
					&& ( cd_ringenergyhit1[LastAdc][LastEntry] < 3840 && cd_stripenergyhit1[LastAdc][LastEntry] < 3840 )
					&& DemuxRing < 16 && DemuxStrip < 16 && !VetoBCD ) {
				
					// The BCD was fired
					if( cd_ringidhit2[LastAdc][LastEntry] < Threshold_CDRing_ID[LastAdc] 
						&& cd_stripidhit2[LastAdc][LastEntry] < Threshold_CDRing_ID[LastAdc] ) {

						// 1 ring and 1 strip fired, no reconstruction energy
						Region.push_back(LastAdc);
						Elem_fired.push_back(2);
						Chan_front.push_back(DemuxRing);
						Ener_front.push_back(cd_ringenergyhit1[LastAdc][LastEntry]);
						Chan_back.push_back(DemuxStrip);
						Ener_back.push_back(cd_stripenergyhit1[LastAdc][LastEntry]);

						time.push_back(event->Adc(j)->Time() + dtAdc[LastAdc]);
						laser.push_back(event->Adc(j)->LaserOn());

					}

				}
			
			}
		
			// Only hit in the BBarrel And veto if the Pad is not in the trigger
			else if( !FCDPadTrig && HitBBarrel && LastAdc < 4 ) { 
	
				if( MultBBarrel == 1 ) {

					Region.push_back(LastAdc);
					Elem_fired.push_back(1);
					Chan_front.push_back(StripFront);
					Ener_front.push_back(EnergyBarrelBack);
					Chan_back.push_back(StripBack); // ratio: EneFirstStripHit/EnergyBarrelBack
					Ener_back.push_back(EnergyBarrelBack);

					time.push_back(event->Adc(j)->Time() + dtAdc[LastAdc]);
					laser.push_back(event->Adc(j)->LaserOn());

				}
			
			}
		
			// Only hit in the FCD Pad and the Pad is in the trigger
			else if( FCDPadTrig && HitFCDPad && !HitBBarrel && LastAdc < 4 ) {

				Region.push_back(LastAdc);
				Elem_fired.push_back(3);
				Chan_front.push_back(0);
				Ener_front.push_back(EnergyBad);
				Chan_back.push_back(0);
				Ener_back.push_back(0);

				time.push_back(event->Adc(j)->Time() + dtAdc[LastAdc]);
				laser.push_back(event->Adc(j)->LaserOn());

			}
		  
		} // numberofadcs
	
		for( j = 0; j < 4; j++ ) {
	
			for( k = 0; k < cd_ringenergyhit1[j].size(); k++ ) 

				FBCD_Rings_id_energy_hit1[j]->Fill(cd_ringidhit1[j][k], cd_ringenergyhit1[j][k]);
			
			for( k = 0; k < cd_ringenergyhit2[j].size(); k++ )

				FBCD_Rings_id_energy_hit2[j]->Fill(cd_ringidhit2[j][k], cd_ringenergyhit2[j][k]);
		  
			for( k = 0; k < cd_stripenergyhit1[j].size(); k++ )

				FBCD_Strips_id_energy_hit1[j]->Fill(cd_stripidhit1[j][k], cd_stripenergyhit1[j][k]);

			for( k = 0; k < cd_stripenergyhit2[j].size(); k++ )

				FBCD_Strips_id_energy_hit2[j]->Fill(cd_stripidhit2[j][k], cd_stripenergyhit2[j][k]);
		  
		} // j

		// Gamma-particle coincidences
		for( j = 0; j < event->NumberOfDgfs(); j++ ) {
	
			dgf_num = event->Dgf(j)->ModuleNumber();
			dgf_ch  = event->Dgf(j)->Channel();
			dgf_en  = event->Dgf(j)->Energy();
			dgf_t   = event->Dgf(j)->Time();		
		  
		  	// Look for a core event
			if( 0 <= dgf_num && dgf_num < 48 && dgf_ch == 0 && dgf_num % 2 == 0 ) {
			
				GammaEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );
				MaxSegClu = dgf_num / 6;
				MaxSegCore = dgf_num % 6 / 2;						

				// Check for highest energy segment in same detector
				for( k = 0; k < event->NumberOfDgfs(); k++ ) {
			
					dgf_num2 = event->Dgf(k)->ModuleNumber();
					dgf_ch2  = event->Dgf(k)->Channel();
					dgf_en2  = event->Dgf(k)->Energy();
					dgf_t2   = event->Dgf(k)->Time();
					
					// We don't care if it's the same event
					if( k == j ) continue;
			
					// Skip if a different detector
					if( dgf_num2 != dgf_num && dgf_num2 != dgf_num + 1 ) continue;
					
					GammaEnergy2 = Cal->DgfEnergy( dgf_num2, dgf_ch2, dgf_en2 );

					// Test maximum energy segment
					if( GammaEnergy2 < MaxSegEnergy ) continue;
					
					// Reassign energy and id
					MaxSegEnergy = GammaEnergy2;
					if( dgf_num2 % 2 == 0 ) MaxSegId = dgf_ch2 - 1;
					else MaxSegId = dgf_ch2+3 - 1;					
			
				} // k

				// Found highest energy segment
				mb_evts[GammaCtr]->SetGen( GammaEnergy );
				mb_evts[GammaCtr]->SetCluid( MaxSegClu );
				mb_evts[GammaCtr]->SetCid( MaxSegClu*3 + MaxSegCore );
				mb_evts[GammaCtr]->SetSid( MaxSegId );
				mb_evts[GammaCtr]->SetTheta( 0. );
				mb_evts[GammaCtr]->SetPhi( 0. );
					
				// Do particles
				for( k = 0; k < Elem_fired.size(); k++ ) {

					tdiffPG = time[k] - dgf_t;
		  
					if( tMinRandom <= tdiffPG && tdiffPG <= tMaxRandom ) coinc_flag = 1;
					else if( tMinPrompt <= tdiffPG && tdiffPG <= tMaxPrompt ) coinc_flag = 0;
					else coinc_flag = -1;			
					
					// Deal with the front CD only with mb_evts
					if( Elem_fired[k] != 0 ) continue;

					// Add particle
					mb_evts[GammaCtr]->SetPart( Ener_front[k], (int)Chan_front[k], (int)Chan_back[k], (double)time[k],
						(double)event->SuperCycleTime()/1000000, (double)tdiffPG, (int)coinc_flag, Region[k], (int)laser[k], PartCtr );
						
					PartCtr++;

				} // End loop All the particles

			// Count the gamma!
			GammaCtr++;

			} // real event in the core?			

			// Reset
			MaxSegEnergy = -99.;
			MaxSegClu = -1;
			MaxSegCore = -1;
			MaxSegId = -1;
			PartCtr = 0;
		
		} // j
		
		// Progress bar
		if( i%50000 == 0 ) cout << setw(5) << setiosflags(ios::fixed) << setprecision(1) << (100.*i)/nentries << "% done\r" << flush;

	} // i

	cout << "Check ADCs Fired:" << endl;
	for( i = 0; i < 4; i++ ) cout << " Adc # " << i << " fired: " << CounterAdcCDFired[i] << endl;
   
	outfile->Write();
	outfile->Close();
	delete tr;

	return 0;
	
}

