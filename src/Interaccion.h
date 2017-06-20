#pragma once
#include "Personaje.h"
#include "Escenario.h"
#include "Caja.h"
#include "Monstruo.h"
#include "Vector3D.h"
#include "Manzana.h"

class Interaccion
{
private:
public:
	Interaccion();
	virtual ~Interaccion();
	void Mueve(float t);
	static void apoyo(Personaje &h, Escenario e);
	static bool rebotecaja(Personaje &h, Caja c);
	static void rebote(Personaje &h, Suelo *s);
	static bool localizacion(Personaje &h, Suelo *s);
	static bool localizacion2(Personaje &h, Suelo *s);
	static bool localizacion2(Personaje &h, Escenario &c);
	static void rebote(Personaje &h, Escenario &e);
	static bool choque(Personaje &h, Manzana &m);
	static bool choque(Personaje &h, Monstruo &m);
	static bool ataque(Personaje &h, Monstruo &m);

};
