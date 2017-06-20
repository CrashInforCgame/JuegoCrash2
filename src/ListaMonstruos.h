#pragma once
#include "Monstruo.h"
#include "Interaccion.h"
#include "Personaje.h"
#define MAX_MONSTRUOS 40
class ListaMonstruos
{
public:
public:
	ListaMonstruos(void);
	~ListaMonstruos(void);
	bool agregar (Monstruo *e);
	void Dibuja();
	void Mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Monstruo *e);
	bool choque(Personaje &h);
	Monstruo* ataque(Personaje &h);
	Monstruo * operator [](int i);
	int getNumero(){return numero;}
	void operator+=(Monstruo *);
private:
	Monstruo * lista[MAX_MONSTRUOS];
	int numero;
};

