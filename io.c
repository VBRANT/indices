/*      Sat May 28 12:29:47 EEST 2011
        Ver 0.1
        Panagiotis Vavilis
        pvavilis@her.hcmr.gr    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

station_t *readCSV(char *infile, int *pcls, int *prws)
{
	
	station_t *stns;
	FILE *fp;	
	register int i=0,j=0;
	int cls=0,rws=0;
	char Line[2048];
	char *tokenPtr;


	rws = counter(infile)-1; /*total number of lines minus header */

	if ( (fp=fopen(infile,"r")) == NULL ) {
		printf("I/O Error:Cannot open file %s\n",infile);
      		exit(-1);
    	}
	fgets(Line, sizeof(Line), fp); 
	tokenPtr = strtok(Line,",");

	cls=-1;
   	while ( tokenPtr != NULL ) { 
      		tokenPtr = strtok( NULL, "," );
		cls++;
   	}

	stns = (station_t *)malloc(cls*sizeof(station_t));
	for (i=0; i<cls; i++)
		stns[i].spcs = (species_t *)malloc(rws*sizeof(species_t));

	fseek(fp,0, SEEK_SET);
	fgets(Line, sizeof(Line), fp); 
	tokenPtr = strtok(Line,",");
	i=0;
   	while ( tokenPtr != NULL ) { 
      		tokenPtr = strtok( NULL, "," );
		if ( tokenPtr != NULL ){
      			stns[i].name = (char *)malloc(sizeof(char)*strlen(tokenPtr)+1);
        		strncpy(stns[i].name, tokenPtr, sizeof(char)*strlen(tokenPtr) );
			i++;
		}
	}


	i=0;
	while(fgets(Line, sizeof(Line), fp)) {  
      		tokenPtr = strtok(Line,",");
		for (j=0; j<cls; j++) {
      			stns[j].spcs[i].name = (char *)malloc(sizeof(char)*strlen(tokenPtr)+1);
      			strncpy(stns[j].spcs[i].name, tokenPtr, sizeof(char)*strlen(tokenPtr) );
      			stns[j].spcs[i].name[sizeof(char)*strlen(tokenPtr)] = '\0';
		}
		j=0;
		while ( tokenPtr != NULL ) {
      			tokenPtr = strtok( NULL, "," );
			if ( tokenPtr != NULL )
				stns[j].spcs[i].size=atoi(tokenPtr);
			j++;
		}
		i++;
    	}  
	*pcls = cls;
	*prws = rws;
	return (stns);
}
