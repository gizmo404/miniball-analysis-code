#ifndef hists_hh
#define hists_hh

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include "TObject.h"

#include <iostream>
#include <string>
using namespace std;

// Experimental definitions
#ifndef ExpDefs_hh
# include "ExpDefs.hh"
#endif

// Headers for doppler
#ifndef doppler_hh
# include "doppler.hh"
#endif

using namespace std;

class hists {

	// Declare histos : 
	// B = Beam detection 
	// T = Target detection 
	// 2hB = both detected - Beam part
	// 2hT = both detected - Target part
	// p=prompt r=random

	public:

	// Undoppler-corrected gamma spectra
	TH1F *p, *r, *pmr;
	TH1F *pB, *rB, *pBmrB;
	TH1F *pT, *rT, *pTmrT;
	TH1F *p_1B, *r_1B, *p_1T, *r_1T, *p_2h, *r_2h;

	// Undoppler-corrected electron spectra
	TH1F *pe, *re, *pemre;
	TH1F *peB, *reB, *peBmreB;
	TH1F *peT, *reT, *peTmreT;
	TH1F *pe_1B, *re_1B, *pe_1T, *re_1T, *pe_2h, *re_2h;
	
	// Coincidence matrices
	TH2F *gg, *ge;
	TH2F *gg_dcT, *gg_dcB;
	TH1F *gg_td, *ge_td;
	TH1F *gcor_size;

	// Calibrate phi rotation of cd
#ifdef PHICAL
	TH1F *phical_dcB[PHI_NSTEPS], *phical_dcT[PHI_NSTEPS];
	TH2F *phical_dcT_MaxSigma;
#endif
	// Doppler corrected spectra per detector
#ifdef CALIB
	TH1F *GeCalib_clu[8], *GeCalib_cid[24];
	//TH1F *GeCalib_dcT[3][GE_THETA_NSTEPS][GE_PHI_NSTEPS];
	//TH2F *GeCalib_dcTMax[3];
	//TH2F *GeCalib_dcTMaxE[3];
	//TH2F *GeCalib_dcTMaxSigma[3];
	TH1F *GeCalib_dcT[GE_THETA_NSTEPS][GE_PHI_NSTEPS];
	TH2F *GeCalib_dcTMax;
	TH2F *GeCalib_dcTMaxE;
	TH2F *GeCalib_dcTMaxSigma;
#endif

#ifdef CDCALIB
	TH1F *GeCalib_clu_CD[8][CD_DIST_NSTEPS];	
	TH2F *GeCalib_clu_CD_MaxSigma;
#endif

#ifdef DISTCALIB
	TH1F *GeCalib_clu_DIST[CLU_DIST_NSTEPS];	
	TH2F *GeCalib_clu_DIST_MaxSigma;
#endif

#ifdef ALPHACALIB
	TH1F *GeCalib_clu_ALPHA[CLU_ALPHA_NSTEPS];	
	TH2F *GeCalib_clu_ALPHA_MaxSigma;
#endif

#ifdef SPEDECALIB
	TH1F *SpedeCalib_dist[SPEDE_DIST_NSTEPS];
	TH2F *SpedeCalib_dist_mat;
	TH1F *SpedeCalib_alpha[SPEDE_ALPHA_NSTEPS];
	TH2F *SpedeCalib_alpha_mat;
	TH1F *sid_test;
	TH1F *sid_single_test[50];
	TH2F *sid_single_dist[50];
	TH2F *sid_single_alpha[50];
#endif
	 
	// Background subtracted, Doppler corrected gamma spectra
	TH1F *B_dcB, *B_dcT, *B_1hdcB, *B_1hdcT;
	TH1F *T_dcT, *T_dcB, *T_1hdcT, *T_1hdcB;
	TH1F *T_dcB_x[16], *T_dcT_x[16];
	TH1F *gam_dcB, *gam_dcT, *T_2hdcB, *T_2hdcT;
   
	// Background subtracted, Doppler corrected electron spectra
	TH1F *Be_dcB, *Be_dcT, *Be_1hdcB, *Be_1hdcT;
	TH1F *Te_dcT, *Te_dcB, *Te_1hdcT, *Te_1hdcB;
	TH1F *Te_dcB_x[16], *Te_dcT_x[16];
	TH1F *elec_dcB, *elec_dcT, *Te_2hdcB, *Te_2hdcT;
   
