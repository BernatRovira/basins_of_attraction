#include"../header.h" // aqui van tots els fitxers i coses
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  yesno
 *  Description: asks for y/n returns 1/0 
 * =====================================================================================
 */
   int
yesno ( void )
{
   printf ( "<y/n>?\n" );
   char answer;
   scanf("%c",&answer);
   if(answer=='y')
      return 1;
   else if(answer=='n')
      return 0;
   else{
      printf ( "Unrecognized option. Stopping\n" );
      exit(EXIT_FAILURE);
   }
}				/* ----------  end of function main  ---------- */
