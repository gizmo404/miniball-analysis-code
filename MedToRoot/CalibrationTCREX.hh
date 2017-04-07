#ifndef __CALIBRATIONTCREX_HH
#define __CALIBRATIONTCREX_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "TSystem.h"
#include "TEnv.h"
#include "TRandom.h"
#include "TMath.h"

#include "CommandLineInterface.hh"

using namespace std;

class CalibrationTCREX {

public:

	CalibrationTCREX();
	CalibrationTCREX(const char*);
	~CalibrationTCREX();
	void ReadCalibration();
	void PrintCalibration();
	void SetFile(const char* filename){
		fInputFile = filename;
	}
	const string InputFile(){
		return fInputFile;
	}
	double DgfEnergy(int dgf, int chan, unsigned short raw);
	double AdcEnergy(int adc, int chan, unsigned short raw);
	int PosFBCDRing(int Quad, unsigned short raw);
	int PosFBCDStrip(int Quad, unsigned short raw);
	int PosRing(int Quad, unsigned short raw);
	int PosStrip(int Quad, unsigned short raw);
	int StripPosBarrel(unsigned short strraw, unsigned short rearraw);

private:

	int fVerbose;
	string fInputFile;

	TRandom* fRand;
  
	vector< vector<long double> > fDgfGainQuadr;
	vector< vector<double> > fDgfOffset;
	vector< vector<double> > fDgfGain;
	vector< vector<double> > fAdcOffset;
	vector< vector<double> > fAdcGain;
	vector< vector<double> > fFCDPosStrip;
	vector< vector<double> > fFCDPosRing;
	vector< vector<double> > fBCDPosStrip;
	vector< vector<double> > fBCDPosRing;

	double fBeamdumpOffset;
	double fBeamdumpGain;
	double fBeamdumpGainQuadr;
  
	double RawRandomized;

	int fNofDgfs;
	int fNofDgfChans;
	int fNofAdcs;
	int fNofAdcsCD;
	int fNofAdcChans;
	int fNofCDSegm;
 
	double fFWHMPosMux;
	vector<double> fLimitFBCD;

	int fBeamdumpDgf;

	ClassDef(CalibrationTCREX, 1);
   
};

#endif
