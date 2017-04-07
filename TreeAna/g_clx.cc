// Sorting for 220Rn and building histograms
// Cuts are done in doppler.hh using function, doppler::Cut()
// Liam Gaffney (liam.gaffney@cern.ch) - 26/10/2016

#define g_clx_cxx

// Experimental definitions
#ifndef ExpDefs_hh
# include "ExpDefs.hh"
#endif

// Select settings by uncommenting one of the following: 
# define CLUSTER 4

//#define CALIB			// define for plotting core seperately
//#define TWOPART 		// define to plot every 2p combination
//#define PHICAL  		// define to plot different CD rotation offsets
//#define GEANG			// define for plotting Ge angles per cluster
#define TDIFF  			// define to plot various tdiff spectra
#define MBGEOMETRY  		// define to overwrite MB angles with MBGeometry routine
#define SPEDEGEOMETRY	// define to overwrite Spede angles with SpedeGeometry routine
//#define CDCALIB			// define to plot clusters change from cd distance
//#define DISTCALIB			// define to plot clusters change from cluster distance
//#define ALPHACALIB			// define to plot clusters change from cluster rotation
//#define SPEDECALIB

#ifdef PHICAL
# define PHI_STEP_WIDTH 0.01 
# define PHI_NSTEPS 551 // try to use an odd number
#endif

#ifdef CALIB
//# define GE_THETA_STEP_WIDTH 1
//# define GE_THETA_NSTEPS 91
//# define GE_PHI_STEP_WIDTH 1
//# define GE_PHI_NSTEPS 91
# define GE_THETA_STEP_WIDTH 1 
# define GE_THETA_NSTEPS 91
# define GE_PHI_STEP_WIDTH 1
# define GE_PHI_NSTEPS 251
#endif

#ifdef CDCALIB
# define CD_DIST_NSTEPS 501
# define CD_DIST_WIDTH	0.05
#endif

#ifdef DISTCALIB
# define CLU_DIST_NSTEPS 501
# define CLU_DIST_WIDTH 0.1
#endif

#ifdef ALPHACALIB
# define CLU_ALPHA_NSTEPS 501 
# define CLU_ALPHA_WIDTH 0.1
//# define CLU_ALPHA_NSTEPS 800
//# define CLU_ALPHA_WIDTH 0.2
#endif

#ifdef SPEDECALIB
# define SPEDE_DIST_NSTEPS 149
# define SPEDE_DIST_WIDTH 0.1
# define SPEDE_ALPHA_NSTEPS 11
# define SPEDE_ALPHA_WIDTH 0.1
#endif

#ifndef __MBGEOMETRY_HH__
# include "MBGeometry.hh"
#endif
#ifndef __SpedeGeometry_HH__
# include "SpedeGeometry.hh"
#endif
#ifndef hist_cxx
# include "hists.hh"
#endif
#ifndef g_clx_hh
# include "g_clx.hh"
#endif