	// Prompt/Random Particle spectra
	TH2F *part, *part1h, *part2h, *partQ[4], *part_ann;
	TH2F *Bh, *Th, *B1h, *T1h, *B2h, *T2h;
	TH2F *Bhhigh, *Bhlow, *Thhigh, *Thlow;
	TH1F *target_ev, *target_1pev, *target_2pev;
#ifdef TWOPART
	TH2F *BT[16], *TB[16];
#endif

	// Second hit - simulated etc.
	TH2F *Bsim, *Tsim;
	TH2F *en2hit;
	TH1F *sum2hit;

	// CD picture using the gamma gating
	TH2F *cdpic;
	
	// Testing
	TH1F *multp, *multr;
	TH1F *GeReject, *GePass, *GeRatio;
	TH2F *GeAng;
#ifdef GEANG
	TH2F *GeAng_clu[8];
	TH3F *GeSiAng, *GeSiAng_clu[8];
#endif

	// gamma - particle time difference
	TH1F *tdiff, *tdiff_e;
#ifdef TDIFF
	float tegate[4]; // Energy gates for tdiff spectra
	TH1F *tdiffE[4], *tdiffQ[4]; // Energy and Quadrant gated

	// particle - particle time difference
	TH1F *tppdiff;
	TH2F *tpp;
	TH1F *tQQ[2];
#endif

	// Variables to be set in g_clx.C via Set_xxx functions
	double ppwin;
	int maxrecoil;
	int minrecoil;

	// Array of cd angles for histogram bins
	double cd_angles[17];

	// functions
	void Initialise();
	void Set_ppwin( double user_ppwin );
	void Set_maxrecoil( int user_maxrecoil );
	void Set_minrecoil( int user_minrecoil );

	// fill functions
	void Fill1h( double GEn, double GTh, double GPh, vector <double> GCor_GEn, vector <double> GCor_GTh,
					vector <double> GCor_GPh, vector <int> GCor_GCluID, vector <double> GCor_Gtd, bool electron,
					double PEn, Int_t Pann, Int_t Psec, Int_t Pquad, double weight=1.0 );
	void Fill2h( double GEn, double GTh, double GPh, vector <double> GCor_GEn, vector <double> GCor_GTh,
					vector <double> GCor_GPh, vector <int> GCor_GCluID, vector <double> GCor_Gtd, bool electron,
					double *PEn, Int_t *Pann, Int_t *Psec, Int_t *Pquad, Int_t *Pptr, double *td, double weight=1.0 );
	void FillGam1h( double GEn, double GTh, double GPh, double PEn, Int_t Pann,
					Int_t Psec, Int_t Pquad, Int_t cut, double weight=1.0 );
	void FillGam2h( double GEn, double GTh, double GPh, double *PEn, Int_t *Pann,
					Int_t *Psec, Int_t *Pquad, Int_t Bptr, Int_t Tptr, double weight=1.0 );
	void FillElec1h( double GEn, double GTh, double GPh, double PEn, Int_t Pann,
					Int_t Psec, Int_t Pquad, Int_t cut, double weight=1.0 );
	void FillElec2h( double GEn, double GTh, double GPh, double *PEn, Int_t *Pann,
					Int_t *Psec, Int_t *Pquad, Int_t Bptr, Int_t Tptr, double weight=1.0 );
	void FillGamGam1h( double GEn, double GTh, double GPh, vector <double> GCor_GEn, vector <double> GCor_GTh,
					  vector <double> GCor_GPh, vector <int> GCor_GCluID, vector <double> GCor_Gtd,
					  double PEn, Int_t Pann, Int_t Psec, Int_t Pquad, Int_t cut, double weight=1.0 );
	void FillGamGam2h( double GEn, double GTh, double GPh, vector <double> GCor_GEn, vector <double> GCor_GTh,
					  vector <double> GCor_GPh, vector <int> GCor_GCluID, vector <double> GCor_Gtd, double *PEn,
					  Int_t *Pann, Int_t *Psec, Int_t *Pquad, Int_t Bptr, Int_t Tptr, double weight=1.0 );
	void FillPar1h( double PEn, Int_t Pann, Int_t Psec, Int_t Pquad, Int_t cut, double weight=1.0 );
	void FillPar2h( double *PEn, Int_t *Pann, Int_t *Psec, Int_t *Pquad, Int_t Bptr, Int_t Tptr, double weight=1.0 );
	void PhiCalHists( double GEn, double GTh, double GPh, double PEn, Int_t Pann,
						Int_t Psec, Int_t Pquad, Int_t cut, double weight=1.0 );
	void AddSpectra( double bg_frac );
		
	private:

	//ClassDef(hists,1);

};
#endif
