/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  fill_a
 *  Description:  fills the adjacency matrix for excitatory neurons 
 * =====================================================================================
 */
#include"../header.h" // aqui van tots els fitxers i coses
   void
fill_ad ( void )
{
//   int i,j,mu;

//   for ( i=0; i<N; i++ ) {
//      for ( j=0; j<N; j++ ) {
//         if(p>(float)rand()/(float)RAND_MAX)    /* activem amb probabilitat p */
//            a[i*N+j]=1;      
//      }
//   }
//   
//
//   for ( i=0; i<N; i++) {
//      a[i*N+i]=0;                               /* eliminem les autoconnexions */
//   }
//


   int i;
   float dum=0;
   for ( i=0; i<N; i++ ) {
      ad[i]=1;
      old_ad[i]=1;
      dum+=ad[i];
   }
   
   if( dum != (N) ){
      printf ( "\nADAPTATION VARIABLE HAS HOLES\nSUM=%f/%i\t%f/1",dum,N,dum/((float)N) );
      espera
   }

   return ;
}		/* -----  end of function fill_a   ----- */
