#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  fill_rates
 *  Description:  initial distribution of firing rates. Modifiable to introduce patterns as IC. Forced to modify EXACTLY hamming elements
 * =====================================================================================
 */
   int
fill_rates( int number,int hamming )
{
   unsigned int i;
   if(number==-1){
      for ( i=0; i<N; i++ ) {                      
         r[i]=0;                    
         h[i]=0;                    
      }
   }
   else{
      for ( i=0; i<N; i++ ) {                      
        r[i]=pattern[number*N+i];                    
      }
  /* UNBALANCED HAMMING DISTANCE */
      if(hamming){               /* si cal iniciar a una hamming distance ho fem */
         int moved[N];
         for ( i=0; i<N; i++ ) {
            moved[i]=0;                         /* comptarem els que s'han invertit */
         }
         unsigned int alea,k;
         for ( k=0; k<hamming; k++ ) {
            alea=floor((float)N*((float)rand()/(float)RAND_MAX)); /* seleccionem un element a l'atzar */
            if(moved[alea])                     /* si s'ha invertit */
               k--;                             /* en busquem un altre */
            if(!moved[alea]){                   /* si no s'ha invertit */
               moved[alea]=1;                   /* comptem que el girarem */
               r[alea]=1-r[alea];           /* i l'invertim (0->1 || 1->0)*/
            }
         }
         int sum=0;
         for ( i=0; i<N; i++ ) {
            sum+=moved[i];
         }
//         if(sum==hamming){
//            printf ( "sum=hamming, everything ok!\n" );
//         }
//         else{
         if(sum!=hamming){
            printf ( "ERROR: sum=%i != hamming=%i\n",sum,hamming );
            espera
         }
      }
      float dum;
      unsigned int j;
      for ( i=0; i<N; i++ ) {       /* Actualitzem els inputs a on toca  */
         dum=0;
         for ( j=0; j<N; j++ ) {
            dum += w[i*N+j]*r[j];  
         }
         h[i] = dum-theta;
      }
   }
   return EXIT_SUCCESS;
}		/* -----  end of function fill_rates  ----- */





