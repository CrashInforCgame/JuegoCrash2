#include "Suelo.h"
#include "glut.h"
#include "math.h"
#include "ETSIDI.h"
#include <stdlib.h>


void Suelo::setColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}

Suelo::Suelo(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3, float z3,float x4, float y4, float z4)
{
	SetPos(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4);
	setColor(150,50,0);
}
void Suelo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x,limite1.y,limite1.z);
	glVertex3d(limite2.x,limite2.y,limite2.z);
	glVertex3d(limite3.x,limite3.y,limite3.z);
	glVertex3d(limite4.x,limite4.y,limite4.z);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Suelo::Dibuja2()
{/*
	glEnable(GL_TEXTURE_2D);
  
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes1/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	
	glTexCoord2d(0,1);		glVertex3f(limite1.x,limite1.y,limite1.z);
	glTexCoord2d(1,1);		glVertex3f(limite2.x,limite2.y,limite2.z);
	glTexCoord2d(1,0);		glVertex3f(limite3.x,limite3.y,limite3.z);
	glTexCoord2d(0,0);		glVertex3f(limite4.x,limite4.y,limite4.z);
	glEnd();

	glEnable(GL_LIGHTING);	
	glDisable(GL_TEXTURE_2D);
	*/
}

void Suelo::SetPos(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3,
				   float z3,float x4, float y4, float z4)
{
	limite1.x=x1;
	limite1.y=y1;
	limite1.z=z1;
	limite2.x=x2;
	limite2.y=y2;
	limite2.z=z2;
	limite3.x=x3;
	limite3.y=y3;
	limite3.z=z3;
	limite4.x=x4;
	limite4.y=y4;
	limite4.z=z4;

}
Vector3D Suelo::v_distancia_plano(Personaje &h)  // Este nos da el vector de la distancia mas corta entre el personaje y el plano
{
	Vector3D Pos_personaje = h.GetPos();
	Vector3D pnj_plano = Pos_personaje-limite1; 
	Vector3D v_plano1= limite1-limite2;
	Vector3D v_plano2= limite1-limite3;
	Vector3D normal = v_plano1.pvectorial(v_plano2).unitario(); // Aqui sacamos la normal al plano
	Vector3D v_distancia = normal*(pnj_plano*normal);
	return v_distancia;
}

float Suelo::distancia_plano(Personaje &h){ // Hallamos el vector normal al plano haciendo el producto vectorial de dos vectores que estan en este y normalizando
	// Luego hallamos un vector que vaya del personaje a un punto del plano (Cogemos algun punto limite1 o limite2 de esos)
	// Por ultimo proyectamos ese vector sobre la normal al plano para tener la distancia (Producto escalar)
	
    Vector3D Pos_personaje = h.GetPos();
	Vector3D pnj_plano = Pos_personaje-limite1; 
	Vector3D v_plano1= limite1-limite2;
	Vector3D v_plano2= limite1-limite3;
	Vector3D normal = v_plano1.pvectorial(v_plano2).unitario(); // Aqui sacamos la normal al plano
	float distancia = abs(pnj_plano*normal);
	return distancia;
}
//ESTA VERSION QUE ESTA ENTRE CORCHETES SOLO FUNCIONA PARA PLANOS CON Y CONSTANTE, CON RAMPAS NO FUNCIONA BIENHAY UN FALLO AL PLANTEARLO

float Suelo::Ypuntoplano(Personaje &h) // Para obtener el punto del plano sobre el que el personaje luego proyecta en Y    
		// Podría servir para saber el punto donde tenemos que dejar el personaje si este se mueve por un plano inclinado
{
	Vector3D Pos_personaje = h.GetPos();
	Vector3D pnj_plano = Pos_personaje-limite1; 
	Vector3D v_plano1= limite1-limite2;
	Vector3D v_plano2= limite1-limite3;
	Vector3D normal = v_plano1.pvectorial(v_plano2).unitario(); // Aqui sacamos la normal al plano
	Vector3D Ny(0,1,0); // Proyectaremos sobre Y para saber la distancia entre nuestro personaje y la proyeccion en el plano con la misma Y que el personaje
	Vector3D dist_pnj_plano = Ny*(pnj_plano*Ny);
	Vector3D puntoplano = Pos_personaje-dist_pnj_plano; // Debería dar el punto Y donde dejaremos fijo ya al personaje
	float puntoY= puntoplano.y;
	return puntoY;
}

 //ESTE ÚLTIMO DEBERÍA FUNCIONAR PERO DA MUCHOS FALLOS EN LA CAMARA, POR TANTO LO DEJAMOS COMENTADO Y PREGUNTAMOS ALGUN DIA EN TUTORIA

/*
float Suelo::Ypuntoplano(Personaje &h) 

{
	Suelo estesuelo= *this;
	Vector3D distancia_plano = estesuelo.v_distancia_plano(h);
	Vector3D Ny(0,1,0);
	float a= Ny*distancia_plano;
    float angulo = distancia_plano.angulo_con_vector(Ny);
	float dist = estesuelo.distancia_plano(h);
	float distancia_y = abs(dist/cos(angulo));
	return distancia_y;
}
*/

