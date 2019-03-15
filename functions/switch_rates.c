#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  fill_rates
 *  Description:  initial distribution of firing rates. Modifiable to introduce patterns as IC. Forced to modify EXACTLY hamming elements
 * =====================================================================================
 */
   int
fill_rates_switch( int number,int hamming )
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
      if(hamming){               /* si cal iniciar a una hamming distance ho fem */
         unsigned int selective=(int)round((float)N*f),selective_list[selective],pipo=0;
         for ( i=0; i<N; i++ ) {
            if(r[i]){
            selective_list[pipo]=i;                         /* guardem les posicions dels uns */
            pipo++;
            }
            if(pipo==selective)
               break;
         }
         int alea,alea2,mark,k;
         for ( k=0; k<hamming; k++ ) {
            alea=floor((float)N*dice()); /* seleccionem un element a l'atzar */
            if(r[alea])                     /* si val 1 */
               k--;                           /* en busquem un altre */
            else{                   /* si val 0 */
               r[alea]=1;                  /* l'activem*/
               mark=0;
//               printf ( "Switch: %i 1->0,",alea );
               do{
                  alea2=floor((float)selective*dice()); /* seleccionem un element de la llista d'uns a l'atzar */
                  if(r[selective_list[alea2]]){    /* si encara val 1 (no s'ha modificat des de l'original) */
                     r[selective_list[alea2]]=0;   /* l'invertim */
                     mark=1;                       /* i marquem final del do while */
//                     printf ( " %i 0->1\n",selective_list[alea2] );
                  }
               }while(!mark);                   /* repetim fins que trobem un 1 verge */
            }
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
