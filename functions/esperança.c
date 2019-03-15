#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mean
 *  Description:  computes the mean of a vector
 * =====================================================================================
 */
   float
mean ( float* vector, int size )
{
   float sum=0;
   int i;

   for ( i=0; i<size; i++ ) {
      sum+=vector[i];
   }

   return sum/(float)size;
}		/* -----  end of function mean  ----- */
