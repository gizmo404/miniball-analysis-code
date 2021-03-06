//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb 18 15:39:48 2013 by ROOT version 5.34/05
// from TTree g_clx/g_clx
// found on file: 62Mn_109Ag.root
//////////////////////////////////////////////////////////

#ifndef g_clx_hh
#define g_clx_hh

#include <TROOT.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TGraph.h>
#include <TF1.h>
#include <TCutG.h>
#include <TMath.h>
#include <TGaxis.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// Header file for the classes stored in the TTree if any.
#include <TObject.h>

// Experimental definitions
#ifndef ExpDefs_hh
# include "ExpDefs.hh"
#endif

// Headers for tree
#ifndef __MBEVTS_HH__
# include "../mbevts/mbevts.hh"
#endif

// Fixed size dimensions of array or collections stored in the TTree if any.

class g_clx : public TObject {
	public :
	TTree          *fChain;   //!pointer to the analyzed TTree or TChain
	Int_t           fCurrent; //!current Tree number in a TChain
	
	// Declaration of leaf types
	//mbevts          *mbevts;
	UInt_t          fUniqueID;
	UInt_t          fBits;
	double          gen;
	int             cid;
	int             sid;
	int             cluid;
	double          tha;
	double          pha;
	vector <double> gcor_gen;
	vector <int>    gcor_cid;
	vector <int>    gcor_sid;
	vector <int>    gcor_cluid;
	vector <double> gcor_tha;
	vector <double> gcor_pha;
	vector <double> gcor_gtd;
	int             ctr;
	double          pen[8];
	double          time[8];
	double          sst[8];
	double          td[8];
	int             ann[8];
	int             sec[8];
	int             det[8];
	int             coin[8];
	int             laser;
	int             pr_hits;
	int             rndm_hits;
	int             pr_ptr[8];
	int             rndm_ptr[8];
	int             file;

	Double_t		PeakMaxCounts[3];
	Double_t		PeakSigma[3];
	Double_t		GammaEnergy;
	TF1 			*gaussian;
	TF1 			*gaussianPlusBG;

	double scan_alpha;
	
	// List of branches
	TBranch        *b_mbevts_fUniqueID;   //!
	TBranch        *b_mbevts_fBits;   //!
	TBranch        *b_mbevts_gen;   //!
	TBranch        *b_mbevts_cid;   //!
	TBranch        *b_mbevts_sid;   //!
	TBranch        *b_mbevts_cluid;   //!
	TBranch        *b_mbevts_tha;   //!
	TBranch        *b_mbevts_pha;   //!
	TBranch        *b_mbevts_gcor_gen;   //!
	TBranch        *b_mbevts_gcor_cid;   //!
	TBranch        *b_mbevts_gcor_sid;   //!
	TBranch        *b_mbevts_gcor_cluid;   //!
	TBranch        *b_mbevts_gcor_tha;   //!
	TBranch        *b_mbevts_gcor_pha;   //!
	TBranch        *b_mbevts_gcor_gtd;   //!
	TBranch        *b_mbevts_ctr;   //!
	TBranch        *b_mbevts_pen;   //!
	TBranch        *b_mbevts_time;   //!
	TBranch        *b_mbevts_sst;   //!
	TBranch        *b_mbevts_td;   //!
	TBranch        *b_mbevts_ann;   //!
	TBranch        *b_mbevts_sec;   //!
	TBranch        *b_mbevts_det;   //!
	TBranch        *b_mbevts_coin;   //!
	TBranch        *b_mbevts_laser;   //!
	TBranch        *b_mbevts_pr_hits;   //!
	TBranch        *b_mbevts_rndm_hits;   //!
	TBranch        *b_mbevts_pr_ptr;   //!
	TBranch        *b_mbevts_rndm_ptr;   //!
	TBranch        *b_mbevts_file;   //!
	
	g_clx( TTree *tree = 0 );
	virtual ~g_clx();
	virtual Int_t	GetEntry( Long64_t entry );
	virtual Long64_t	LoadTree( Long64_t entry );
	virtual void		Init( TTree *tree );
	virtual void		Loop( string outputfilename );
	virtual Bool_t	Notify();
	virtual void		Show( Long64_t entry = -1 );
	
	ClassDef(g_clx,1);
	
};

#endif

