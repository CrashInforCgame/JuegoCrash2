#pragma once
#include "Vector3D.h"
#include "Personaje.h"

class Suelo
{
public:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	
	Vector3D limite1;
	Vector3D limite2;
	Vector3D limite3;
	Vector3D limite4;

	//bool vacio;// atributo para determinar si el plano es un suelo de poyo o de caida al vacio
public: 	
	Suelo():rojo(150),azul(0),verde(50) {}
	Suelo(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3, float z3,float x4, float y4, float z4);
	void Dibuja();//Para poder compaginar los limites y que 
							//el extremo del personaje no pase la pared
	void Dibuja2();
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void SetPos(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3,
				 float z3,float x4, float y4, float z4);
	Vector3D v_distancia_plano(Personaje &h); //El vector entre el personaje y el plano con dstancia minima
	float distancia_plano(Personaje &h); // Halla distancias al plano
	float Ypuntoplano(Personaje &h); // Para obtener la Y del punto del plano sobre el que el personaje luego proyecta en Y
		// Podría servir para saber el punto donde tenemos que dejar el personaje si este se mueve por un plano inclinado
	friend class Interaccion;
};