void g_clx::Loop( string outputfilename ) {

	if( fChain == 0 ) return;

	// Output file name	
	TFile *out = new TFile( outputfilename.c_str(), "RECREATE" );

	// Fit stopping power curves from the srim output files
	// Comment out to use the default parameters in doppler.hh
	if( !doppler::stoppingpowers( ZP, ZT, AP, AT, "BT" ) || // beam in target
			!doppler::stoppingpowers( ZP, ZT, AP, AT, "TT" ) || // target in target
			!doppler::stoppingpowers( ZP, ZT, AP, AT, "BS" ) || // beam in silicon
			!doppler::stoppingpowers( ZP, ZT, AP, AT, "TS" )	// target in silicon
	  ) return;

	// Ratio of prompt and random time windows
	// Alternatively, normalisation of beta-decay lines
	double bg_frac = -(14./20.);

	// Test if it's an electron of gamma
	bool electron;

	// Include errors on histograms (required for correct bg subtraction)
	TH1::SetDefaultSumw2();

	// Declare the histograms here and initialise!
	hists h;
	h.Initialise();

	// Particle-particle time difference (from tppdiff)
	h.Set_ppwin(300.);

	// Maximum strip number where recoils and projectiles are separable
	// Applicable mostly for inverse kinematics. To turn off, set to 16
	h.Set_maxrecoil(16);

	// Minimum strip number to define high CoM recoils
	// For normal kinematics, this is likely to be the limit of the safe condition
	// i.e. strips that are >= minrecoil are unsafe. Only low CoM solution is safe
	h.Set_minrecoil(0);

	// New angles defined by Miniball geometry
#ifdef MBGEOMETRY
	//double clu_r[8] = { 145.771, 131.83, 127.278, 131.695, 127.67, 131.695, 153.545, 130.104 };//This is a hack
	//double clu_theta[8] = { 142.823, 57.2478, 57.2478, 142.823, 145.884, 55.9527, 145.884, 55.9527 };//This is a hack
	//double clu_phi[8] = { 126.21, 52.8856, 132.529, 57.0067, 232.479, 222.16, 298.712, 228.893 };//This is a hack
	//double clu_alpha[8] = { 309.357, 127.278, 123.559, 118.29, 49.5007, 4.76191, 149.602, 350.352 };//This is a hack

	//double clu_r[8] = { 145.771, 131.83, 127.278, 131.695, 127.67, 131.695, 153.545, 130.104 };//This is a hack
	//double clu_theta[8] = { 0, 56.5, 44.5, 120, 91,51,0,80 };//This is a hack optimising for height
	//double clu_phi[8] = { 0, 64.3, 116.0, 55,88.5,229,0,300 };//This is a hack optimising for height
	//
	//double clu_theta[8] = { 0,160.,0,0,0,0,0,0 };//This is a hack
	//double clu_theta[8] = { 142.823, 57.2478, 57.2478, 118.000, 145.884, 55.9527, 145.884, 55.9527 };//This is a hack
	//                      back,    	 forward, forward, back,    back,    forward,   back,    forward

	double clu_r[8] = { 0,//1
		137.8,//2
		100,//3
		135,//4
		135,//5
		140,//6
		0,//7
		130.104 };//8
	
	double clu_theta[8] = { 0,//1
		68.3,//2 75
		65.9,//3
		90,//4
		107.5,//5
		66.5,//6
		0,//7
		70 };//8
	
	double clu_phi[8] = { 0,//1
		56.3,//2 55
		131.6,//3
		285,//4
		260,//5
		217,//6
		0,//6
		300 };//8

	double clu_alpha[8] = { 0,//1
		165,//2
		127,//3
		90,//4
		295,//5
		0,//6
		0,//7
		350.352 };//8

	//double clu_phi[8] = { 0,90.0,0,0,0,0,0,0 };//This is a hack
	//double clu_phi[8] = { 126.21, 52.8856, 132.529, 71.5, 232.479, 222.16, 298.712, 228.893 };//This is a hack
	//					  low r,  high r,  low r,   high r,  low l,   low l,  high l , high l
	/* clu[0] not there
	 *
	 */
	double new_theta[8][3][7];//cluster, crystal segment
	double new_phi[8][3][7];

	MBGeometry mbg;	
	for( int i = 0; i < 8; i++ ) { // loop over clusters

		mbg.SetupCluster( clu_theta[i], clu_phi[i], clu_alpha[i], clu_r[i] );

		for( int j = 0; j < 3; j++ ) { // loop over cores

			new_theta[i][j][0] = mbg.GetCoreTheta(j) * TMath::DegToRad();
			new_phi[i][j][0] = mbg.GetCorePhi(j) * TMath::DegToRad();
			//cout << new_phi[i][j][0]*TMath::RadToDeg() << " ";	
			for( int k = 0; k < 6; k++ ) { // loop over segments

				new_theta[i][j][k+1] = mbg.GetSegTheta(j,k) * TMath::DegToRad();
				new_phi[i][j][k+1] = mbg.GetSegPhi(j,k) * TMath::DegToRad();

			}

		}
		//cout << "\n";
		//double tempangle;
		//tempangle = 220;
		//cout << tempangle << " " << tempangle*TMath::DegToRad() << " " << tempangle*TMath::DegToRad()*TMath::RadToDeg() << "\n";
	}

#endif
	//Scanning variables
#ifdef CALIB
	double new_theta_scan[3][7][GE_THETA_NSTEPS];//crystal, segment, step
	double new_phi_scan[3][7][GE_PHI_NSTEPS];

	double scan_theta;
	double scan_phi;
	//set to input value
	scan_theta = clu_theta[CLUSTER-1];//degrees
	scan_phi = clu_phi[CLUSTER-1];//degrees
	//reduce by half steps * step width
	scan_theta -= (double)(int)((GE_THETA_NSTEPS-1)/2) * GE_THETA_STEP_WIDTH;//degrees
	scan_phi -= (double)(int)((GE_PHI_NSTEPS-1)/2) * GE_PHI_STEP_WIDTH;//degrees

	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout <<"flag\n";
	for( int j = 0; j < 3; j++ ) { // loop over cores
		for( int x = 0; x < GE_THETA_NSTEPS; x++ )
		{ // loop over theta steps
			for( int y = 0; y < GE_PHI_NSTEPS; y++ )
			{ // loop over phi steps
				MBGeometry mbg2;	
				mbg2.SetupCluster( scan_theta+(x*GE_THETA_STEP_WIDTH), scan_phi+(y*GE_PHI_STEP_WIDTH), clu_alpha[CLUSTER-1], clu_r[CLUSTER-1] );
				new_theta_scan[j][0][x] = mbg2.GetCoreTheta(j) * TMath::DegToRad();
				//new_theta_scan[j][0][x] = (x*0.01 +  mbg2.GetCoreTheta(j)) * TMath::DegToRad();
				new_phi_scan[j][0][y] = mbg2.GetCorePhi(j) * TMath::DegToRad();
				//cout << mbg2.GetCoreTheta(j);
				for( int k = 0; k < 6; k++ ) { // loop over segments
					new_theta_scan[j][k+1][x] = mbg2.GetSegTheta(j,k) * TMath::DegToRad();
					new_phi_scan[j][k+1][y] = mbg2.GetSegPhi(j,k) * TMath::DegToRad();

				}
			}
		}
	}
	scan_theta = clu_theta[CLUSTER-1];//degrees
	scan_theta -= (double)(int)((GE_THETA_NSTEPS-1)/2) * GE_THETA_STEP_WIDTH;//degrees

	scan_phi = clu_phi[CLUSTER-1];//degrees
	scan_phi -= (double)(int)((GE_PHI_NSTEPS-1)/2) * GE_PHI_STEP_WIDTH;//degrees

	cout << clu_theta[CLUSTER-1] << " ";
	for( int j = 0; j < 3; j++ ) cout << new_theta[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	cout << "	Initial\n";
	for( int x = 0; x < GE_THETA_NSTEPS; x++ )
	{
		//for( int y = 0; y < GE_PHI_NSTEPS; y++ )
		{
			cout << scan_theta+x*GE_THETA_STEP_WIDTH << " ";
			for( int j = 0; j < 3; j++ )
			{
				cout << new_theta_scan[j][0][x]*TMath::RadToDeg() << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";

	cout << clu_phi[CLUSTER-1] << " ";
	for( int j = 0; j < 3; j++ ) cout << new_phi[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	cout << "	Initial\n";
	for( int y = 0; y < GE_PHI_NSTEPS; y++ )
	{
		cout << scan_phi+y*GE_PHI_STEP_WIDTH << " ";
		for( int j = 0; j < 3; j++ )
		{
			cout << new_phi_scan[j][0][y]*TMath::RadToDeg() << " ";
		}
		cout << "\n";
	}
#endif
#ifdef DISTCALIB
	double new_theta_dist_scan[3][7][CLU_DIST_NSTEPS];
	double new_phi_dist_scan[3][7][CLU_DIST_NSTEPS];

	double scan_distance;
	//set to input value
	scan_distance = clu_r[CLUSTER-1];//degrees
	cout << scan_distance << "\n";
	//reduce by half steps * step width
	scan_distance -= (double)(int)((CLU_DIST_NSTEPS-1)/2) * CLU_DIST_WIDTH;//degrees
	//scan_distance = 0;

				cout << scan_distance << "\n";
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for( int j = 0; j < 3; j++ ) { // loop over cores
		for( int x = 0; x < CLU_DIST_NSTEPS; x++ )
		{ // loop over theta steps
				MBGeometry mbg3;	
				mbg3.SetupCluster( clu_theta[CLUSTER-1], clu_phi[CLUSTER-1], clu_alpha[CLUSTER-1], scan_distance+x*CLU_DIST_WIDTH);
				//cout << scan_distance+x*CLU_DIST_WIDTH << " ";
				new_theta_dist_scan[j][0][x] = mbg3.GetCoreTheta(j) * TMath::DegToRad();
				new_phi_dist_scan[j][0][x] = mbg3.GetCorePhi(j) * TMath::DegToRad();
				//cout << new_theta_dist_scan[j][0][x] * TMath::RadToDeg() << "\n";
				for( int k = 0; k < 6; k++ )
				{ // loop over segments
					new_theta_dist_scan[j][k+1][x] = mbg3.GetSegTheta(j,k) * TMath::DegToRad();
					new_phi_dist_scan[j][k+1][x] = mbg3.GetSegPhi(j,k) * TMath::DegToRad();
			}
		}
	}
	scan_distance = clu_r[CLUSTER-1];//degrees
	//scan_distance -= (double)(int)((CLU_DIST_NSTEPS-1)/2) * CLU_DIST_WIDTH;//degrees


	cout << clu_r[CLUSTER-1] << " ";
	for( int j = 0; j < 3; j++ ) cout << new_theta[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	for( int j = 0; j < 3; j++ ) cout << new_phi[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	cout << "	Initial\n";
	for( int x = 0; x < CLU_DIST_NSTEPS; x++ )
	{
			cout << scan_distance+x*CLU_DIST_WIDTH << " ";
			for( int j = 0; j < 3; j++ )
			{
				cout << new_theta_dist_scan[j][0][x]*TMath::RadToDeg() << " ";
			}
			for( int j = 0; j < 3; j++ )
			{
				cout << new_phi_dist_scan[j][0][x]*TMath::RadToDeg() << " ";
			}
			cout << "\n";
	}
	cout << "\n";
#endif
#ifdef ALPHACALIB
	double new_theta_alpha_scan[3][7][CLU_ALPHA_NSTEPS];
	double new_phi_alpha_scan[3][7][CLU_ALPHA_NSTEPS];

	//set to input value
	scan_alpha = clu_alpha[CLUSTER-1];//degrees
	cout << scan_alpha << "\n";
	//reduce by half steps * step width
	scan_alpha -= (double)(int)((CLU_ALPHA_NSTEPS-1)/2) * CLU_ALPHA_WIDTH;//degrees
	//scan_alpha = 0;

	cout << scan_alpha << "\n";
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for( int j = 0; j < 3; j++ ) { // loop over cores
		for( int x = 0; x < CLU_ALPHA_NSTEPS; x++ )
		{ // loop over theta steps
				MBGeometry mbg4;	
				mbg4.SetupCluster( clu_theta[CLUSTER-1], clu_phi[CLUSTER-1], scan_alpha+x*CLU_ALPHA_WIDTH, clu_r[CLUSTER-1]);
				//cout << scan_alphaance+x*CLU_ALPHA_WIDTH << " ";
				new_theta_alpha_scan[j][0][x] = mbg4.GetCoreTheta(j) * TMath::DegToRad();
				new_phi_alpha_scan[j][0][x] = mbg4.GetCorePhi(j) * TMath::DegToRad();
				//cout << new_theta_alpha_scan[j][0][x] * TMath::RadToDeg() << "\n";
				for( int k = 0; k < 6; k++ )
				{ // loop over segments
					new_theta_alpha_scan[j][k+1][x] = mbg4.GetSegTheta(j,k) * TMath::DegToRad();
					new_phi_alpha_scan[j][k+1][x] = mbg4.GetSegPhi(j,k) * TMath::DegToRad();
			}
		}
	}
	scan_alpha = clu_r[CLUSTER-1];//degrees
	//scan_alpha = 0;
	//scan_alphaance -= (double)(int)((CLU_DIST_NSTEPS-1)/2) * CLU_DIST_WIDTH;//degrees


	cout << clu_alpha[CLUSTER-1] << " ";
	for( int j = 0; j < 3; j++ ) cout << new_theta[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	for( int j = 0; j < 3; j++ ) cout << new_phi[CLUSTER-1][j][0]*TMath::RadToDeg() << " ";
	cout << "	Initial\n";
	for( int x = 0; x < CLU_ALPHA_NSTEPS; x++ )
	{
			cout << scan_alpha+x*CLU_ALPHA_WIDTH << " ";
			for( int j = 0; j < 3; j++ )
			{
				cout << new_theta_alpha_scan[j][0][x]*TMath::RadToDeg() << " ";
			}
			for( int j = 0; j < 3; j++ )
			{
				cout << new_phi_alpha_scan[j][0][x]*TMath::RadToDeg() << " ";
			}
			cout << "\n";
	}
	cout << "\n";
#endif

	// New angles defined by Spede geometry
#ifdef SPEDEGEOMETRY
	double spede_r = SPEDEDIST;
	double spede_alpha = 0.0;

	double spede_theta[24];
	double spede_phi[24];

	SpedeGeometry spg;	
	spg.SetupSpede( spede_r, spede_alpha );
	for( int j = 0; j < 24; j++ ) { // loop over segments

		spede_theta[j] = spg.GetSpedeTheta(j) * TMath::DegToRad();
		spede_phi[j] = spg.GetSpedePhi(j) * TMath::DegToRad();
	}

#endif
#ifdef SPEDECALIB
	double spede_theta_dist_scan[24][SPEDE_DIST_NSTEPS];
	double spede_phi_dist_scan[24][SPEDE_DIST_NSTEPS];

	double spede_theta_alpha_scan[24][SPEDE_ALPHA_NSTEPS];
	double spede_phi_alpha_scan[24][SPEDE_ALPHA_NSTEPS];

	double scan_dist = spede_r;
	//scan_dist -= (double)(int)((SPEDE_DIST_NSTEPS-1)/2) * SPEDE_DIST_WIDTH;
	scan_dist = 0;

	scan_alpha = spede_alpha;
	scan_alpha -= (double)(int)((SPEDE_ALPHA_NSTEPS-1)/2) * SPEDE_ALPHA_WIDTH;
	scan_alpha = 0;

	for( int j = 0; j < 24; j++ ) { // loop over segments
		//cout << "theta " << spede_theta[j] << " phi " << spede_phi[j] << "\n";
		for ( int k = 0; k < SPEDE_DIST_NSTEPS; k++ ) { // loop over steps
			spg.SetupSpede( scan_dist+k*SPEDE_DIST_WIDTH, spede_alpha );

			spede_theta_dist_scan[j][k] = spg.GetSpedeTheta(j) * TMath::DegToRad();
			spede_phi_dist_scan[j][k] = spg.GetSpedePhi(j) * TMath::DegToRad();
			//cout  << " dist theta " << spede_theta_dist_scan[j][k] << " phi " << spede_phi_dist_scan[j][k] << "\n";
		}

		//cin.get();
		for ( int k = 0; k < SPEDE_ALPHA_NSTEPS; k++ ) { // loop over steps
			//spg.SetupSpede( spede_r, scan_alpha+k*SPEDE_ALPHA_WIDTH);
			spg.SetupSpede( spede_r, spede_alpha);

			spede_theta_alpha_scan[j][k] = spg.GetSpedeTheta(j) * TMath::DegToRad();
			spede_phi_alpha_scan[j][k] = spg.GetSpedePhi(j) * TMath::DegToRad();
			//cout << spg.GetSpedeTheta(j)* TMath::DegToRad() << " " << spg.GetSpedePhi(j)* TMath::DegToRad() << "\n";
			//cout << "alpha theta " << spede_theta_alpha_scan[j][SPEDE_ALPHA_NSTEPS] << " phi " << spede_phi_alpha_scan[j][SPEDE_ALPHA_NSTEPS] << "\n";
		}
		//cout << "Press any key...\n";

	}

//cin.get();
#endif

	float rad, phi; // for cdpic

	// Loop over events 
	cout << "Looping over events...\n";
	Int_t nbytes = 0, nb = 0;
	Int_t skipFactor =1;
	for( Long64_t jentry=0; jentry<fChain->GetEntries()/skipFactor; jentry++ ) {	

		Long64_t ientry = LoadTree(jentry);

		if( ientry < 0 ) break;

		nb = fChain->GetEntry(jentry);   nbytes += nb;

		if( jentry%5000==0 ){
			cout << " " << jentry << "/" << fChain->GetEntries() << "  (" << jentry*100./fChain->GetEntries() << "%)    \r";
			cout << flush;
		}

		// Is it an electron or gamma?
		if( cluid < 8 ) electron = false;
		else if( cluid == 8 ) electron = true;
		else break; // shouldn't be anything else

		// Overwrite angles from tree with new angles
#ifdef MBGEOMETRY
		if( !electron ) { // check if it's Miniball
			tha = new_theta[cluid][cid%3][sid+1];
			pha = new_phi[cluid][cid%3][sid+1];
		}
		
		for( int i = 0; i < gcor_gen.size(); i++ ){
		
			if( gcor_cluid[i] == 8 || gcor_sid[i] < 0 ) continue; // not Ge
			gcor_tha[i] = new_theta[gcor_cluid[i]][gcor_cid[i]%3][gcor_sid[i]+1];	// gcor_sid broken!
			gcor_pha[i] = new_phi[gcor_cluid[i]][gcor_cid[i]%3][gcor_sid[i]+1];		// gcor_sid broken!
			
		}
#endif
#ifdef SPEDEGEOMETRY
		if( electron ) { // check if it's SPEDE
			tha = spede_theta[sid];
			pha = spede_phi[sid];
		}

		for( int i = 0; i < gcor_gen.size(); i++ ){
			
			if( gcor_cluid[i] != 8 || gcor_sid[i] < 0 || gcor_sid[i] > 23 ) continue; // not spede
			gcor_tha[i] = spede_theta[gcor_sid[i]];		// gcor_sid broken!
			gcor_pha[i] = spede_phi[gcor_sid[i]];		// gcor_sid broken!
			
		}
#endif


		// Escape if angles are strange
		//if( gen >= 0 && ( tha < 0.0005 || pha < 0.0005 ) && !electron ){
		//	h.GeReject->Fill( cluid );
		//	continue;
		//}
		//h.GePass->Fill(cluid);

		// Paricle multiplicity
		if( pr_hits != 0 ) h.multp->Fill( pr_hits );
		else h.multr->Fill( rndm_hits );

		// Germanium angles
		if( !electron ) { // check if it's Miniball

			h.GeAng->Fill(tha*TMath::RadToDeg(),pha*TMath::RadToDeg());
#ifdef GEANG
			h.GeAng_clu[cluid]->Fill(tha*TMath::RadToDeg(),pha*TMath::RadToDeg());
#endif
		}

		// Loop over particle counter
		for( int i=0; i<ctr; i++ ){

			// Escape funny events if there are any
			if( det[i]<0 || det[i]>3 || ann[i]<0 || sec[i]<0 ) continue;

			// Fill particle-gamma time spectra
			if( !electron ) {
				h.tdiff->Fill(td[i]*25.);
#ifdef TDIFF
				h.tdiffQ[det[i]]->Fill(td[i]*25.);
				for( int k=0; k<4; k++ )
					if( gen>h.tegate[k]-20 && gen<h.tegate[k]+20 )
						h.tdiffE[k]->Fill(td[i]*25.);

				// particle - particle time difference
				for( int j=i+1; j<ctr; j++ ) {
					h.tpp->Fill(td[i]*25.,td[j]*25.);
					h.tppdiff->Fill((td[i]-td[j])*25.);
					for( int k=0; k<2; k++ ){
						if( (det[i]==k && det[j]==k+2) || (det[j]==k && det[i]==k+2) ) {
							if( det[i]>det[j] ) h.tQQ[k]->Fill((td[j]-td[i])*25.);
							else h.tQQ[k]->Fill((td[i]-td[j])*25.);
						}
					}
				}
#endif
			} // cluid < 8
			else h.tdiff_e->Fill(td[i]*25.);

			// CD pic
			if( ann[i]>(-1) && ctr>0 ){
				rad=39-2*ann[i];
				rad+=gRandom->Rndm(1)*1.9;
				phi=(sec[i]-16.)*0.12+(det[i]*TMath::PiOver2());
				phi+=gRandom->Rndm(1)*0.114;
				if( sec[i]<29 && sec[i]>15 ) h.cdpic->Fill(rad*cos(phi),rad*sin(phi));
			}

			// Germanium angles vs. Silicon angles
			if( !electron ) {
#ifdef GEANG
				h.GeSiAng->Fill(tha*TMath::RadToDeg(),doppler::GetPTh(ann[i])*TMath::RadToDeg(),(pha-doppler::GetPPhi(det[i],sec[i]))*TMath::RadToDeg());
				h.GeSiAng_clu[cluid]->Fill(tha*TMath::RadToDeg(),doppler::GetPTh(ann[i])*TMath::RadToDeg(),(pha-doppler::GetPPhi(det[i],sec[i]))*TMath::RadToDeg());
#endif
#ifdef CALIB
				//if( doppler::Cut(pen[i],ann[i],det[i]) > 0 )//original
				if( doppler::Cut(pen[i],ann[i],det[i]) == 0 )
				{
					h.GeCalib_clu[cluid]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),tha,pha,AP));
					h.GeCalib_cid[cid]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),tha,pha,AP));

					for( int j = 0; j < GE_THETA_NSTEPS; j++ ) {
						for( int k = 0; k < GE_PHI_NSTEPS; k++ ) {
							if ( cluid >= CLUSTER-1 && cluid < CLUSTER)
								h.GeCalib_dcT[j][k]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),new_theta_scan[cid%3][sid+1][j],new_phi_scan[cid%3][sid+1][k],AT));
						}
					}

				}
#endif
#ifdef CDCALIB
				double scan_dist = CDDIST;
				//scan_dist -= (double)(int)((CD_DIST_NSTEPS-1)/2) * CD_DIST_WIDTH;//degrees
				scan_dist = 15;
				if( doppler::Cut(pen[i],ann[i],det[i]) == 0 )
				{
					for( int j = 0; j < CD_DIST_NSTEPS; j++ ) {
						h.GeCalib_clu_CD[cluid][j]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i],scan_dist+j*CD_DIST_WIDTH),doppler::GetPPhi(det[i],sec[i]),tha,pha,AP));
					}
				}
