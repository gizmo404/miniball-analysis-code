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
#include "ParticleRange.hh"
#include "../mbevts/mbevts.hh"

#define PBINS 800
#define PRANGE 800
#define PMIN -1.0*PRANGE/PBINS
#define PMAX PRANGE+PMIN

#define GBINS 8000
#define GRANGE 8000
#define GMIN -1.0*GRANGE/GBINS
#define GMAX GRANGE+GMIN
#define GAMMA_ARRAY 250

#define ELBINS 2000
#define ELRANGE 1000
#define ELMIN -1.0*ELRANGE/ELBINS
#define ELMAX ELRANGE+ELMIN
#define ELECTRON_ARRAY 250

using namespace std;

ClassImp(BuiltEvent)
ClassImp(AdcData)
ClassImp(DgfData)

int main(int argc, char* argv[]) {

	vector<char*> InputFiles;
	string OutputFile;
	string CalibrationFile;
	string RangeFile;
	bool Singles = false;
	bool verbose = false;
	bool muxed 	 = false;
	CommandLineInterface* interface = new CommandLineInterface();

	interface->Add("-i", "inputfiles", &InputFiles );
	interface->Add("-o", "outputfile", &OutputFile );
	interface->Add("-c", "calibrationfile", &CalibrationFile );
	interface->Add("-s", "singles", &Singles );
	interface->Add("-vl", "verbose", &verbose );
	interface->Add("-m", "muxed", &muxed );//for muxed data
	interface->Add("-r", "rangefile",&RangeFile);

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

		for( unsigned int i = 0; i < InputFiles.size(); i++ ) {

			cout << InputFiles[i] << endl;

		}

		return 3;

	}
	if (muxed && RangeFile.size() == 0){//if you mux you must range
		cerr << "Error: No range file provided." << endl;
		exit(1);
	}


	Calibration *Cal = new Calibration( CalibrationFile.c_str() );
	if(verbose) Cal->PrintCalibration();

	if (muxed)
	{
		ParticleRange range;
		range.Read(RangeFile);
	}

	BuiltEvent *event = new BuiltEvent;

	tr->SetBranchAddress( "Event", &event );

	TFile* outfile = new TFile( OutputFile.c_str(), "recreate" );
	if( outfile->IsZombie() ) return 4;

	// Write to mb_evts tree
	mbevts* write_mb_evts = new mbevts();
	mbevts* mb_evts[GAMMA_ARRAY];
	for( int i = 0; i < GAMMA_ARRAY; i++ ) {

		mb_evts[i] = new mbevts();
		mb_evts[i]->Initialize();

	}

	TTree* g_clx = new TTree( "g_clx", "g_clx" );
	g_clx->Branch( "mbevts", "mbevts", &write_mb_evts );

	unsigned int i,j,k,l;

	// How many ticks need to align the prompt, in ticks.
	//	Double_t dtAdc[4] = {1.,0.,0.,0.};  // IS557
	Double_t dtAdc[4] = {-6.,-4.,1.,0.};  // spede

	// IS557
	Double_t tMinRandom = -10., tMaxRandom = 10.;
	Double_t tMinPrompt = -30., tMaxPrompt = -16.;

	Double_t tMinRandomElectron = -20., tMaxRandomElectron = 0.;
	Double_t tMinPromptElectron = 2., tMaxPromptElectron = 16.;

	Double_t WeightPR = abs(tMinPrompt-tMaxPrompt)/abs(tMinRandom-tMaxRandom);

	if( verbose ) cout << "WeightPR: " << WeightPR << endl;

	double tdiffPG = 0.;

	// Which gates do you need in the particle detector.
	// Double_t GELMINAdc[4] = {200.,200.,200.,200.};
	// Double_t GELMAXAdc[4] = {4096.,4096.,4096.,4096.};

	// Which gates do you need in the gamma detector. 
	double GammaEnergy = 0.;
	double GammaEnergy2 = 0.;
	double GammaEnergy3 = 0.;
	double GammaEnergy4 = 0.;
	double ElectronEnergy = 0.;
	int GammaCtr = 0;
	int PartCtr = 0;
	double MaxSegEnergy = -99.;
	double MaxSegEnergy2 = -99.;
	int MaxSegClu = -1;
	int MaxSegClu2 = -1;
	int MaxSegCore = -1;
	int MaxSegCore2 = -1;
	int MaxSegId = -1;
	int MaxSegId2 = -1;
	int coinc_flag;
	Int_t dgf_num = 0;
	Int_t dgf_num2 = 0;
	Int_t dgf_num3 = 0;
	Int_t dgf_num4 = 0;
	Int_t dgf_ch = 0;
	Int_t dgf_ch2 = 0;
	Int_t dgf_ch3 = 0;
	Int_t dgf_ch4 = 0;
	Int_t dgf_en = 0;
	Int_t dgf_en2 = 0;
	Int_t dgf_en3 = 0;
	Int_t dgf_en4 = 0;
	long long dgf_t = 0;
	long long dgf_t2 = 0;
	long long dgf_t3 = 0;
	long long dgf_t4 = 0;
	Int_t adc_num = 0;
	Int_t adc_ch = 0;
	Int_t adc_en = 0;
	long long adc_t =0;

	//muxing variables
	int RingPos1Chan = 18;
	int RingPos2Chan = 19;
	int RingEn1Chan = 16;
	int RingEn2Chan = 17;
	int StripPos1Chan = 22;
	int StripPos2Chan = 23;
	int StripEn1Chan = 20;
	int StripEn2Chan = 21;
	int CDPadChan = 24;


	vector<unsigned short> cd_ringenergyhit1[4];
	vector<unsigned short> cd_ringenergyhit2[4];
	vector<unsigned short> cd_stripenergyhit1[4];
	vector<unsigned short> cd_stripenergyhit2[4];
	vector<unsigned short> cd_ringidhit1[4];
	vector<unsigned short> cd_ringidhit2[4];
	vector<unsigned short> cd_stripidhit1[4];
	vector<unsigned short> cd_stripidhit2[4];
	vector<unsigned long long> cd_ringtime1[4];
	vector<unsigned long long> cd_ringtime2[4];
	vector<unsigned short> cd_pad[4];

	vector<unsigned short> dgf_si_module;
	vector<unsigned short> dgf_si_channel;
	vector<unsigned long long> dgf_si_time;

	Double_t Threshold_CDRing_E[4] = {100.,100.,100.,100.};
	Double_t Threshold_CDStrip_E[4] = {100.,100.,100.,100.};

	vector<unsigned int> Quad; // CD quadrant
	vector<unsigned int> Chan_front; // Rings for CDs, Total Energy for Pad or Strips for Barrel
	vector<double> Ener_front;
	vector<unsigned int> Chan_back; // Strips for CDs and Total Energy for Barrel
	vector<double> Ener_back;
	vector<long long> time;
	vector<bool> laser;

	int tempStripNum = 0;
	int tempRingNum = 0;
	int tempStripEnergy = 0;
	int tempRingEnergy = 0;
	int tempStripTime = 0;
	long long tempRingTime = 0;

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
	TH1F* tdiff_gp = new TH1F("tdiff_gp","tdiff_gp",2000,-1000,1000);
	tdiff_gp->GetXaxis()->SetTitle("time diff (particle - gamma) [us]");
	TH1F* tdiff_ep = new TH1F("tdiff_ep","tdiff_ep",2000,-1000,1000);
	tdiff_ep->GetXaxis()->SetTitle("time diff (particle - electron) [us]");
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
	// Total electron - no Doppler correction
	TH1F* E_spede = new TH1F("E_spede","E_spede",ELBINS,ELMIN,ELMAX);
	E_spede->GetXaxis()->SetTitle("Energy Electrons [Channels]");

	// Electron spectra for every segment - no Doppler correction
	TH1F* E_spede_seg[24];
	TDirectory *spede_dir = outfile->mkdir("E_spede_seg");
	spede_dir->cd();
	for( i = 0; i < 24; i++ ) {

		E_spede_seg[i] = new TH1F(Form("E_spede_%d",i),Form("E_spede_%d",i),ELBINS,ELMIN,ELMAX);
		E_spede_seg[i]->GetXaxis()->SetTitle("Energy Electrons [Channels]");

	}
	gDirectory->cd("/");

	TH1F* E_BeamDump = new TH1F("E_BeamDump","E_BeamDump",GBINS,GMIN,GMAX);
	E_BeamDump->GetXaxis()->SetTitle("Energy of the Beam Dump [keV]");
	TH1F* T_BeamDump = new TH1F("T_BeamDump","T_BeamDump",7200,0,7200);	
	T_BeamDump->GetXaxis()->SetTitle("Time of the Beam Dump [s]");

	// particle-spectra
	TH2F* CD_front_energy[4];
	TH2F* CD_back_energy[4];
	for( i = 0; i < 4; i++ ) {

		CD_front_energy[i] = new TH2F(Form("CD_front_energy_%d",i),Form("CD_front_energy_%d",i),16,-0.5,15.5,4096,0,4096);
		CD_front_energy[i]->GetXaxis()->SetTitle("Ring number");
		CD_front_energy[i]->GetYaxis()->SetTitle("Energy particle [MeV]");
		CD_back_energy[i] = new TH2F(Form("CD_back_energy_%d",i),Form("CD_back_energy_%d",i),16,-0.5,15.5,4096,0,4096);
		CD_back_energy[i]->GetXaxis()->SetTitle("Strip number");
		CD_back_energy[i]->GetYaxis()->SetTitle("Energy particle [MeV]");

	}

	TH2F* FBCD_Rings_id_energy_hit1[4];
	TH2F* FBCD_Rings_id_energy_hit2[4];
	TH2F* FBCD_Strips_id_energy_hit1[4];
	TH2F* FBCD_Strips_id_energy_hit2[4];

	TH1F* FCD_Rings[4][16];
	TH1F* FCD_Strips[4][16];

	TH1F *FCD_pad[4];

	TH1F *thick[4];

	TH2F* de_e_quad[4][16];
	TH2F* de_e_quad_gate[4][16];
	if (muxed)
	{
		for (int i = 0 ; i < 4 ; ++i){
			thick[i] = new TH1F(Form("thick_q%d",i+1),Form("thick_q%d",i+1),4000,0,4000);
		}

		// Demuxing
		for(int i = 0; i < 4; i++ )
		{
			FBCD_Rings_id_energy_hit1[i] = new TH2F(Form("FBCD_Rings_id_energy_hit1_%d",i),Form("FBCD_Rings_id_energy_hit1_%d",i),1500,0,1500,4096,0,4096);
			FBCD_Rings_id_energy_hit1[i]->GetXaxis()->SetTitle("Energy ID MUX");
			FBCD_Rings_id_energy_hit1[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
			FBCD_Rings_id_energy_hit2[i] = new TH2F(Form("FBCD_Rings_id_energy_hit2_%d",i),Form("FBCD_Rings_id_energy_hit2_%d",i),1500,0,1500,4096,0,4096);
			FBCD_Rings_id_energy_hit2[i]->GetXaxis()->SetTitle("Energy ID MUX");
			FBCD_Rings_id_energy_hit2[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
			FBCD_Strips_id_energy_hit1[i] = new TH2F(Form("FBCD_Strips_id_energy_hit1_%d",i),Form("FBCD_Strips_id_energy_hit1_%d",i),1500,0,1500,4096,0,4096);
			FBCD_Strips_id_energy_hit1[i]->GetXaxis()->SetTitle("Energy ID MUX");
			FBCD_Strips_id_energy_hit1[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
			FBCD_Strips_id_energy_hit2[i] = new TH2F(Form("FBCD_Strips_energy_id_hit2_%d",i),Form("FBCD_Strips_id_energy_hit2_%d",i),1500,0,1500,4096,0,4096);
			FBCD_Strips_id_energy_hit2[i]->GetXaxis()->SetTitle("Energy ID MUX");
			FBCD_Strips_id_energy_hit2[i]->GetYaxis()->SetTitle("Energy particle [Channels]");
		}

		TDirectory *Rings_dir = outfile->mkdir("rings_singles");
		TDirectory *Strips_dir = outfile->mkdir("strips_singles");
		for (int i = 0 ; i < 4 ; ++i)
		{
			for (int j = 0 ; j < 16 ; ++j)
			{
				Rings_dir->cd();
				FCD_Rings[i][j] = new TH1F(Form("FCD_Rings_q%d_%d",i+1,j+1), Form("FCD_Rings_q%d_%d",i+1,j+1), 4096, 0, 4096);
				FCD_Rings[i][j]->GetXaxis()->SetTitle("Energy [ch]");
				FCD_Rings[i][j]->GetYaxis()->SetTitle("Counts/ch");
				gDirectory->cd("/");
				Strips_dir->cd();
				FCD_Strips[i][j] = new TH1F(Form("FCD_Strips_q%d_%d",i+1,j+1), Form("FCD_Strips_q%d_%d",i+1,j+1), 4096, 0, 4096);
				FCD_Strips[i][j]->GetXaxis()->SetTitle("Energy [ch]");
				FCD_Strips[i][j]->GetYaxis()->SetTitle("Counts/ch");
				gDirectory->cd("/");
			}
		}
		TDirectory *Back_dir = outfile->mkdir("CDPAD");
		Back_dir->cd();
		for (int i = 0 ; i < 4 ; ++i){
			FCD_pad[i] = new TH1F(Form("pad_q%d",i+1), Form("pad_q%d",i+1), 4096, 0, 4096);
		}
		gDirectory->cd("/");

		TDirectory *quad_1_dir = outfile->mkdir("quad1");
		quad_1_dir->cd();
		for (int i = 0 ; i < 16 ; ++i){
			de_e_quad[0][i] = new TH2F(Form("de_e_q1_s%d",i+1), Form("de_e_q1_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad[0][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad[0][i]->GetYaxis()->SetTitle("dE energy [ch]");
			de_e_quad_gate[0][i] = new TH2F(Form("de_e_q1_gate_s%d",i+1), Form("de_e_q1_gate_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad_gate[0][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad_gate[0][i]->GetYaxis()->SetTitle("dE energy [ch]");
		}
		gDirectory->cd("/");

		TDirectory *quad_2_dir = outfile->mkdir("quad2");
		quad_2_dir->cd();
		for (int i = 0 ; i < 16 ; ++i){
			de_e_quad[1][i] = new TH2F(Form("de_e_q2_s%d",i+1), Form("de_e_q2_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad[1][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad[1][i]->GetYaxis()->SetTitle("dE energy [ch]");
			de_e_quad_gate[1][i] = new TH2F(Form("de_e_q2_gate_s%d",i+1), Form("de_e_q2_gate_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad_gate[1][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad_gate[1][i]->GetYaxis()->SetTitle("dE energy [ch]");
		}
		gDirectory->cd("/");

		TDirectory *quad_3_dir = outfile->mkdir("quad3");
		quad_3_dir->cd();
		for (int i = 0 ; i < 16 ; ++i){
			de_e_quad[2][i] = new TH2F(Form("de_e_q3_s%d",i+1), Form("de_e_q3_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad[2][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad[2][i]->GetYaxis()->SetTitle("dE energy [ch]");
			de_e_quad_gate[2][i] = new TH2F(Form("de_e_q3_gate_s%d",i+1), Form("de_e_q3_gate_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad_gate[2][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad_gate[2][i]->GetYaxis()->SetTitle("dE energy [ch]");
		}
		gDirectory->cd("/");

		TDirectory *quad_4_dir = outfile->mkdir("quad4");
		quad_4_dir->cd();
		for (int i = 0 ; i < 16 ; ++i){
			de_e_quad[3][i] = new TH2F(Form("de_e_q4_s%d",i+1), Form("de_e_q4_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad[3][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad[3][i]->GetYaxis()->SetTitle("dE energy [ch]");
			de_e_quad_gate[3][i] = new TH2F(Form("de_e_q4_gate_s%d",i+1), Form("de_e_q4_gate_s%d",i+1), 2000, 0, 30000, 2000, 0, 10000);
			de_e_quad_gate[3][i]->GetXaxis()->SetTitle("E energy [ch]");
			de_e_quad_gate[3][i]->GetYaxis()->SetTitle("dE energy [ch]");
		}
		gDirectory->cd("/");
	}//muxed

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
			else if( Singles ) g_clx->Fill();

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
			cd_ringtime1[j].clear();
			cd_ringtime2[j].clear();
			cd_pad[j].clear();

		}

		Quad.clear();
		Chan_front.clear();
		Ener_front.clear();
		Chan_back.clear();
		Ener_back.clear();
		time.clear();
		laser.clear();

		dgf_si_module.clear();
		dgf_si_channel.clear();
		dgf_si_time.clear();

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

		// Only Gammas and electrons
		for( j = 0; j < event->NumberOfDgfs(); j++ ) {

			dgf_num = event->Dgf(j)->ModuleNumber();
			dgf_ch  = event->Dgf(j)->Channel();
			dgf_en  = event->Dgf(j)->Energy();
			dgf_t   = event->Dgf(j)->Time();

			if( 6 <= dgf_num && dgf_num < 48 && 0 <= dgf_ch && dgf_ch < 4 ) { // miniball

				GammaEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );

				if( dgf_num % 2 == 0 && dgf_ch < 3 ) { // cores plus seg1 and seg2

					E_gam_seg[dgf_num/6][dgf_num%6/2][dgf_ch]->Fill( GammaEnergy );
					if( dgf_ch == 0 ) E_gam->Fill( GammaEnergy );

				} // even DGF number

				else {

					E_gam_seg[dgf_num/6][dgf_num%6/2][dgf_ch+3]->Fill( GammaEnergy );

				} // odd DGF number

			}

			if( 0 <= dgf_num && dgf_num < 6 && 0 <= dgf_ch && dgf_ch < 4 ) { // spede

				ElectronEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );

				//E_spede_seg[dgf_num*4+dgf_ch]->Fill( ElectronEnergy );

			}

			else if( dgf_num == 53 && dgf_ch == 0 ) {

				GammaEnergy = Cal->DgfEnergy( dgf_num, dgf_ch, dgf_en );
				E_BeamDump->Fill(Cal->DgfEnergy(53,0,dgf_en));
				T_BeamDump->Fill((dgf_t)/40000000);

			}

		}

		// Only Particles (and SPEDE if it is in ADC5)
		for( j = 0; j < event->NumberOfAdcs(); j++ ) {

			adc_num = event->Adc(j)->ModuleNumber();
			//cout << "adc_num " << adc_num << " test \n";
			for( k = 0; k < event->Adc(j)->SubEvent()->Size(); k++ ) {

				adc_ch = event->Adc(j)->SubEvent()->AdcChannel(k);
				adc_en = event->Adc(j)->SubEvent()->AdcValue(k);
				adc_t  = event->Adc(j)->Time();

				//cout << "K " << K << adc_ch << " " << adc_en << " " << adc_t << "\n";

				//Adding another option for CD being muxed
				if (muxed)
				{
					//cout << "adc chan " << adc_ch << "\n";
					if( 0 <= adc_num && adc_num < 4 ) { // CD
						if (adc_ch == RingEn1Chan){// FCD Ring Energy
								cd_ringenergyhit1[adc_num].push_back(adc_en);
								cd_ringtime1[adc_num].push_back(adc_t);
						} else if (adc_ch == RingEn2Chan) {// BCD Ring Energy
								cd_ringenergyhit2[adc_num].push_back(adc_en);
								cd_ringtime2[adc_num].push_back(adc_t);
						} else if (adc_ch == RingPos1Chan) {// FCD Ring ID
								cd_ringidhit1[adc_num].push_back(adc_en);
						} else if (adc_ch == RingPos2Chan) {// BCD Ring ID
								cd_ringidhit2[adc_num].push_back(adc_en);
						} else if (adc_ch == StripEn1Chan) {// FCD Strip Energy
								cd_stripenergyhit1[adc_num].push_back(adc_en);
						} else if (adc_ch == StripEn2Chan) {//BCD Strip Energy
								cd_stripenergyhit2[adc_num].push_back(adc_en);
						} else if (adc_ch == StripPos1Chan) {//FCD Strip ID
								cd_stripidhit1[adc_num].push_back(adc_en);
						} else if (adc_ch == StripPos2Chan) {//BCD Strip ID
								cd_stripidhit2[adc_num].push_back(adc_en);
						} else if (adc_ch == CDPadChan){// PAD
								cd_pad[adc_num].push_back(adc_en);//probably not needed now
						}
						//cout << cd_ringenergyhit1[adc_num].size() << " " << cd_ringidhit1[adc_num].size() << "\n";;
						//if (cd_ringenergyhit1[adc_num].size() > 1) cout << cd_ringenergyhit1[adc_num].size() << " " << cd_ringidhit1[adc_num].size() << "\n";
						if (cd_ringenergyhit1[adc_num].size() > 0 &&
								cd_ringidhit1[adc_num].size() > 0 &&
								cd_ringtime1[adc_num].size() > 0 &&
								cd_ringenergyhit1[adc_num].size() == cd_ringidhit1[adc_num].size() == cd_ringtime1[adc_num].size() )
						{
							if( tempRingEnergy < cd_ringenergyhit1[adc_num].back() )// is this energy higher than the last one
							{
								//cout << tempRingEnergy << " " << cd_ringenergyhit1[adc_num].back() << "\n";
								tempRingEnergy = cd_ringenergyhit1[adc_num].back();
								int ringID = Cal->PosFBCDRing(adc_num, cd_ringidhit1[adc_num].back());
								//cout << ringID << "\n";
								tempRingNum = ringID;
								tempRingTime = cd_ringtime1[adc_num].back();
								//cout << "time " << tempRingTime <<"\n";
							}
						}
						if (cd_stripenergyhit1[adc_num].size() > 0 &&
								cd_stripidhit1[adc_num].size() > 0 &&
								cd_stripenergyhit1[adc_num].size() == cd_stripidhit1[adc_num].size()  )
						{
							if( tempRingEnergy < cd_stripenergyhit1[adc_num].back() )// is this energy higher than the last one
							{
								tempStripEnergy = cd_stripenergyhit1[adc_num].back();
								int sectorID = Cal->PosFBCDStrip(adc_num, cd_ringidhit1[adc_num].back());
								tempStripNum = sectorID;
								//tempStripTime = cd_striptime1[adc_num].back();
								//cout << tempStripTime <<"\n";
							}
						}
					}
				} // muxed
				else// not muxed
				{
					if( 0 <= adc_num && adc_num < 4 ) { // CD

						if( adc_ch < 16 ) {

							cd_ringenergyhit1[adc_num].push_back(adc_en);
							cd_ringidhit1[adc_num].push_back(adc_ch);

							if( tempRingEnergy < adc_en )
							{
								tempRingEnergy = adc_en;
								tempRingNum = adc_ch;
							}

						}

						else if( adc_ch < 32 ) {

							cd_stripenergyhit1[adc_num].push_back(adc_en);
							cd_stripidhit1[adc_num].push_back(adc_ch);

							if( tempStripEnergy < adc_en )
							{
								tempStripEnergy = adc_en;
								tempStripNum = adc_ch;
							}

						}

					} // particle in CD
				} // not muxed
				//else if( adc_num == 4 )
				if( adc_num == 4 )
				{ // SPEDE

					ElectronEnergy = Cal->AdcEnergy( 4, adc_ch, adc_en );

					//STM-16 one
					if( adc_ch < 12 ) {

						E_spede_seg[adc_ch]->Fill( ElectronEnergy );					
						E_spede->Fill( ElectronEnergy );		

					}

					//STM-16 two
					else if( adc_ch > 15 && adc_ch < 28 ) {

						E_spede_seg[adc_ch-4]->Fill( ElectronEnergy );					
						E_spede->Fill( ElectronEnergy );			

					}

				} // SPEDE

			} // k
			if (muxed)
			{
				for (int j = 0 ; j < 4 ; ++j){
					for (int k = 0 ; k < cd_pad[j].size() ; ++k)
						FCD_pad[j]->Fill(cd_pad[j][k]);
				}
				for(int j = 0; j < 4; j++ ) {
					for(int k = 0; k < cd_ringenergyhit1[j].size(); k++ ){
						FBCD_Rings_id_energy_hit1[j]->Fill(cd_ringidhit1[j][k], cd_ringenergyhit1[j][k]);
						int ringID = Cal->PosFBCDRing(j, cd_ringidhit1[j][k]);
						if (ringID < 16)
							FCD_Rings[j][ringID]->Fill(cd_ringenergyhit1[j][k]);
					}
					for(int k = 0; k < cd_ringenergyhit2[j].size(); k++ ){
						FBCD_Rings_id_energy_hit2[j]->Fill(cd_ringidhit2[j][k], cd_ringenergyhit2[j][k]);
					}		  
					for(int k = 0; k < cd_stripenergyhit1[j].size(); k++ ){
						FBCD_Strips_id_energy_hit1[j]->Fill(cd_stripidhit1[j][k], cd_stripenergyhit1[j][k]);
						int sectorID = Cal->PosFBCDStrip(j, cd_ringidhit1[j][k]);
						if (sectorID < 16)
							FCD_Strips[j][sectorID]->Fill(cd_ringenergyhit1[j][k]);
					}
					for(int k = 0; k < cd_stripenergyhit2[j].size(); k++ ){
						FBCD_Strips_id_energy_hit2[j]->Fill(cd_stripidhit2[j][k], cd_stripenergyhit2[j][k]);
					}
				}
			}// muxed

			// Use only the highest energy hit - no reconstruction
			//cout << tempRingEnergy << " " << tempStripEnergy << " " << adc_num << "\n";
			if( tempRingEnergy > Threshold_CDRing_E[adc_num] &&
					tempStripEnergy > Threshold_CDStrip_E[adc_num] &&
					adc_num >= 0 && adc_num < 4 ) {

				Quad.push_back( adc_num );
				Chan_front.push_back( tempRingNum );
				Ener_front.push_back( Cal->AdcEnergy( adc_num, tempRingNum, tempRingEnergy ) );
				Chan_back.push_back( tempStripNum-16 );
				Ener_back.push_back( tempStripEnergy );

				if (muxed) time.push_back( tempRingTime );
				else time.push_back(event->Adc(j)->Time() + dtAdc[adc_num]);
				laser.push_back(event->Adc(j)->LaserOn());

				CounterAdcCDFired[adc_num]++;

			}

		} // j - numberofadcs

		for( j = 0; j < 4; j++ ) {
			if (muxed)
			{
				for( k = 0; k < cd_ringenergyhit1[j].size(); k++ )
				{
					int ringID = Cal->PosFBCDRing(j, cd_ringidhit1[j][k]);
					CD_front_energy[j]->Fill( ringID, cd_ringenergyhit1[j][k] );
				}

				for( k = 0; k < cd_stripenergyhit1[j].size(); k++ )
				{
					int sectorID = Cal->PosFBCDStrip(j, cd_ringidhit1[j][k]);
					CD_back_energy[j]->Fill( sectorID, cd_stripenergyhit1[j][k] );
				}
			}
			else
			{
				for( k = 0; k < cd_ringenergyhit1[j].size(); k++ )
				{
					//cout << "filling with " << cd_ringidhit1[j][k] << " " << cd_ringenergyhit1[j][k] << "\n";
					CD_front_energy[j]->Fill( cd_ringidhit1[j][k], cd_ringenergyhit1[j][k] );
				}

				for( k = 0; k < cd_stripenergyhit1[j].size(); k++ )
					CD_back_energy[j]->Fill( cd_stripidhit1[j][k]-16, cd_stripenergyhit1[j][k] );
			}
		} // j

		// Gamma-particle coincidences
		for( j = 0; j < event->NumberOfDgfs(); j++ ) {

			dgf_num = event->Dgf(j)->ModuleNumber();
			dgf_ch  = event->Dgf(j)->Channel();
			dgf_en  = event->Dgf(j)->Energy();
			dgf_t   = event->Dgf(j)->Time();		

			// Look for a core event
			if( 6 <= dgf_num && dgf_num < 48 && dgf_ch == 0 && dgf_num % 2 == 0 ) { // miniball

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

				// Do particles
				for( k = 0; k < Ener_front.size(); k++ ) {

					tdiffPG = time[k] - dgf_t;

					if( tMinRandom <= tdiffPG && tdiffPG <= tMaxRandom ) coinc_flag = 1;
					else if( tMinPrompt <= tdiffPG && tdiffPG <= tMaxPrompt ) coinc_flag = 0;
					else coinc_flag = -1;

					tdiff_gp->Fill( tdiffPG );

					// Add particle
					mb_evts[GammaCtr]->SetPart( Ener_front[k], (int)Chan_front[k], (int)Chan_back[k], tdiffPG,
							(double)event->SuperCycleTime()/1000000, (double)tdiffPG, (int)coinc_flag, Quad[k], (int)laser[k], PartCtr );

					PartCtr++;

				} // End loop All the particles

				// Look for correlated gammas
				for( l = 0; l < event->NumberOfDgfs(); l++ ) {

					// skip if it's the same event as before
					if( l == j ) continue;

					dgf_num3 = event->Dgf(l)->ModuleNumber();
					dgf_ch3  = event->Dgf(l)->Channel();
					dgf_en3  = event->Dgf(l)->Energy();
					dgf_t3   = event->Dgf(l)->Time();

					// skip if it's the same core as before
					if( dgf_num3 == dgf_num ) continue;

					// Look for a core event
					if( 6 <= dgf_num3 && dgf_num3 < 48 && dgf_ch3 == 0 && dgf_num3 % 2 == 0 ) { // miniball

						GammaEnergy3 = Cal->DgfEnergy( dgf_num3, dgf_ch3, dgf_en3 );
						MaxSegClu2 = dgf_num3 / 6;
						MaxSegCore2 = dgf_num3 % 6 / 2;

						// Check for highest energy segment in same detector
						for( k = 0; k < event->NumberOfDgfs(); k++ ) {

							dgf_num4 = event->Dgf(k)->ModuleNumber();
							dgf_ch4  = event->Dgf(k)->Channel();
							dgf_en4  = event->Dgf(k)->Energy();
							dgf_t4   = event->Dgf(k)->Time();

							// We don't care if it's the same event
							if( k == l ) continue;

							// Skip if a different detector
							if( dgf_num4 != dgf_num3 && dgf_num4 != dgf_num3 + 1 ) continue;

							GammaEnergy4 = Cal->DgfEnergy( dgf_num4, dgf_ch4, dgf_en4 );

							// Test maximum energy segment
							if( GammaEnergy4 < MaxSegEnergy2 ) continue;

							// Reassign energy and id
							MaxSegEnergy2 = GammaEnergy4;
							if( dgf_num4 % 2 == 0 ) MaxSegId2 = dgf_ch4 - 1;
							else MaxSegId2 = dgf_ch4+3 - 1;

						} // k

						// Found highest energy segment
						mb_evts[GammaCtr]->SetCorGamGen( GammaEnergy3 );
						mb_evts[GammaCtr]->SetCorGamCluid( MaxSegClu2 );
						mb_evts[GammaCtr]->SetCorGamCid( MaxSegClu2*3 + MaxSegCore2 );
						mb_evts[GammaCtr]->SetCorGamSid( MaxSegId2 );
						mb_evts[GammaCtr]->SetCorGamGtd( dgf_t3 - dgf_t );
						mb_evts[GammaCtr]->SetCorGamTheta( 0. );
						mb_evts[GammaCtr]->SetCorGamPhi( 0. );

					} // real event in the core? 2nd gamma

					// Reset
					MaxSegEnergy2 = -99.;
					MaxSegClu2 = -1;
					MaxSegCore2 = -1;
					MaxSegId2 = -1;

				} // End search for correlated gammas

				// Search for correlated electrons
				for( l = 0; l < event->NumberOfAdcs(); l++ ) {

					for( k = 0; k < event->Adc(l)->SubEvent()->Size(); k++ ) {

						if( event->Adc(l)->ModuleNumber() == 4 ) { // spede

							adc_ch  = event->Adc(l)->SubEvent()->AdcChannel(k);
							adc_en  = event->Adc(l)->SubEvent()->AdcValue(k) ;
							adc_t   = event->Adc(l)->Time();

							ElectronEnergy = Cal->AdcEnergy( 4, adc_ch, adc_en );

							if( ElectronEnergy < 5.0 || adc_en <= 1 ) continue;

							mb_evts[GammaCtr]->SetCorGamGen( ElectronEnergy );
							mb_evts[GammaCtr]->SetCorGamCluid( 8 );
							mb_evts[GammaCtr]->SetCorGamCid( 0 );
							mb_evts[GammaCtr]->SetCorGamSid( adc_ch );
							mb_evts[GammaCtr]->SetCorGamGtd( adc_t - dgf_t );
							mb_evts[GammaCtr]->SetCorGamTheta( 0. );
							mb_evts[GammaCtr]->SetCorGamPhi( 0. );

						} // spede

					} // k

				} // End search for correlated electrons

				// Count the gamma!
				GammaCtr++;

			} // real event in the core? first gamma

			// Reset
			MaxSegEnergy = -99.;
			MaxSegClu = -1;
			MaxSegCore = -1;
			MaxSegId = -1;
			PartCtr = 0;

		} // j

		// Electron-particle coincidences
		for( j = 0; j < event->NumberOfAdcs(); j++ ) {

			for( k = 0; k < event->Adc(j)->SubEvent()->Size(); k++ ) {

				if( event->Adc(j)->ModuleNumber() == 4 ) { // spede

					adc_ch  = event->Adc(j)->SubEvent()->AdcChannel(k);
					adc_en  = event->Adc(j)->SubEvent()->AdcValue(k) ;
					adc_t   = event->Adc(j)->Time();

					ElectronEnergy = Cal->AdcEnergy( 4, adc_ch, adc_en );

					mb_evts[GammaCtr]->SetGen( ElectronEnergy );
					mb_evts[GammaCtr]->SetCluid( 8 );
					mb_evts[GammaCtr]->SetCid( 0 );
					mb_evts[GammaCtr]->SetSid( adc_ch );

					// Do particles
					for( l = 0; l < Ener_front.size(); l++ ) {

						tdiffPG = time[l] - adc_t;

						if( tMinRandomElectron <= tdiffPG && tdiffPG <= tMaxRandomElectron ) coinc_flag = 1;
						else if( tMinPromptElectron <= tdiffPG && tdiffPG <= tMaxPromptElectron ) coinc_flag = 0;
						else coinc_flag = -1;			

						tdiff_ep->Fill( tdiffPG );

						// Add particle
						mb_evts[GammaCtr]->SetPart( Ener_front[l], (int)Chan_front[l], (int)Chan_back[l], tdiffPG,
								(double)event->SuperCycleTime()/1000000, (double)tdiffPG, (int)coinc_flag, Quad[l], (int)laser[l], PartCtr );
						PartCtr++;
					} // End loop All the particles
					// Count the electron!
					GammaCtr++;
				} // is it in the spede madc?
				// Reset
				PartCtr = 0;
				tempStripNum = 0;
				tempRingNum = 0;
				tempStripEnergy = 0;
				tempRingEnergy = 0;
				tempStripTime = 0;
				tempRingTime = 0;

			} // j
		} // k
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

