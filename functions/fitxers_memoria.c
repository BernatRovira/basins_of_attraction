#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  memoria
 *  Description:  stores and frees memory space for all pointers
 * =====================================================================================
 */
   int
memoria ( int load )
{
   unsigned int i;
   if(load){
      char string[50];
      sprintf(string,"data_adapt");    /* omplim la cadena amb el nom del fitxer */
      data  = fopen(string,"w");        /* obrim fitxer RAW de dades */
      
      pattern     = calloc ( (size_t)(N*L), sizeof(int) ); /* mode normal amb L patterns */
      if ( pattern    == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      r         = calloc ( (size_t)(N)  , sizeof(float) );
      if ( r        == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      h         = calloc ( (size_t)(N)  , sizeof(float) );
      if ( h        == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      w	          = calloc ( (size_t)(N*N), sizeof(float) );
      if ( w          == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      
      eta	= malloc ( N*sizeof(float) );
      if ( eta        ==NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      eta_old	= malloc ( N*sizeof(float) );
      if ( eta_old    ==NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      ad           = calloc ( (size_t)(N), sizeof(float) );
      if ( ad          == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      old_ad       = calloc ( (size_t)(N), sizeof(float) );
      if ( old_ad      == NULL ) {
         fprintf ( stderr, "\ndynamic memory allocation failed\n" );
         exit (EXIT_FAILURE);
      }
      results = (float **)calloc ((size_t)(100),sizeof(float*) );
      for ( i=0; i<100; i++ ) {
         results[i] = (float*)calloc ((size_t)(T/dt),sizeof(float) );
      }
   }
   
   if(!load){   /* No load = unload */
      fclose (data);
      data      = NULL;
      free   (r);
      r           = NULL;
      free   (h);
      h           = NULL;
      free   (pattern);
      pattern       = NULL;  
      free   (w);
      w             = NULL;
      free (eta);
      eta	    = NULL;
      free (eta_old);
      eta_old	    = NULL;
      free   (ad);
      ad             = NULL;
      free   (old_ad);
      old_ad         = NULL;
      for ( i=0; i<100; i++ ) {
         free (results[i]);
         results[i]= NULL;
      }
      free (results);
      results	= NULL;
   } 

   return EXIT_SUCCESS;
}		/* -----  end of function memoria  ----- */
