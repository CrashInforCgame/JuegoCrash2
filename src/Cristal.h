#pragma once
#include "Vector3D.h"
#include "glut.h"
class Cristal
{
public:
	Cristal *cristal;
	Cristal(void);
	Cristal(float x, float z, float y=2); // PARA CONSTRUIR CRISTAL, LA Y ESTARÁ AL FINAL, POR TANTO ES DIFERENTE A MONSTRUO
	virtual ~Cristal(void);
	friend class Interaccion;
	void Mueve(float t);
	void Dibuja();
	void SetPos(float x,float y,float z);
	float getRadio(){return radio;}
	Vector3D getPos(){return posicion;}
	void operator+=(Cristal *m);
	void destruircristal();
private:
	float radio;
	Vector3D posicion;
	int estado; // Entero que nos da el estado de si el cristal esta creciendo, decreciendo, etc
};