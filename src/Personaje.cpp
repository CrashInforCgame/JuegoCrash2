#include "Personaje.h"
#include "glut.h"
#include "Vector3D.h"

Personaje::Personaje(void)
{
	radio=0.4f;
	apoyo=0;
	aceleracion.x=0;
	aceleracion.y=-9.8f;
	aceleracion.z=0;
	velocidad.x=0;
	velocidad.y=0;
	velocidad.z=0;
	rojo=125;
	verde=125;
	azul=34;
	posicion.x=0;
	posicion.y=4+radio;
	posicion.z=0;
}


void Personaje::SetPos(float ix, float iy, float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

void Personaje::SetVel(float vy)
{
	velocidad.y=vy;

}
void Personaje::SetDesplazamientoZ(float pz)
{
	posicion.z = posicion.z + pz;
}
void Personaje::SetDesplazamientoX(float px)
{
	posicion.x = posicion.x + px;
}

void Personaje::Dibuja()
{
	if(estado_ataque==0) glColor3ub(rojo,verde,azul);// Para el color si no ataca
	if(estado_ataque==1) glColor3ub(rojo,0,azul); // El color si ataca
	if(estado_ataque==2) glColor3ub(0,verde,255); // El color si esta en enfriamiento
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);

}

void Personaje::Mueve(float t)//Esta parte irá en la clase movimientos y habra que poner esto de forma más
							// simplificada como en lo comentado abajo
{

	posicion.y = posicion.y+velocidad.y*t+aceleracion.y*(0.5f*t*t);
	if(posicion.y>radio)
	{
		velocidad.y = velocidad.y+aceleracion.y*t;
		aceleracion.y=-5;
	} 
	/*posicion = posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad = velocidad+aceleracion*t;*/
	if((posicion.y-radio<apoyo))posicion.y=(apoyo+radio); // Para que de momento no caiga por la gravedad al vacio, hay que hacer un collider con suelos
}
void Personaje::Pesaje(void)
{
	masa=4*3,14*radio*radio;
}
Vector3D Personaje::GetPos(){return posicion;}

void Personaje::ataca()
{
	if(estado_ataque==1)
	{
		cuenta_ataque++;
		if(cuenta_ataque>50) 
		{
			estado_ataque=2;
			cuenta_ataque=0;
		}
	}
	if(estado_ataque==2)
	{
		cuenta_ataque++;
		if(cuenta_ataque>25)
		{
			estado_ataque=0;
			cuenta_ataque=0;
		}
	}

}




