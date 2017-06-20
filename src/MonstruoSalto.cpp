#include "MonstruoSalto.h"


MonstruoSalto::MonstruoSalto(void)
{
	radio=1.0f;
	estado=1;
	posicion.x=posicion.y=posicion.z=0;
	color[0]=125;
	color[1]=24;
	color[2]=103;
	aceleracion.y=-5;
	velocidad.y = 5;
}
MonstruoSalto::MonstruoSalto(float x, float y, float z, float ampli)
{
	radio=1.0f;
	estado=1;
	posicion.x=posicion.y=posicion.z=0;
	color[0]=125;
	color[1]=24;
	color[2]=103;
	aceleracion.y=-5;
	velocidad.y = 5;
	SetPos(x,y,z,ampli);

}

MonstruoSalto::~MonstruoSalto(void)
{
}


void MonstruoSalto::SetPos(float ix, float iy, float iz, float a)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

void MonstruoSalto::Mueve(float t)
{
	
	if(estado==1) // estado 1 salto, estado 2 reposo
	{
		posicion.y= posicion.y + velocidad.y*t +aceleracion.y*(0.5*t*t);
		velocidad.y = velocidad.y+aceleracion.y*t;
		if(posicion.y-radio<0) estado=2;
	} 
	if(estado ==2)
	{
		/*posicion.y=radio;
		contador+=t;			
		if(contador>3) */{estado=1; contador=0; velocidad.y=5;}
	}
}

