#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  overlap
 *  Description:  calcula l'overlap del sistema respecte l'estat "number" 
 * =====================================================================================
 */
   float
overlap ( int number )
{
   int j;
   float magnet=0;

   for ( j=0; j<N; j++ ) {
      magnet+=(float)sigmoid(gama,h[j])*((float)pattern[j+N*number]-f);   /* formula 2.6 romani 13 */
//      magnet+=(float)r_E[j]*(float)pattern[j+N*number];   /* overlap directe */
  }

   return magnet/( (float)N*f*(1-f) );                 /* 2.6 romani13 */
//   return magnet/( (float)N*f );                 /* overlap directe */

}		/* -----  end of function overlap  ----- */