#endif

#ifdef DISTCALIB
				if( doppler::Cut(pen[i],ann[i],det[i]) == 0 )
				{
					for( int j = 0; j < CLU_DIST_NSTEPS; j++ ) {
							if ( cluid >= CLUSTER-1 && cluid < CLUSTER)
								h.GeCalib_clu_DIST[j]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),new_theta_dist_scan[cid%3][sid+1][j],new_phi_dist_scan[cid%3][sid+1][j],AT));
					}
				}
#endif
#ifdef ALPHACALIB
				if( doppler::Cut(pen[i],ann[i],det[i]) == 0 )
				{
					for( int j = 0; j < CLU_ALPHA_NSTEPS; j++ ) {
							if ( cluid >= CLUSTER-1 && cluid < CLUSTER)
								h.GeCalib_clu_ALPHA[j]->Fill(gen*doppler::DC(pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),new_theta_alpha_scan[cid%3][sid+1][j],new_phi_alpha_scan[cid%3][sid+1][j],AT));
					}
				}
#endif
			} // !electron
			
			else if( electron ) {
#ifdef SPEDECALIB
				if( doppler::Cut(pen[i],ann[i],det[i]) == 0 && sid < 24 )
				{
					h.sid_test->Fill(sid);
					h.sid_single_test[sid]->Fill(doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),tha,pha,AT));
					for( int j = 0; j < SPEDE_DIST_NSTEPS; j++ ) {
						h.SpedeCalib_dist[j]->Fill(doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_dist_scan[sid][j],spede_phi_dist_scan[sid][j],AT));
						h.SpedeCalib_dist_mat->Fill(j,doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_dist_scan[sid][j],spede_phi_dist_scan[sid][j],AT));
						//if (sid < 24) h.SpedeCalib_alpha[j]->Fill(doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_alpha_scan[sid][j],spede_phi_alpha_scan[sid][j],AT));
						//if (sid < 24) h.SpedeCalib_alpha_mat->Fill(j,doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_alpha_scan[sid][j],spede_phi_alpha_scan[sid][j],AT));
						//cout << "sid " << sid << " J " << j << " theta " << spede_theta_dist_scan[sid][j] <<  " phi " << spede_phi_dist_scan[sid][j] << "\n";
						//cout << "J " << j << " energy " << doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_dist_scan[sid][j],spede_phi_dist_scan[sid][j],AT) << "\n";
						h.sid_single_dist[sid]->Fill(j,doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_dist_scan[sid][j],spede_phi_dist_scan[sid][j],AT));
						h.sid_single_alpha[sid]->Fill(j,doppler::DC_elec(gen,pen[i],doppler::GetPTh(ann[i]),doppler::GetPPhi(det[i],sec[i]),spede_theta_alpha_scan[sid][j],spede_phi_alpha_scan[sid][j],AT));
						//else cout << sid << "\n";
						//cout << "theta " << tha << " phi " << pha << "\n";
						//cout << "j " << j << " sid " << sid << " energy " << gen << " theta " << spede_theta_dist_scan[sid][j] << " phi " << spede_phi_dist_scan[sid][j] << "\n";
					}
					
				}
