/*
 * =====================================================================================
 *
 *       Filename:  variables.h
 *
 *    Description:  Variables global del programa.
 *    Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *    Organization:  UPF-CRM
 *
 * =====================================================================================
 */
/*-----------------------------------------------------------------------------
 *  VARIABLES EXTERNAL 
 *-----------------------------------------------------------------------------*/
//
//       Aqui es declaren com extern totes les variables "globals"
//       Despres es tornen a declarar al fitxer del main, pero FORA
//       del main. Representa que es la millor manera de fer-ho pero
//       no estic molt segur del perque. Finalment es defineixen,
//       fora o dins del main, no importa -es pot redeclarar i
//       definir un altre cop a la vegada-.
//

///////////////////// MODEL PARAMETERS
//////// INDEPENDENT
extern int N;                 // Network size
extern float gama;            // Sigmoid steepness
extern float beta;            // Coding level constant
extern float theta;           // Excitatory threshold
extern float w_EI;            // Synaptic efficacy of I to E connections. In [0,1]
extern float t_R,U;
//////// FUNCTION OF OTHERS
extern float f;               // Coding level.
extern float q_,q_10,q_01;    // Depression probability.

///////////////////// MODEL VARIABLES 
extern float *r;              // Vector of firing rates (neural output)
extern float *h;              // Vector of synaptic currents (neural input)
extern int *pattern;          // Matrix of patterns (Vector of vectors)
extern float *w;              // Synaptic connectivity matrix
extern float *ad,*old_ad;
extern float *eta,*eta_old,t_N;                 /* correlated noise variable */
extern float sigma;

///////////////////// ITERATION PARAMETERS
extern float T,dt;            // Time and time differential
extern int L;                 // System load (patterns learnt)
extern int hamming;           // hamming distance for IC
extern float **results;

///////////////////// OTHER VARIABLES
extern int debug;             /* debugging variable */
extern FILE* data;            /* dades del programa */
