#pragma once
#include "Vector3D.h"
#include "Personaje.h"
#include "Monstruo.h"

class MonstruoX :public Monstruo
{
public:
	MonstruoX(float x, float y, float z, float ampli=10);
	MonstruoX();
	virtual ~MonstruoX(void);
	void Mueve(float);
	void SetPos(float x, float y, float z, float ampli=10);
private:
};

