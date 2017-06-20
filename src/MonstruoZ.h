#pragma once
#include "Monstruo.h"

class MonstruoZ : public Monstruo
{
public:
	MonstruoZ();
	MonstruoZ(float x, float y, float z, float ampli=10);
	virtual ~MonstruoZ(void);
	void Mueve(float);
	void SetPos(float x, float y, float z, float ampli=10);
private:
};

