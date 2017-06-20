#pragma once
#include "Monstruo.h"

class MonstruoSalto : public Monstruo
{
public:
	MonstruoSalto(float x, float y, float z, float ampli=3);
	MonstruoSalto(void);
	~MonstruoSalto(void);
	void Mueve(float);
	void SetPos(float x, float y, float z, float a=0);
private:
	float contador; // para contar tiempo en reposo para luego saltar
};

