#ifndef __MBEVTS_HH__
#define __MBEVTS_HH__

#include "TObject.h"

#include <iostream>
using namespace std;

class mbevts : public TObject {
//class mbevts {

	public:
	
	// original gamma-ray
	double gen;
	int cid;
	int sid;
	int cluid;
	double tha;
	double pha;
	
	// list of correlated gammas
	vector <double> gcor_gen;
	vector <int> gcor_cid;
	vector <int> gcor_sid;
	vector <int> gcor_cluid;
	vector <double> gcor_tha;
	vector <double> gcor_pha;
	vector <double> gcor_gtd;
	
	// particles (max. 8)
	int ctr;
	double pen[8];
	double time[8];
	double sst[8];
	double td[8];
	int ann[8];
	int sec[8];
	int det[8];
	int coin[8];
	int laser;
	int pr_hits;
	int rndm_hits;

	// pointers for particles
	int pr_ptr[8];
	int rndm_ptr[8];
	int file; 

	// setup functions
	void Initialize();
	void SetGen(double en);
	void SetTheta(double theta);
	void SetPhi(double phi);
	void SetCluid(int id);
	void SetCid(int id);
	void SetSid(int id);
	void SetCorGamGen(double en);
	void SetCorGamTheta(double theta);
	void SetCorGamPhi(double phi);
	void SetCorGamCluid(int id);
	void SetCorGamCid(int id);
	void SetCorGamSid(int id);
	void SetCorGamGtd(double td);
	void SetPart(double en, int a, int s, double t, double ss, double ctd, int co, int quad, int laserflag, int nr);
	void SearchCoin();
	void CopyData(mbevts* src);

	// get functions
	int GetCluid();
	int GetCid();
	int GetSid();
	double GetGen();
	double GetTheta();
	double GetPhi();
	double GetPen(int nr);
	int GetNrParts();
	int GetSec(int nr);
	int GetAnn(int nr);
	
	ClassDef(mbevts,2);

};

#endif
