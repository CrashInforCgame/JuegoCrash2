#pragma once
#include "Vector3D.h"

class Caja
{
protected:
	float lado;
	float masa;
	Vector3D posicion;
public:
	Caja();
	virtual ~Caja();
	void Dibuja(void);
	void SetPos(float x, float y, float z);

	friend class Interaccion;

};