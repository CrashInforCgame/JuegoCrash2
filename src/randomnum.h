// he creado esta libreria porque el glut da problemas constantemente con stdlib y necesito usar numeros aleatorios
#ifndef randim
#define randim

int numeroRand ()  // Generate a 4 digit pseudo-random integer
{
  static int nexti = 3251 ; // Anything you like here - but not
                           // 0000, 0100, 2500, 3792, 7600,
                           // 0540, 2916, 5030 or 3009.
  nexti = ((nexti * nexti) / 100 ) % 10000 ;
  return nexti ;
}
 
int random ( int min, int max )  // max-min must be <10000!!
{
  return numeroRand() % (max+1-min) + min ; 
}
#endif