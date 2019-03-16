/*
 * =====================================================================================
 *
 *       Filename:  functions.h
 *
 *    Description:  Funcions pel main.
 *    Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *    Organization:  UPF-CRM
 *
 * =====================================================================================
 */
/*-----------------------------------------------------------------------------
 *  FUNCIONS DEL SISTEMA
 *-----------------------------------------------------------------------------*/
///////////////////// STARTUP 
int   fill_patterns(int,int);      /* omplir patterns */
void  fill_ad(void);                /* start adaptation variable */
int   load_w(int);                 /* carrega la matriu de pesos sinaptics estacionaria des de fitxer */
int   fill_rates(int,int);         /* Initial Condition: unabalanced HD */
int   fill_rates_switch(int,int);  /* Initial Condition: Switch HD */
///////////////////// ITERATION
int   iteration(float, float,int); /* iteracions */
int   update(void);                /* actualitzacio r_E,r_I,w per euler */
///////////////////// AUXILIARY 
float mean(float*,int);            /* calcula la mitja d'un vector float mida int */
float overlap(int);                /* calcula l'overlap amb el pattern argument */
float energy(void);                /* calcula l'energia */
int   hamdist(float*,int);         /* calcula la distancia de hamming */
float gnoise(void);                /* genera un soroll aleatori gaussia */
float corr_noise(int);             /* genera un soroll aleatori gaussia */
///////////////////// ALTRES
int   memoria(int);                /* reserva i allibera memoria de punters i fitxers */
int   yesno(void);                 /* demana y/n i torna 1/0 */
