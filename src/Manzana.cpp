#include "Manzana.h"


Manzana::Manzana(void)
{
	radio= 0.25f;
	estado=2;
}
Manzana::Manzana(float x, float z, float y)
{
	radio= 0.25f;
	estado=2;
	SetPos(x,y,z);
}

Manzana::~Manzana(void)
{
}
void Manzana::Dibuja() 
{
	glColor3ub(255,45,0);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);

}
void Manzana::SetPos(float x, float y, float z)
{
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}
void Manzana::Mueve(float t)
{
	//ESTADOS DECRECE 1 CRECE 2
	if(radio>0.3) estado=1;
	
	if(radio<0.2) estado=2; 

	switch(estado)
	{
	case 1:
		radio-=t*0.075;
		break;
	case 2:
		radio+=t*0.075;
		break;
	}
};