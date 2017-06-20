#pragma once

class Vector3D
{
public:		//atributos
	float x;
	float y;
	float z;
public:		//metodos
	float modulo();			   // (2) modulo del vector
	Vector3D unitario();		   // (4) devuelve un vector unitario
	float angulo_con_vector(Vector3D v);		   // Da el angulo entre ese vector y otro
	Vector3D pvectorial(Vector3D v);	//Producto vectorial de ese vector
	// con otro que pasamos como parametro, lo usaremos para sacar
	// el vector normal a los planos
	Vector3D(float xv=0.0f,float yv=0.0f, float zv=0.0f); // (1)
	Vector3D operator - (Vector3D &); // (5) resta de vectores
	Vector3D operator + (Vector3D &); // (6) suma de vectores
	float operator *(Vector3D &); // (7) producto escalar
	Vector3D operator *(float); // (8) producto por un escalar 
};
