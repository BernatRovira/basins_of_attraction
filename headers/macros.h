/*
 * =====================================================================================
 *
 *       Filename:  macros.h
 *
 *    Description:  Macros especials.
 *    Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *    Organization:  UPF-CRM
 *
 * =====================================================================================
 */
/*-----------------------------------------------------------------------------
 *  MACROS 
 *-----------------------------------------------------------------------------*/
#define debug(a)     printf("debug %i\n",a);fflush(stdout); /* missatge per pantalla, debugging */
#define espera       while(getchar() != '\n');              /* pausa, per debugging */
#define GNUPLOT_PATH "/usr/bin/gnuplot"                     /* definim la ruta cap al gnuplot */
#define sigmoid(a,b) (1/(1+exp(-a*b)))                      /* sigmoid pel neural output */
#define dice()       ((float)rand()/(float)RAND_MAX)        /* rnd number in [0,1] */
#define anykey       printf("press any key");espera         /* missatge per pantalla: press any key */
#define phi(x,y)     y*log(y/x)+(1-y)*log((1-y)/(1-x))       /* phi(x,y) a dubreil 14 */
