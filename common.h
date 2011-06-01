/*	Sat May 28 12:29:47 EEST 2011
	Ver 0.1
	Panagiotis Vavilis
	pvavilis@her.hcmr.gr	*/
#include <stdio.h>
#include <stdarg.h>


 /* Real type definition */
 typedef double REAL;

 /* Counter type */
 typedef unsigned long count_t;

 static void error_print (int , char *, va_list );
 static void errf (char *, ...);
 static void perrf (char *, ...);
 static int isword (unsigned char );
 int getword (FILE *);
 int counter (char *);

 /* specie data type */
 typedef struct species {
        char *name;
        int size;
 } species_t;

 /* station data type */
 typedef struct station {
        char *name;
        species_t *spcs;
 } station_t;

 /* functions headers */
 int NumOfIndividuals ( station_t , int );
 int SpeciesRichness ( station_t , int );
 REAL ShannonIndex ( station_t , int );
 REAL SpeciesEvenness ( station_t , int );
 station_t *readCSV( char *, int *, int * );

