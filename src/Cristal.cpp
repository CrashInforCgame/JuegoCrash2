#include "Cristal.h"

//////
Cristal::Cristal(void)
{
	radio= 0.25f;
	estado=2;
}
//hola
Cristal::Cristal(float x, float z, float y)
{
	radio= 0.25f;
	estado=2;
	SetPos(x,y,z);
}

Cristal::~Cristal(void)
{
}

void Cristal::operator+=(Cristal *m)
{
	cristal=m;
}
void Cristal::destruircristal(){
	delete cristal;
}
void Cristal::Dibuja() 
{
	glColor3ub(200,120,0);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);

}
void Cristal::SetPos(float x, float y, float z)
{
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}
void Cristal::Mueve(float t)
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