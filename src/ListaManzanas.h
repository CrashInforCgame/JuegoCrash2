#pragma once
#include "Manzana.h"
#include "Personaje.h"
#include "Interaccion.h"
#define MAX_MANZANAS 120

class ListaManzanas
{
public:
	ListaManzanas(void);
	~ListaManzanas(void);
	bool agregar (Manzana *m);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Manzana *m);
	Manzana* choque(Personaje &h);
	Manzana * operator [](int i);
	int getNumero(){return numero;}
	void operator+=(Manzana *);
private:
	Manzana* lista[MAX_MANZANAS];
	int numero;
};
