#pragma once
#include "MonstruoZ.h"
#include "randomnum.h"
MonstruoZ::MonstruoZ()
{
	radio=1.5f;
	estado=random(1,2); //GENERO ALETORIEDAD EN EL ESTADO INICIAL 
	posicion.x=posicion.y=posicion.z=0;
	color[0]=0;
	color[1]=255;
	color[2]=3;

}
MonstruoZ::MonstruoZ(float x, float y, float z, float ampli)
{
	radio=1.5f;
	estado=random(1,2); //GENERO ALETORIEDAD EN EL ESTADO INICIAL 
	posicion.x=posicion.y=posicion.z=0;
	color[0]=0;
	color[1]=255;
	color[2]=3;
	SetPos(x,y,z,ampli);

}

MonstruoZ::~MonstruoZ(void)
{
}


void MonstruoZ::SetPos(float ix, float iy, float iz,float ampli)
{//ampli es la mitad del intervalo que hará el monstruo
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
	if(ampli==0)
	{
		limitestrayectoria[0]=posicion.z-5,
		limitestrayectoria[1]=posicion.z+5;
	}
	limitestrayectoria[0]=posicion.z-ampli/2,
	limitestrayectoria[1]=posicion.z+ampli/2;
}


void MonstruoZ::Mueve(float t)//Esta parte irá en la clase movimientos y habra que poner esto de forma más
							// simplificada como en lo comentado abajo
{
		if(posicion.z>limitestrayectoria[1]) estado=1;
	
		if(posicion.z<limitestrayectoria[0]) estado=2; 

		switch(estado)
		{
		case 1:
			posicion.z-=t*1.7;
			break;
		case 2:
			posicion.z+=t*1.7;
			break;
		}

}