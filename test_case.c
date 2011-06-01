#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"

/* Source code to test the indices and io functions */
/* Input file should be csv file: Fisrt row: name of each station
   First column: name of each specie */ 

int main(int argc, char **argv)
{	
	station_t *stns;
	int i;
	int cols,rows;

	if (argc < 2){
    		printf("usage: csv FILE [FILE...]\n");
		return (-1);
	}

	stns = readCSV(argv[1],&cols,&rows);

	printf("\n\n\n");
	for (i=0; i<cols; i++){
		printf("id: %d Station: %s\n",i,stns[i].name);
		printf("Number of Individuals (N): %d\n",NumOfIndividuals(stns[i],rows));
		printf("Species Richness (S): %d\n",SpeciesRichness(stns[i],rows));
		printf("Shannon Index (H): %lf\n",ShannonIndex(stns[i],rows));
		printf("Species Evenness (J): %lf\n",SpeciesEvenness(stns[i],rows));
		printf("\n");
	}


 	return (0);
}