#endif
			}

		} // END - Loop over particle counter

		// Check size of correlated gammas
		h.gcor_size->Fill( gcor_gen.size() );

		// Fill conditioned spectra

		// Condition on particle detection
		//if (cluid == 1)//TODO this is temporary
		{
			if( pr_hits==1 && rndm_hits==0 ) 
				h.Fill1h(gen, tha, pha, gcor_gen, gcor_tha, gcor_pha, gcor_cluid, gcor_gtd, electron,
						 pen[pr_ptr[0]], ann[pr_ptr[0]], sec[pr_ptr[0]], det[pr_ptr[0]], 1.0);

			else if( pr_hits==2 && rndm_hits==0 )
				h.Fill2h(gen, tha, pha, gcor_gen, gcor_tha, gcor_pha, gcor_cluid, gcor_gtd, electron,
						 pen, ann, sec, det, pr_ptr, td, 1.0);

			else if( rndm_hits==1 && pr_hits==0 ) 
				h.Fill1h(gen, tha, pha, gcor_gen, gcor_tha, gcor_pha, gcor_cluid, gcor_gtd, electron,
						 pen[rndm_ptr[0]], ann[rndm_ptr[0]], sec[rndm_ptr[0]], det[rndm_ptr[0]], bg_frac);

			else if( rndm_hits==2 && pr_hits==0 )			
				h.Fill2h(gen, tha, pha, gcor_gen, gcor_tha, gcor_pha, gcor_cluid, gcor_gtd, electron,
						 pen, ann, sec, det, rndm_ptr, td, bg_frac);
		}

	} // for (Long64_t jentry=0; jentry<fChain->GetEntries();jentry++)
	
