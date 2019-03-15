/*
 * =====================================================================================
 *
 *       Filename:  hamming_distace.c
 *
 *    Description:  Mesura la distancia de Hamming ente dos vectors
 *
 *        Version:  1.0
 *        Created:  11/10/17 11:57:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bernat Rovira Olive, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  hamdist
 *  Description:  
 * =====================================================================================
 */
   int
hamdist ( float* estat, int patro )
{
   int distance = 0;
   float tol=1e-4;
   unsigned int i;

   for (i=0 ; i<N; i++ ) {
      if( fabs(estat[i]-(float)pattern[patro*N+i])>tol )
         distance++;
   }

   return distance;
}		/* -----  end of function hamdist  ----- */
