/*
 * =====================================================================================
 *
 *       Filename:  iteration.c
 *
 *    Description:  bucle d'iteracions del sistema
 *
 *        Version:  1.0
 *        Created:  12/02/2014 10:55:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *   Organization:  UPF-CRM
 *
 * =====================================================================================
 */
#include"../header.h" // aqui van tots els fitxers i coses
   int
iteration ( float temps_inicial, float temps_final, int a )
{
   unsigned int i;
   float temps;
/************************************************************ BUCLES D'ITERACIONS ********************************************************/
   for ( temps=temps_inicial; temps<temps_final ; temps+=dt ) {
      /////////////////////////// updating currents
      update();
      /////////////////////////// updating rates
      for ( i=0; i<N; i++ ) {
         r[i]=sigmoid(gama,h[i]);
         old_ad[i]=ad[i];
      }
      /////////////////////////// storing iteration data
      for ( i=0; i<100; i++ ) {
         results[i][(int)(temps/dt)] = hamdist(r,L-1-i);
      }
   }
   return EXIT_SUCCESS;
}		/* -----  end of function iteration  ----- */

/////////////////////////// auxiliar printing
//      for ( i=0; i<N; i++ ) {
//         printf ( "%i %1.2f %+1.2f -- ",pattern[N*(L-1)+i],r[i],h[i] );
//         if( !(i%11) )
//            printf ( "\n" );
//      }
//      printf ( "\nMean rate: %f\n",mean(r,N) );
//      espera


/*
      printf ( "t=%f <r>=%f overlap=%f hamming distance:%i V=%f\n",temps,mean(r,N),overlap(L-l),hamdist(r,L-l),V );
      fprintf (data,"%f\t%f\t%f\t%i\t%f\n",temps,mean(r,N),overlap(L-l),hamdist(r,L-l),V );
 */
