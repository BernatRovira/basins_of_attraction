#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  load_w
 *    Description:  load already computed steady state w
 * =====================================================================================
 */
   int
load_w ( int load_from_file )
{
   unsigned int i;

   if(load_from_file){              //// loading the file if load_from_file != 0
      FILE *data;
      char string[18];
      sprintf(string,"wmatrix_%04i_%1.3f",N,f);
      data = fopen(string,"r");
      for ( i=0; i<N*N; i++ ) {
         fscanf(data,"%f ",&w[i]);
      }
      fclose(data);
   }

   if(!load_from_file){             ////// synthetic creation of matrices if load_from_file == 0
      unsigned int j,k;
      float rnd;
//      FILE *prova;
//      prova =fopen("w_loading","w");

      /* updating W synthetic */
      for ( i=0; i<L; i++ ){                   /* grab each pattern */
         for ( j=0; j<N; j++ ){                /* coordinate eta_j */
               for ( k=0; k<j; k++ ){          /* coordinate eta_k */
                  if(w[j*N+k]){                  /* if W+ */
                     if( (pattern[i*N+j])^(pattern[i*N+k]) ){ /* and j or k are firing (only one). ^ is XOR */
                        if( (pattern[i*N+k]) ){
                           rnd =  dice(); 
                           if( (rnd<q_01) ){
                              w[j*N+k] = 0;          /* dep01 */
                              w[k*N+j] = 0;          /* SIMMETRY */
                           }
                        }
                        else{
                           rnd =  dice(); 
                           if( (rnd< q_10) ){
                              w[j*N+k] = 0;          /* dep10 */
                              w[k*N+j] = 0;          /* SIMMETRY */
                           }  
                        }
                     }
                  }
                  else if ( (pattern[i*N+j]) & (pattern[i*N+k]) ){  /* if W- and j,k firing. & is AND */ 
                     w[j*N+k] = 1;          /* pot */ 
                     w[k*N+j] = 1;          /* SIMMETRY */ 
                  }
               }
         }
//         fprintf(prova,"%i %f\n",i,mean(w,N*N));
      }
//      fclose(prova);
      for ( i=0; i<N; i++ ) {
         w[i*N+i] = 1;          /* autoexcitation loop */
      }
   }
   float prob;
   prob = 1/(2.0-f);                /*stationary positive prob b/(a+b) */
   printf ( "Average Wij: %f\nPrediction: %f\n",mean(w,N*N),prob ); /* compared with mean of W */
   
   for ( i = 0; i<N*N; i++ ) {
      w[i] -= w_EI;                             /* restem w_EI per fer Weff */
   }
   printf ( "Average Weff: %f\n",mean(w,N*N)); /* mean of Weff */
   return EXIT_SUCCESS;
}		/* -----  end of function load_w  ----- */

/* ORIGINAL CHAINED TERNARY VERSION */
//      for ( i=0; i<L; i++ ) {                   /* grab each pattern */
//         for ( j=0; j<N; j++ ) {                /* coordinate eta_j */
//            if(pattern[i*N+j]==0){              /* if j is not firing */
//               for ( k=0; k<j; k++ ) {          /* coordinate eta_k */
//                  w[j*N+k] = (pattern[i*N+k]==0) ?  w[j*N+k] /* if k is also silent, VOID */
//                                                 : (q_01 <= ((float)rand()/(float)RAND_MAX)) ?  w[j*N+k] /* if not throw dice, fails VOID */
//                                                                                             :  0;   /* otherwise DEP */
//                  w[k*N+j] = w[j*N+k];          /* SIMMETRY */
//               }
//            }
//            else{                               /* if j is firing */
//               for ( k=0; k<j; k++ ) {          /* coordinate eta_k */
////                  w[j*N+k] = (pattern[i*N+k]==0) ?  ( q_10<=((float)rand()/(float)RAND_MAX) ) ?  w[j*N+k] 
////                                                                                              :  0  
////                                                 : 1; 
//                  w[j*N+k] = (pattern[i*N+k]==1) ?  1
//                                                 : ( q_10<=((float)rand()/(float)RAND_MAX) ) ?  w[j*N+k] 
//                                                                                             :  0;
//               }
//                  w[k*N+j] = w[j*N+k];          /* SIMMETRY */
//            }
//
//         }
//
//         fprintf(prova,"%i %f\n",i,mean(w,N*N));
//
//      }

//   printf ( "press any key, matrix will be studied\n" ); espera
//  unsigned int j; 
//      float dum;
//      for ( i=0; i<N; i++ ) {
//         if(pattern[(L-1)*N+i]){
//            dum=0;
//            for ( j=0; j<N; j++ ) {
//               if(pattern[(L-1)*N+j]){
//                  dum+=w[i*N+j];
//               }
//            }
//            printf ( "Selective neuron %i sum of POT inputs: %f\n",i,dum );
//         }
//         else{
//            dum=0;
//            for ( j=0; j<N; j++ ) {
//               if(pattern[(L-1)*N+j]){
//                  dum+=w[i*N+j];
//               }
//            }
//            printf ( "NON-Selective neuron %i sum of DEP inputs: %f\n",i,dum );
//         }
//      }
//      anykey
//   for ( i=0; i<N*N; i++ ) {
////      printf ( "%1.0f",w[i] );
//      if( (w[i]!=0) && (w[i]!=1) ){
//         printf ( "ERROR: SOMETHING IS WRONG WITH W\n" );
//         exit(EXIT_FAILURE);
//      }
//   }
//   printf ( "press any key\n" ); espera

//   w_EI = (1.0)*mean(w,N*N); printf ( "w_EI set to 100 percent average synaptic weight\n" );