#ifdef CALIB
	GammaEnergy = 278.;//strongest gamma ray
	//TF1 *gaus1 = new TF1("gaus","gaus",GammaEnergy-20,GammaEnergy+20);
	gaussian = new TF1("gaussian","gaus(0)",GammaEnergy-30,GammaEnergy+30);
	//gaussian->SetParameters(3,1);
	//gaussian->SetParNames("constant","mean","sigma");
	//TF1 *gaussianPlusBG = new TF1("gaussianPlusBG","gaussian+pol2(3)",GammaEnergy-20,GammaEnergy+20);
	gaussianPlusBG = new TF1("gaussianPlusBG","gaus(0)+pol2(3)",GammaEnergy-30,GammaEnergy+30);
	//gaussianPlusBG->SetParameters(3,1);
	gaussianPlusBG->SetParNames("constant","mean","sigma","const","linear","square");
	//for (int i=0; i<3; i++)
	{
		cout << setprecision(3)<< setw(5);
		//cout << "Fitting all of the things for crystal " << i << "...\n";
		//int i = 1;
		for (int j=0; j< GE_THETA_NSTEPS; j++)
		{
			for (int k=0; k< GE_PHI_NSTEPS; k++)
			{
				double MaxVal = h.GeCalib_dcT[j][k]->GetBinContent(h.GeCalib_dcT[j][k]->GetMaximumBin());//Counts in max bin
				double MaxBin = h.GeCalib_dcT[j][k]->GetBinCenter(h.GeCalib_dcT[j][k]->GetMaximumBin());//Centroid of max bin
				//gaus1->SetParameter(0,500);
				//gaus1->SetParameter(1,GammaEnergy);
				//gaus1->SetParameter(2,5);
				gaussianPlusBG->SetParameter(0,500);
				gaussianPlusBG->SetParameter(1,GammaEnergy);
				gaussianPlusBG->SetParLimits(1,GammaEnergy-15,GammaEnergy+15);
				gaussianPlusBG->SetParameter(2,5);
				gaussianPlusBG->SetParLimits(2,1,50);
				gaussianPlusBG->SetParameter(3,1);
				gaussianPlusBG->SetParameter(4,-1);
				gaussianPlusBG->SetParameter(5,0);
				gaussianPlusBG->SetParLimits(5,-10,1);
				//gaussianPlusBG->FixParameter(3,0);
				//gaussianPlusBG->FixParameter(4,0);
				gaussianPlusBG->FixParameter(5,0);

				h.GeCalib_dcT[j][k]->Fit(gaussianPlusBG,"QR");
				h.GeCalib_dcTMax->SetBinContent(j,k,h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)));
				h.GeCalib_dcTMaxE->SetBinContent(j,k,abs( GammaEnergy - gaussianPlusBG->GetParameter("mean")));
				h.GeCalib_dcTMaxSigma->SetBinContent(j,k,(gaussianPlusBG->GetParameter("sigma")));
				Double_t tempCounts = PeakMaxCounts[0];
				Double_t tempSigma = PeakSigma[0];
				//if (tempCounts < h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1))) PeakMaxCounts[0] = h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1));
				if (tempSigma < 1/gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = 1/gaussianPlusBG->GetParameter("sigma");
				if (1/gaussianPlusBG->GetParameter("sigma") < 0.95* PeakSigma[0]) delete h.GeCalib_dcT[j][k];
			}
		}
	}
	PeakSigma[0] = 0;
	cout << "Deleting the boring ones\n";
	{
		cout << "Start - Theta " << clu_theta[CLUSTER-1]
			<< "	Phi " << clu_phi[CLUSTER-1]
			<< "	cluster " << CLUSTER << "\n";

		for (int j=0; j< GE_THETA_NSTEPS; j++)
		{
			for (int k=0; k< GE_PHI_NSTEPS; k++)
			{

				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];
				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];

			}
		}
	}

