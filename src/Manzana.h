#pragma once
#include "Vector3D.h"
#include "glut.h"
class Manzana
{
public:
	Manzana(void);
	Manzana(float x, float z, float y=0.3); // PARA CONSTRUIR MANZANA, LA Y ESTARÁ AL FINAL, POR TANTO ES DIFERENTE A MONSTRUO
	virtual ~Manzana(void);
	friend class Interaccion;
	void Mueve(float t);
	void Dibuja();
	void SetPos(float x,float y,float z);
	float getRadio(){return radio;}
	Vector3D getPos(){return posicion;}
private:
	float radio;
	Vector3D posicion;
	int estado; // Entero que nos da el estado de si la manzana esta creciendo, decreciendo, etc
};

