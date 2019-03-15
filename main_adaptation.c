/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main per energy function
 *
 *    Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *    Organization:  UPF-CRM
 *
 * =====================================================================================
*/
#include"./header.h" // Llibreries necessaries pel programa
///////////////////// MODEL PARAMETERS
//////// INDEPENDENT
int N;               // Network size
float gama;          // Sigmoid steepness
float beta;          // Coding level constant
float theta;         // Excitatory threshold
float w_EI;          // Synaptic efficacy of I to E connections. In [0,1]
float t_R=800,U=0.05;
//////// FUNCTION OF OTHERS
float f;             // Coding level.
float q_,q_01,q_10;  // Depression probability.
///////////////////// MODEL VARIABLES 
float *r;            // Vector of firing rates (neural output)
float *h;            // Vector of synaptic currents (neural input)
int *pattern;        // Matrix of patterns (Vector of vectors)
float *w;            // Synaptic connectivity matrix
float **results,**count;
float *ad,*old_ad;
float *eta,*eta_old,t_N=1;                 /* correlated noise variable */
float sigma=1.00;
///////////////////// ITERATION PARAMETERS
float T,dt;          // Time and time differential
int L;               // System load (patterns learnt)
int ham;             // hamming distance for IC
///////////////////// OTHER VARIABLES
int debug;           /* debugging variable */
FILE* data;          /* dades del programa */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

   int
main ( int argc, char *argv[] )
{
/************************************************************** STARTUP PARAMETRES **********************************************************/
   ////////////////// Fixed parameters
   N      = atoi((char*)argv[1]);                /* 'N': nombre total de neurones */
   gama   = atof((char*)argv[2]);                /* 'gamma': sigmoid steepness*/
   beta   = atof((char*)argv[3]);                /* 'beta': coding level parameter */
   theta  = atof((char*)argv[4]);                /* 'theta': excitatory threshold */
   T      = atof((char*)argv[5]);                /* 'T':  total a simular */
   dt     = atof((char*)argv[6]);                /* 'dt':  interval de temps */
   ham    = atoi((char*)argv[7]);                /* 'ham': hamming distance for IC */
   ////////////////// Function parameters
   f  = beta*log((float)N)/(float)N;             /* 'f': Coding level */
//   q_10   = f/2.0;                               /* 'q_10': DEP prob w (1,0) */
//   q_01   = f/2.0;                               /* 'q_01': DEP prob w (0,1) */
//   q_ = q_10+q_01;                               /* 'q_': Depression probability */
   L  = (int)round(log(1e-4)/log(1-2*f*f+f*f*f) ); /* 'L': System load (patterns learnt) */
//   w_EI   = 1/(2-f);                             /* 'w_EI': I to E synaptic efficacy, in [0,1] */

   w_EI = 0.0;

   q_=2.57*f/(1-f);
   q_01=q_/2;
   q_10=q_/2;
   float g  = 1/(1+f*(1-f)*q_/(f*f));
   float gp = g+(1-g)*exp(-0.14/g);

//   theta = N*f*gp;
//   beta=1/phi(g,gp);
   printf ( "g=%f gp=%f theta= %f beta=%f\n",g,gp,theta,beta ); 



   w_EI = gp;

   printf ( "PARAMETERS:\n"
        "N=%i\n"
        "gama=%.2f\n"
        "beta=%1.2f\n"
        "theta=%1.2f\n"
        "T=%.0f\n"
        "dt=%0.3f\n"
        "f=%0.5f\n"
        "q_10=%0.5f\n"
        "q_01=%0.5f\n"
        "q_=%0.5f\n"
        "L=%i\n"
        "w_EI=%.5f\n"
        "ham dist for IC: %i\n"
        "Neurons activated: %i\n",N,gama,beta,theta,T,dt,f,q_10,q_01,q_,L,w_EI,ham,(int)round((float)N*f)); fflush(stdout);
/************************************************************** INICIALITZACIO DEL SISTEMA **************************************************/
   memoria(1);                                  /* reserva de memoria pels punters i creacio dels fitxers */
   srand(time(NULL));                           /* inicialitzem la llavor de nombres aleatoris amb el temps del PC */
/************************************************************** BUCLE D'ITERACIONS **********************************************************/
   ////////////////// STARTUP OPERATIONS
   ////////////////////// TRYING BEHAVIOR

   int age = 1;//round(0.14/powf(f,2));            /* nombre de patrons a provar */
   int age_intrvl = 30;
   int rlzt = 1;                               /* nombre de realitzacions de la matriu */
   int iter = 1;                               /* repeticions per rlzt,age,ham */
//   float tol=0.001;
   int maxham = 1;//(int)round((float)N*f);//ham            /* distancia de hamming maxima */
   unsigned int rl,j, a,i,it;
 

   for ( rl = 0; rl<rlzt;rl++ ){                /* rlzt: realitzacions de la la matriu */
      for ( j=0; j<N*L; j++ ) {
         pattern[j]=0;
      }
      fill_patterns(0,L);                         /* omplir patterns, 1 des de fitxer, 0 les crea */
      printf ( "Patterns generated. Loading weights. Rlzt: %i/%i\n",rl,rlzt ); 
      for ( j=0; j<N*N; j++ ) {
         w[j]=0;
      }
      load_w(0);                                 
      printf ( "Synaptic connectivity matrix loaded.\n"  ); 
      for (a=0 ; a<age; a+=age_intrvl ) {               
         printf ( "Testing pattern age %i/%i\n",a,age ); 
         for ( ham=0; ham<maxham; ham++ ) {     /* ham: dist ham de la IC */
            printf ( "Testing distance %i/%i\n",ham,maxham ); 
            for (it=0 ; it<iter; it++ ) {
               printf ( "%i/%i\r",it,iter ); 
               //fill_rates(L-a-1,ham); // per unbalanced HD
               fill_rates_switch(L-a-1,ham);           /* quan comptem al reves cal restar una unitat extra ja que L+i esta fora de memoria */
               fill_ad();                               /* start adaptation variable */
               iteration(0,T,a);
            }
         }
      }

   }

    
   for ( i=0; i<100; i++ ) {
      for (j=0 ; j<(int)(T/dt); j++ ) {
         fprintf(data,"%f\t",results[i][j]);
      }
      fprintf(data,"\n");
   }

   ////////////////// SAVE THE WHALES, FREE THE MALLOCS
//   for ( i=0; i<N; i++ ) {
//         printf ( "%i %1.3f %+1.2f -- ",pattern[N*(L-1)+i],r[i],h[i] );
//         if( !(i%11) )
//            printf ( "\n" );
//   }
//   printf ( "\nMean rate: %f\n",mean(r,N) );
   memoria(0);                                  /* alliberament de punters de variables i fitxers */
   exit(EXIT_SUCCESS);
}				/* ----------  end of function main  ---------- */

/*
   unsigned int i;
 do{
   printf ( "Introduce desired hamming distance\n" );
   scanf("%i",&ham);
   fill_rates(L-1,ham);                           

   float tol=0.001;

   for ( i=0; i<N; i++ ) {
      printf( "%1i%1.0f|",pattern[(L-1)*N+i],r[i]);
      if( fabs((float)pattern[(L-1)*N+i]-r[i])>tol)
         printf ( "<---SWITCH: %i %f \n",pattern[(L-1)*N+i],r[i] );
   }
   printf ( "\nMean rate: %f\n",mean(r,N) );
   anykey

   iteration(0,T);

   printf ( "\n" );
   printf ( "Do you want to iterate again w/ same matrix?\n" );
 }while(yesno());  
*/