#endif
#ifdef CDCALIB
	GammaEnergy = 278.;//strongest gamma ray
	//TF1 *gaus1 = new TF1("gaus","gaus",GammaEnergy-20,GammaEnergy+20);
	gaussian = new TF1("gaussian","gaus(0)",GammaEnergy-30,GammaEnergy+30);
	//gaussian->SetParameters(3,1);
	//gaussian->SetParNames("constant","mean","sigma");
	//TF1 *gaussianPlusBG = new TF1("gaussianPlusBG","gaussian+pol2(3)",GammaEnergy-20,GammaEnergy+20);
	gaussianPlusBG = new TF1("gaussianPlusBG","gaus(0)+pol2(3)",GammaEnergy-30,GammaEnergy+30);
	//gaussianPlusBG->SetParameters(3,1);
	gaussianPlusBG->SetParNames("constant","mean","sigma","const","linear","square");
	for (int i=0; i<8; i++)
	{
		cout << setprecision(3)<< setw(5);
		//cout << "Fitting all of the things for crystal " << i << "...\n";
		//int i = 1;
		for (int j=0; j< CD_DIST_NSTEPS; j++)
		{
				//gaus1->SetParameter(0,500);
				//gaus1->SetParameter(1,GammaEnergy);
				//gaus1->SetParameter(2,5);
				gaussianPlusBG->SetParameter(0,500);
				gaussianPlusBG->SetParameter(1,GammaEnergy);
				gaussianPlusBG->SetParLimits(1,GammaEnergy-5,GammaEnergy+5);
				gaussianPlusBG->SetParameter(2,5);
				gaussianPlusBG->SetParLimits(2,1,10);
				gaussianPlusBG->SetParameter(3,1);
				gaussianPlusBG->SetParameter(4,-1);
				gaussianPlusBG->SetParameter(5,0);
				gaussianPlusBG->SetParLimits(5,-10,1);
				//gaussianPlusBG->FixParameter(3,0);
				//gaussianPlusBG->FixParameter(4,0);
				gaussianPlusBG->FixParameter(5,0);

				h.GeCalib_clu_CD[i][j]->Fit(gaussianPlusBG,"QR");
				h.GeCalib_clu_CD_MaxSigma->SetBinContent(i,j,(gaussianPlusBG->GetParameter("sigma")));
				//if (tempSigma < gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = gaussianPlusBG->GetParameter("sigma");
				Double_t tempSigma = PeakSigma[0];
				if (tempSigma < 1/gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = 1/gaussianPlusBG->GetParameter("sigma");
				if (1/gaussianPlusBG->GetParameter("sigma") < 0.95* PeakSigma[0]) delete h.GeCalib_clu_CD[i][j];
			}
	}
	PeakSigma[0] = 0;
	cout << "Deleting the boring ones\n";
	{
		for (int j=0; j< CD_DIST_NSTEPS; j++)
		{

				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];
				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];

		}
	}

