/*
 * =====================================================================================
 *
 *       Filename:  energy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/09/17 00:27:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  energy
 *  Description:  
 * =====================================================================================
 */
   float
energy ( void )
{
  float Vrec=0,Vext=0,Vleak=0, tol=0.0001;
  unsigned int i,j;
  for ( i=0; i<N; i++ ) {
     Vext += r[i];                             /* V de l'input extern */
     Vleak += (r[i]<tol) ? 0                     /* V del leak term */
                      : (r[i]>1-tol) ? 0
                                  : log(1-r[i])-r[i]*log(1/r[i]-1); 
//     if( isinf(Vleak) ){
//        printf ( "Vleak INF! r[%i]=%f\n",i,r[i] ); anykey
//     }
     for ( j=0; j<N; j++ ) {
         Vrec += w[i*N+j]*r[i]*r[j];           /* V recursiu */
     }
  }
//  printf ( "Vext=%f Vleak=%f Vrec=%f\n",Vext,Vleak,Vrec ); //anykey
   return -Vrec/2+Vext*theta/((float)N*f)+Vleak/gama; /* V final amb constants */
}		/* -----  end of function energy  ----- */
