#pragma once
#include "MonstruoX.h"


//COLOCO ESTE GENERADOR AQUI PORQUE AL INTENTAR INCLUIRLO DICE EL COMPILADOR DA ERROR LNK2005

int numerRand ()  // Generate a 4 digit pseudo-random integer
{
  static int next = 3251 ; // Anything you like here - but not
                           // 0000, 0100, 2500, 3792, 7600,
                           // 0540, 2916, 5030 or 3009.
  next = ((next * next) / 100 ) % 10000 ;
  return next ;
}
 
int random1 ( int min, int max )  // max-min must be <10000!!
{
  return numerRand() % (max+1-min) + min ; 
}


MonstruoX::MonstruoX()
{
	radio=1.5f;
	estado=random1(1,2); //GENERO ALETORIEDAD EN EL ESTADO INICIAL 
	posicion.x=posicion.y=posicion.z=0;
	color[0]=0;
	color[1]=255;
	color[2]=3;

}
MonstruoX::MonstruoX(float x, float y, float z, float ampli)
{
	radio=1.5f;
	estado=random1(1,2); //GENERO ALETORIEDAD EN EL ESTADO INICIAL 
	posicion.x=posicion.y=posicion.z=0;
	color[0]=0;
	color[1]=255;
	color[2]=3;
	SetPos(x,y,z,ampli);

}


MonstruoX::~MonstruoX(void)
{
}


void MonstruoX::SetPos(float ix, float iy, float iz, float ampli)
{ //ampli es la semiamplitud del limite de la trayectoria 
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
	if(ampli==0)
	{
		limitestrayectoria[0]=posicion.x-5,
		limitestrayectoria[1]=posicion.x+5;

	}
	limitestrayectoria[0]=posicion.x-ampli/2,
	limitestrayectoria[1]=posicion.x+ampli/2;
}


void MonstruoX::Mueve(float t)//Esta parte irá en la clase movimientos y habra que poner esto de forma más
							// simplificada como en lo comentado abajo
{
		if(posicion.x>limitestrayectoria[1]) estado=1;
	
		if(posicion.x<limitestrayectoria[0]) estado=2; 

		switch(estado)
		{
		case 1:
			posicion.x-=t*1.7;
			break;
		case 2:
			posicion.x+=t*1.7;
			break;
		}

}