#endif

#ifdef DISTCALIB
	GammaEnergy = 278.;//strongest gamma ray
	//TF1 *gaus1 = new TF1("gaus","gaus",GammaEnergy-20,GammaEnergy+20);
	gaussian = new TF1("gaussian","gaus(0)",GammaEnergy-30,GammaEnergy+30);
	//gaussian->SetParameters(3,1);
	//gaussian->SetParNames("constant","mean","sigma");
	//TF1 *gaussianPlusBG = new TF1("gaussianPlusBG","gaussian+pol2(3)",GammaEnergy-20,GammaEnergy+20);
	gaussianPlusBG = new TF1("gaussianPlusBG","gaus(0)+pol2(3)",GammaEnergy-30,GammaEnergy+30);
	//gaussianPlusBG->SetParameters(3,1);
	gaussianPlusBG->SetParNames("constant","mean","sigma","const","linear","square");
	//for (int i=0; i<3; i++)
	{
		cout << setprecision(3)<< setw(5);
		//cout << "Fitting all of the things for crystal " << i << "...\n";
		//int i = 1;
		for (int j=0; j< CLU_DIST_NSTEPS; j++)
		{
				double MaxVal = h.GeCalib_clu_DIST[j]->GetBinContent(h.GeCalib_clu_DIST[j]->GetMaximumBin());//Counts in max bin
				double MaxBin = h.GeCalib_clu_DIST[j]->GetBinCenter(h.GeCalib_clu_DIST[j]->GetMaximumBin());//Centroid of max bin
				//gaus1->SetParameter(0,500);
				//gaus1->SetParameter(1,GammaEnergy);
				//gaus1->SetParameter(2,5);
				gaussianPlusBG->SetParameter(0,500);
				gaussianPlusBG->SetParameter(1,GammaEnergy);
				gaussianPlusBG->SetParLimits(1,GammaEnergy-5,GammaEnergy+5);
				gaussianPlusBG->SetParameter(2,5);
				gaussianPlusBG->SetParLimits(2,1,50);
				gaussianPlusBG->SetParameter(3,1);
				gaussianPlusBG->SetParameter(4,-1);
				gaussianPlusBG->SetParameter(5,0);
				gaussianPlusBG->SetParLimits(5,-10,1);
				//gaussianPlusBG->FixParameter(3,0);
				//gaussianPlusBG->FixParameter(4,0);
				gaussianPlusBG->FixParameter(5,0);

				h.GeCalib_clu_DIST[j]->Fit(gaussianPlusBG,"QR");
				h.GeCalib_clu_DIST_MaxSigma->SetBinContent(CLUSTER-1,j,(gaussianPlusBG->GetParameter("sigma")));
				//Double_t tempCounts = PeakMaxCounts[0];
				//Double_t tempSigma = PeakSigma[0];
				//if (tempCounts < h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1))) PeakMaxCounts[0] = h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1));
				//if (tempSigma < gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = gaussianPlusBG->GetParameter("sigma");
				Double_t tempSigma = PeakSigma[0];
				if (tempSigma < 1/gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = 1/gaussianPlusBG->GetParameter("sigma");
				if (1/gaussianPlusBG->GetParameter("sigma") < 0.95* PeakSigma[0]) delete h.GeCalib_clu_DIST[j];
			}
	}
	PeakSigma[0] = 0;
	//cout << "Deleting the boring ones\n";
	//{
	//	cout << "Start - Theta " << clu_theta[CLUSTER-1]
	//		<< "	Phi " << clu_phi[CLUSTER-1]
	//		<< "	cluster " << CLUSTER << "\n";

		//for (int j=0; j< GE_THETA_NSTEPS; j++)
		//{
		//	for (int k=0; k< GE_PHI_NSTEPS; k++)
		//	{

				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];
				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];

			//}
		//}
	//}

