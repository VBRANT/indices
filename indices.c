/*      Sat May 28 12:29:47 EEST 2011
        Ver 0.1
        Panagiotis Vavilis
        pvavilis@her.hcmr.gr    */
#include "common.h"

/* Number of Individuals function */
int NumOfIndividuals ( station_t st, int nsp )
{
	int i,sum=0;

	for (i=0; i<nsp; i++) {
		if ( st.spcs[i].size != 0 )
			sum+=st.spcs[i].size;
	}
	return (sum);
}

/* Species Richness function */
int SpeciesRichness ( station_t st, int nsp )
{
	int i,cnt=0;
	for (i=0; i<nsp; i++) {
		if ( st.spcs[i].size != 0 )
			cnt++;
	}
	return (cnt);
}

/* Shannon Index function */
REAL ShannonIndex ( station_t st, int nsp )
{
	int i;
	REAL H,cf;
	int N,S;

	N = NumOfIndividuals(st, nsp);
	S = SpeciesRichness(st, nsp);
	if ( N == 0 ) 
		return (0);
	cf = (REAL)((S-1)/(2*N));
	H=0;
	for (i=0; i<nsp; i++) {
		if ( st.spcs[i].size != 0 )
			H = H + ((REAL)st.spcs[i].size/(REAL)N)*log((REAL)st.spcs[i].size/(REAL)N); 	
	}	
	return (-H-cf);
} 
	
/* Species Evenness function */
REAL SpeciesEvenness( station_t st, int nsp )
{
	REAL H,Hmax;

	H =  ShannonIndex(st,nsp);
	Hmax = log((REAL)SpeciesRichness(st,nsp));
	return (H/Hmax);
}

