#pragma once
#include "Vector3D.h"
#include "glut.h"

class Monstruo
{
public:
	friend class Interaccion;
	Monstruo(void);
	virtual ~Monstruo(void);
	Vector3D GetPos(){return posicion;};
	float getRadio(){return radio;}
	void Dibuja(void);
	virtual void Mueve(float)=0;
	virtual void SetPos(float x, float y, float z, float ampli=10)=0;
protected:
	float radio;
	Vector3D posicion;
	unsigned char color[3];
	float limitestrayectoria[2];
	Vector3D velocidad;
	Vector3D aceleracion;
	int estado;
};
