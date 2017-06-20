#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"

class Personaje
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	//float radio;
	float masa;
	int cuenta_ataque;
	
public:
	int estado_ataque; //ESTADO DEL ATAQUE 0: nada    1: atacando    2: enfriamiento, no puedes atacar hasta que pase un tiempo 
	float radio;
	float apoyo;
	Personaje();
	Vector3D GetPos();
	float getRadio(){return radio;}
	void Dibuja(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
	void SetVel(float vy);
	void SetDesplazamientoX(float px);
	void SetDesplazamientoZ(float pz);
	void Pesaje(void);

	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;
	void ataca();
	friend class Interaccion;

};
