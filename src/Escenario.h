#pragma once
#include "Suelo.h" 
#include "Personaje.h" 
#define MAX_SUELOS 120

class Escenario
{
public:
	Suelo* lista[MAX_SUELOS];		//Lista para suelos (suelos horizontales)
	Suelo* lista2[MAX_SUELOS];		//Lista para paredes (suelos verticales)
	int numero;					    //Número para saber el numero de suelos que tenemos
	int numero2;					//Número para saber el numero de suelos que tenemos
	int plano;						//Para saber en que plano nos encontramos
public:
	Escenario();
	void Dibuja(void);
	bool agregar (Suelo *m);
	bool agregar2 (Suelo *m);
	void operator+=(Suelo *m);
	void eliminar();

friend class Interaccion;
friend class Mundo;

};
