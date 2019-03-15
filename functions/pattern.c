#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  fill_memories
 *  Description:  encode L times a random pattern of EXACTLY fN neurons 
 * =====================================================================================
 */
   int
fill_patterns (int load_from_file, int L)
{
   int i,j,k;
   
   if(load_from_file){ //// loading the file if load_from_file != 0
      FILE *data_patterns;
      char string[18];
      sprintf(string,"patterns_%04i_%1.3f",N,f);
      data_patterns = fopen(string,"r");
      for ( i=0; i<L; i++ ) {
         for ( j=0; j<N; j++ ) {
            fscanf(data_patterns,"%i ",&pattern[j+i*N]);
         }
         fscanf(data_patterns,"\n");
      } 
      fclose(data_patterns);
      data_patterns=NULL;
   }

   if(!load_from_file){ ////// creating the patterns if load_from_file == 0
   int alea,activated_neurons=round((float)N*f);               /* el nombre de neurones activades per cada estat */
   for( k=0; k<L; k++ ) {                                      /* per cada memoria */
      for ( i=0; i<activated_neurons; i++ ) {                  /* activarem  activated_neurons neurones */
         alea=floor((float)N*((float)rand()/(float)RAND_MAX)); /* seleccionem un element a l'atzar */
         if(!pattern[alea+k*N]){                               /* si esta parada */
            pattern[alea+k*N]=1;                               /* l'activem */
         }
         else{                                                 /* si esta activada (no esta parada) */
         //else if(pattern[alea+k*N]){                         
            i--;                                               /* ho tornem a provar */
         }
      }
   }
   }

   return EXIT_SUCCESS;
}		/* -----  end of function fill_memories  ----- */
