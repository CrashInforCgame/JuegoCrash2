#include "Monstruo.h"





Monstruo::Monstruo(void)
{
}


Monstruo::~Monstruo(void)
{
}
void Monstruo::Dibuja()
{
	glColor3ub(color[0],color[1],color[2]);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);
}
