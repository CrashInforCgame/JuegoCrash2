#include "Caja.h"
#include "glut.h"

Caja::Caja()
{
	lado=1.0f;
}
Caja::~Caja()
{

}
void Caja::Dibuja()
{
	glColor3ub(0,0,200);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidCube(lado);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);
}
void Caja::SetPos(float x, float y, float z){
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}