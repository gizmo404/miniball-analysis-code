#ifndef __CALIBRATION_HH
#define __CALIBRATION_HH

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

class Calibration {

public:

	Calibration();
	Calibration(const char*);
	~Calibration();
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
	double FCDPadEnergy(int Quad, unsigned short raw);
	int PosFBCDRing(int Quad, unsigned short raw);
	int PosFBCDStrip(int Quad, unsigned short raw);

private:

	int fVerbose;
	string fInputFile;

	TRandom* fRand;
  
	vector< vector<long double> > fDgfGainQuadr;
	vector< vector<double> > fDgfOffset;
	vector< vector<double> > fDgfGain;
	vector< vector<double> > fAdcOffset;
	vector< vector<double> > fAdcGain;
	vector< double > fFCDpadGain;
	vector< double > fFCDpadOffset;
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
	int fNofFCDPads;
	int fNofAdcChans;
	int fNofAdcsCD;
	int fNofCDSegm;
 
	double fFWHMPosMux;
	vector<double> fLimitFBCD;

	int fBeamdumpDgf;

	ClassDef(Calibration, 1);
   
};

#endif
