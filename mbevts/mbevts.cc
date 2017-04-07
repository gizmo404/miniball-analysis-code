#ifndef mbevts_cxx
#define mbevts_cxx

#include "mbevts.hh"

void mbevts::Initialize() {
	
	gen=-100.;
	cid=-1;
	sid=-1;
	cluid=-1;
	tha=-1;
	pha=-1;
	
	gcor_gen.resize(0);
	gcor_cid.resize(0);
	gcor_sid.resize(0);
	gcor_cluid.resize(0);
	gcor_tha.resize(0);
	gcor_pha.resize(0);
	gcor_gtd.resize(0);
	
	ctr=0;
	for( int i=0; i<8; i++ ){
	
		pen[i]=-100.;
		time[i]=-100.;
		sst[i]=-100.;
		td[i]=-20000.;
		ann[i]=-1;
		sec[i]=-1;
		det[i]=-1;
		coin[i]=-1;
		pr_ptr[i]=-1;
		rndm_ptr[i]=-1;
	
	}
	
	laser=-1;
	pr_hits=0;
	rndm_hits=0;
	file=-1;
	
}

void mbevts::CopyData(mbevts* src) {
	
	gen=src->gen;
	cid=src->cid;
	sid=src->sid;
	cluid=src->cluid;
	tha=src->tha;
	pha=src->pha;
	
	gcor_gen = src->gcor_gen;
	gcor_cid = src->gcor_cid;
	gcor_sid = src->gcor_sid;
	gcor_cluid = src->gcor_cluid;
	gcor_tha = src->gcor_tha;
	gcor_pha = src->gcor_pha;
	gcor_gtd = src->gcor_gtd;
	
	ctr=src->ctr;
	for( int i=0; i<8; i++ ){
		
		pen[i]=src->pen[i];
		time[i]=src->time[i];
		sst[i]=src->sst[i];
		td[i]=src->td[i];
		ann[i]=src->ann[i];
		sec[i]=src->sec[i];
		det[i]=src->det[i];
		coin[i]=src->coin[i];
		rndm_ptr[i]=src->rndm_ptr[i];
		pr_ptr[i]=src->pr_ptr[i];
		
	}
	
	laser=src->laser;
	pr_hits=src->pr_hits;
	rndm_hits=src->rndm_hits;
	file=src->file;
	
}

void mbevts::SetGen(double en) {
	
	gen=en;
	
}

void mbevts::SetCluid(int id) {
	
	cluid=id;
	
}

void mbevts::SetCid(int id) {
	
	cid=id;
	
}

void mbevts::SetSid(int id) {
	
	sid=id;
	
}

void mbevts::SetTheta(double theta) {
	
	tha=theta;
	
}

void mbevts::SetPhi(double phi) {
	
	pha=phi;
	
}

void mbevts::SetCorGamGen(double en) {
	
	gcor_gen.push_back( en );
	
}

void mbevts::SetCorGamCluid(int id) {
	
	gcor_cluid.push_back( id );
	
}

void mbevts::SetCorGamCid(int id) {
	
	gcor_cid.push_back( id );
	
}

void mbevts::SetCorGamSid(int id) {
	
	gcor_sid.push_back( id );
	
}

void mbevts::SetCorGamTheta(double theta) {
	
	gcor_tha.push_back( theta );
	
}

void mbevts::SetCorGamPhi(double phi) {
	
	gcor_pha.push_back( phi );
	
}

void mbevts::SetCorGamGtd( double td ) {
	
	gcor_gtd.push_back( td );
	
}

double mbevts::GetGen() {
	
	return gen;
	
}

int mbevts::GetCluid() {
	
	return cluid;

}

int mbevts::GetCid() {

	return cid;

}

int mbevts::GetSid() {

	return sid;

}

double mbevts::GetTheta() {

	return tha;

}

double mbevts::GetPhi() {

	return pha;

}

int mbevts::GetNrParts() {

	return ctr;

}

double mbevts::GetPen(int nr) {

	return pen[nr];

}

int mbevts::GetAnn(int nr) {

	return ann[nr];

}

int mbevts::GetSec(int nr) {

	return sec[nr];

}

void mbevts::SetPart(double en, int a, int s, double t, double ss, double ctd, int co, int quad, int laserflag, int nr) { 

	laser=laserflag;
	
	if( nr<8 ) {
		
		pen[nr]=en;
		ann[nr]=a;
		sec[nr]=s;
		time[nr]=t;
		sst[nr]=ss;
		td[nr]=ctd;
		det[nr]=quad;
		coin[nr]=co;
		
	} else {
		
		printf("INCREASE PARTS = 9 !\n");
	
	}
	
	ctr++;

}

void mbevts::SearchCoin() {

	for( int i=0; i<ctr; i++ ){
	
		if( coin[i]==0 ){
		
			pr_ptr[pr_hits]=i;
			pr_hits++; 
		
		}
		
		else if( coin[i]==1 ){
		
			rndm_ptr[rndm_hits]=i;
			
			rndm_hits++;
	
		}
	
	}

}
#endif
