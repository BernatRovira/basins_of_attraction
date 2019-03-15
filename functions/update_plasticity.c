#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  update
 *  Description:  updating of r_I,*r_E,*w by euler method
 * =====================================================================================
 */
   int
update ( void )
{
   int i,j;
   float dum=0;
   //////// EXCITATORY SYNAPTIC CURRENT (inhibitory fast dynamics assumed)
   for ( i=0; i<N; i++ ) {
      dum = 0; /* aquest comentari nomes es per dirte que ets SUBNORMAL  */
      for ( j=0; j<N; j++ ) {
//            dum += w[i*N+j]*r[j];  
            dum += old_ad[i]*old_ad[j]*w[i*N+j]*r[j];  /* SYMMETRIC SHORT TERM DEPRESSION */
//            dum += old_ad[j]*w[i*N+j]*r[j];  /* ASYMMETRIC SHORT TERM DEPRESSION */
      }

//      printf ( "h[%i]=%f dum=%f\n",i,h[i],dum );

      h[i] += dt*(dum-theta-h[i]+sigma*corr_noise(i)); /* CORRELATED NOISE */
//      h[i] += dt*(dum-theta-h[i]+sigma*gnoise()); /* GAUSSIAN WHITE NOISE */
//      h[i] += dt*(dum-theta-h[i]+0.0);              /* CONSTANT INPUT */

//      printf ( "updated h[%i]=%f\n",i,h[i] ); espera

   //////// ADAPTATION VARIABLE UPDATING
   // this is adaptation for neuron i for all connection in which it is pre-synaptic.
   // straight outta Romani Tsodyks 2015 hippocampus paper.
      ad[i] += dt*( (1-old_ad[i])/t_R -U*old_ad[i]*r[i] );
   }
   return EXIT_SUCCESS;
}		/* -----  end of function update  ----- */