#endif
#ifdef ALPHACALIB
	GammaEnergy = 278.;//strongest gamma ray
	//TF1 *gaus1 = new TF1("gaus","gaus",GammaEnergy-20,GammaEnergy+20);
	gaussian = new TF1("gaussian","gaus(0)",GammaEnergy-30,GammaEnergy+30);
	//gaussian->SetParameters(3,1);
	//gaussian->SetParNames("constant","mean","sigma");
	//TF1 *gaussianPlusBG = new TF1("gaussianPlusBG","gaussian+pol2(3)",GammaEnergy-20,GammaEnergy+20);
	gaussianPlusBG = new TF1("gaussianPlusBG","gaus(0)+pol2(3)",GammaEnergy-30,GammaEnergy+30);
	//gaussianPlusBG->SetParameters(3,1);
	gaussianPlusBG->SetParNames("constant","mean","sigma","const","linear","square");
	//for (int i=0; i<3; i++)
	{
		cout << setprecision(3)<< setw(5);
		//cout << "Fitting all of the things for crystal " << i << "...\n";
		//int i = 1;
		for (int j=0; j< CLU_ALPHA_NSTEPS; j++)
		{
				double MaxVal = h.GeCalib_clu_ALPHA[j]->GetBinContent(h.GeCalib_clu_ALPHA[j]->GetMaximumBin());//Counts in max bin
				double MaxBin = h.GeCalib_clu_ALPHA[j]->GetBinCenter(h.GeCalib_clu_ALPHA[j]->GetMaximumBin());//Centroid of max bin
				//gaus1->SetParameter(0,500);
				//gaus1->SetParameter(1,GammaEnergy);
				//gaus1->SetParameter(2,5);
				gaussianPlusBG->SetParameter(0,500);
				gaussianPlusBG->SetParameter(1,GammaEnergy);
				gaussianPlusBG->SetParLimits(1,GammaEnergy-5,GammaEnergy+5);
				gaussianPlusBG->SetParameter(2,5);
				gaussianPlusBG->SetParLimits(2,1,50);
				gaussianPlusBG->SetParameter(3,1);
				gaussianPlusBG->SetParameter(4,-1);
				gaussianPlusBG->SetParameter(5,0);
				gaussianPlusBG->SetParLimits(5,-10,1);
				//gaussianPlusBG->FixParameter(3,0);
				//gaussianPlusBG->FixParameter(4,0);
				gaussianPlusBG->FixParameter(5,0);

				h.GeCalib_clu_ALPHA[j]->Fit(gaussianPlusBG,"QR");
				h.GeCalib_clu_ALPHA_MaxSigma->SetBinContent(CLUSTER-1,j,(gaussianPlusBG->GetParameter("sigma")));
				//Double_t tempCounts = PeakMaxCounts[0];
				//Double_t tempSigma = PeakSigma[0];
				//if (tempCounts < h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1))) PeakMaxCounts[0] = h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1));
				//if (tempSigma < gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = gaussianPlusBG->GetParameter("sigma")
				Double_t tempSigma = PeakSigma[0];
				if (tempSigma < 1/gaussianPlusBG->GetParameter("sigma")) PeakSigma[0] = 1/gaussianPlusBG->GetParameter("sigma");
				if (1/gaussianPlusBG->GetParameter("sigma") < 0.95* PeakSigma[0]) delete h.GeCalib_clu_ALPHA[j];
			}
	}
	PeakSigma[0] = 0;
	//cout << "Deleting the boring ones\n";
	//{
	//	cout << "Start - Theta " << clu_theta[CLUSTER-1]
	//		<< "	Phi " << clu_phi[CLUSTER-1]
	//		<< "	cluster " << CLUSTER << "\n";

		//for (int j=0; j< GE_THETA_NSTEPS; j++)
		//{
		//	for (int k=0; k< GE_PHI_NSTEPS; k++)
		//	{

				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];
				//if ( h.GeCalib_dcT[j][k]->Integral(int(GammaEnergy-1),int(GammaEnergy+1)) < PeakMaxCounts[0]*.95 ) delete h.GeCalib_dcT[j][k];

			//}
		//}
	//}

#endif
	// Add spectra
	h.AddSpectra(bg_frac);

	long nopart = (long)h.part->Integral();
	printf("1-particle events = %lu\n",nopart);

#ifdef PHICAL
	TCanvas *cphi;
	cphi = new TCanvas( "PhiCalibration", "Phi Calibration" );
	for( int i = 0; i < PHI_NSTEPS; i++ ) {

		h.phical_dcT[i]->SetLineColor(i+1);
		if( i == 0 ) h.phical_dcT[i]->Draw();
		else h.phical_dcT[i]->Draw("SAME");

	}
#endif
#ifdef CALIB
# if 0
	string cname;
	TCanvas *clu[8];
	for( int i = 0; i < 8; i++ ) {

		cname = "Cluster" + doppler::convertInt(i+1);
		clu[i] = new TCanvas( cname.c_str(), cname.c_str() );
		clu[i]->cd();

		for( int j = 0; j < 3; j++){

			h.GeCalib_cid[i*3+j]->SetLineColor(j+1);
			if( j == 0 ) h.GeCalib_cid[i*3+j]->Draw();
			else h.GeCalib_cid[i*3+j]->Draw("SAME");

		}

	}
# endif
#endif	

	out->Write();

}

#ifndef __CINT__
int main( int argc, char *argv[] ) {

	string arg_str;
	string outputfilename;
	vector<string> inputfilenames;
	int j = 0;

	// If not arguments, run default
	if( argc == 1 ) {

		time_t rawtime;
		struct tm *timeinfo;
		char buf[80];

		time( &rawtime );
		timeinfo = localtime( &rawtime );

		strftime( buf, 80, "%Y%m%d_%H%M", timeinfo );

		outputfilename = buf;
		outputfilename = "Hists_" + outputfilename + ".root";

		g_clx x;
		x.Loop( outputfilename );

	}

	// Else process command line arguments
	else {

		for( int i = 1; i < argc; i++ ) {

			arg_str.assign( argv[i] );

			// Help
			if( arg_str == "-h" ) {

				cout << argv[0] << "-i <inputfiles> -o <outputfile>" << endl;

			}

			// Input files
			else if( arg_str == "-i" ) {

				if( i >= argc ) {

					cerr << "No input filename given" << endl;
					return 0;

				}

				cout << "List of input files..." << endl;

				while( i+j+1 < argc ) {

					arg_str.assign( argv[i+j+1] );

					if( arg_str[0] == '-' ) break;

					inputfilenames.push_back( arg_str );
					cout << inputfilenames[j] << endl;

					j++;

				}

			} // "-i"

			// Output file
			else if( arg_str == "-o" ) {

				if( i >= argc ) {

					cerr << "No output filename given" << endl;
					return 0;

				}

				else outputfilename = argv[i+1];

				cout << "Output file: " << outputfilename << endl;


			} // "-o"

		} // i

	} // process command line arguments

	// Test if output file is there
	if( outputfilename.size() <= 0 ) {

		cout << "Did you specify your output file correctly?" << endl;
		return 0;

	}

	// Test if input files are there
	if( inputfilenames.size() <= 0 ) {

		cout << "Did you specify your input files correctly?" << endl;
		return 0;

	}

	// Make chain for g_clx
	TChain *chain = new TChain( "g_clx", "" );
	for( unsigned int i = 0; i < inputfilenames.size(); i++ ) {

		chain->Add( inputfilenames[i].c_str() );	

	}

	// Initiate g_clx
	g_clx x( chain );
	x.Loop( outputfilename );

	return 0;

}
#endif