#ifdef g_clx_cxx
g_clx::g_clx(TTree *tree) : fChain(0) {
	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.
	
	if( tree == 0 ) {

		bool skip_flag;
		vector<int> skip_list;
		skip_list.push_back( 17 );
		skip_list.push_back( 22 );
		skip_list.push_back( 26 );
		skip_list.push_back( 32 );
		skip_list.push_back( 34 );
		skip_list.push_back( 54 );
		skip_list.push_back( 71 );
		skip_list.push_back( 74 );
		skip_list.push_back( 109 );
		skip_list.push_back( 111 );
		skip_list.push_back( 113 );
		skip_list.push_back( 114 );
		skip_list.push_back( 116 );
		skip_list.push_back( 119 );
	
		string inputfilename;
	
		TChain *chain = new TChain( "g_clx", "" );

		for( int i = 9; i <= 125; i++ ) {
	
			// Skip background/broken runs
			skip_flag = false;
			for( unsigned int j = 0; j < skip_list.size(); j++ ) 
				if( i == skip_list[j] ) skip_flag = true;
				
			if( skip_flag ) continue;
				
			// Skip decay runs
			if( i >= 84 && i <= 103 ) continue;

			inputfilename = "rootfiles/IS551_132Sn_RUN";
			if( i < 10 ) inputfilename += "00";
			else if( i < 100 ) inputfilename += "0";
			inputfilename += doppler::convertInt( i );
			inputfilename += "_tree.root";
	
			chain->Add( inputfilename.c_str() );	
		
		}
	
		tree = chain;
	
	}
	
	Init(tree);
	
}

g_clx::~g_clx() {
	if (!fChain) return;
	delete fChain->GetCurrentFile();
}

Int_t g_clx::GetEntry(Long64_t entry) {
	// Read contents of entry.
	if (!fChain) return 0;
	return fChain->GetEntry(entry);
}

Long64_t g_clx::LoadTree(Long64_t entry) {
	// Set the environment to read one entry
	if (!fChain) return -5;
	Long64_t centry = fChain->LoadTree(entry);
	if (centry < 0) return centry;
	if (fChain->GetTreeNumber() != fCurrent) {
		fCurrent = fChain->GetTreeNumber();
		Notify();
	}
	return centry;
}

void g_clx::Init(TTree *tree) {
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).
	
	// Set branch addresses and branch pointers
	if (!tree) return;
	fChain = tree;
	fCurrent = -1;
	fChain->SetMakeClass(1);
	
	fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_mbevts_fUniqueID);
	fChain->SetBranchAddress("fBits", &fBits, &b_mbevts_fBits);
	fChain->SetBranchAddress("gen", &gen, &b_mbevts_gen);
	fChain->SetBranchAddress("cid", &cid, &b_mbevts_cid);
	fChain->SetBranchAddress("sid", &sid, &b_mbevts_sid);
	fChain->SetBranchAddress("cluid", &cluid, &b_mbevts_cluid);
	fChain->SetBranchAddress("tha", &tha, &b_mbevts_tha);
	fChain->SetBranchAddress("pha", &pha, &b_mbevts_pha);
	fChain->SetBranchAddress("gcor_gen", &gcor_gen, &b_mbevts_gcor_gen);
	fChain->SetBranchAddress("gcor_cid", &gcor_cid, &b_mbevts_gcor_cid);
	fChain->SetBranchAddress("gcor_sid", &gcor_sid, &b_mbevts_gcor_sid);
	fChain->SetBranchAddress("gcor_cluid", &gcor_cluid, &b_mbevts_gcor_cluid);
	fChain->SetBranchAddress("gcor_tha", &gcor_tha, &b_mbevts_gcor_tha);
	fChain->SetBranchAddress("gcor_pha", &gcor_pha, &b_mbevts_gcor_pha);
	fChain->SetBranchAddress("gcor_gtd", &gcor_gtd, &b_mbevts_gcor_gtd);
	fChain->SetBranchAddress("ctr", &ctr, &b_mbevts_ctr);
	fChain->SetBranchAddress("pen[8]", pen, &b_mbevts_pen);
	fChain->SetBranchAddress("time[8]", time, &b_mbevts_time);
	fChain->SetBranchAddress("sst[8]", sst, &b_mbevts_sst);
	fChain->SetBranchAddress("td[8]", td, &b_mbevts_td);
	fChain->SetBranchAddress("ann[8]", ann, &b_mbevts_ann);
	fChain->SetBranchAddress("sec[8]", sec, &b_mbevts_sec);
	fChain->SetBranchAddress("det[8]", det, &b_mbevts_det);
	fChain->SetBranchAddress("coin[8]", coin, &b_mbevts_coin);
	fChain->SetBranchAddress("laser", &laser, &b_mbevts_laser);
	fChain->SetBranchAddress("pr_hits", &pr_hits, &b_mbevts_pr_hits);
	fChain->SetBranchAddress("rndm_hits", &rndm_hits, &b_mbevts_rndm_hits);
	fChain->SetBranchAddress("pr_ptr[8]", pr_ptr, &b_mbevts_pr_ptr);
	fChain->SetBranchAddress("rndm_ptr[8]", rndm_ptr, &b_mbevts_rndm_ptr);
	fChain->SetBranchAddress("file", &file, &b_mbevts_file);
	Notify();
}

Bool_t g_clx::Notify() {
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.
	
	return kTRUE;
}

void g_clx::Show(Long64_t entry) {
	/* Print contents of entry.	*/
	/* If entry is not specified, print current entry */
	if (!fChain) return;
	fChain->Show(entry);
}

#endif // #ifdef g_clx_cxx
