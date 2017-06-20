#include "Interaccion.h"
#include "Escenario.h"
#include "math.h"


Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{

}


bool Interaccion::rebotecaja(Personaje &h, Caja c)
{
	float xmin=c.posicion.x-c.lado/2-h.radio;
	float xmax=c.posicion.x+c.lado/2+h.radio;
	float zmin=c.posicion.z-c.lado/2-h.radio;
	float zmax=c.posicion.z+c.lado/2+h.radio;
	float ymax=c.posicion.y+c.lado/2+h.radio;
	
	float x=h.posicion.x;
	float y=h.posicion.y;
	float z=h.posicion.z;


	if((z>zmin && z<zmax) && (x>xmin && x<xmax))
		{
			if(ymax>=h.posicion.y)  // En caso de estar a la altura de la caja, ya estando en los limites establecidos de x y z
				// si no no se activan colisiones
			{
				if((c.posicion.x)>(x+h.radio))h.posicion.x=xmin;
				if((c.posicion.x)<(x-h.radio))h.posicion.x=xmax;
				if((c.posicion.z)>(z+h.radio))h.posicion.z=zmin;
				if((c.posicion.z)<(z-h.radio))h.posicion.z=zmax;
				if((c.posicion.y)<(y-h.radio))h.posicion.y=ymax; // Para que caiga encima de la caja si esta entre los limites y su y encima de ella
				// Como antes se activan todos los limitadores de posicion nunca va a meterse el personaje dentro de una caja por error
				return true;
			}
		}
	return false;
	
}
void Interaccion::rebote(Personaje &h, Suelo *s) //FUNCION PLANTEADA PARA TODO
{
		float xmax=s->limite4.x;
		float xmin=s->limite1.x;
		//float yplano=s.Ypuntoplano(h); // Esta funcion nos da la Y DEL PLANO EN ESA COORDENADA para que no caiga
		//float ypersonaje=yplano+h.radio; //PARA QUE SE VEA EL RADIO ENTERO LUEGO
		float ypersonaje=s->limite2.y+h.radio;
	// float ymin=s.limite1.y; // ESTO FUNCIONA SIEMPRE QUE SEAN PLANOS CON Y CONSTANTE SOLO
		float zmax=s->limite2.z;
		float zmin=s->limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
	// if(h.posicion.y<ymin)h.posicion.x=ymin; //PARA LA Y
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
		//if(ypersonaje>h.posicion.y)h.posicion.y=ypersonaje;  //PARA QUE NO SE CAIGA DEL PLANO Y SE VEA LA ESFERA ENTERA
		if((h.posicion.y-h.radio<=s->limite2.y))h.posicion.y=h.radio+s->limite2.y;
		// YPERSONAJE está cogido como la y del plano + el radio
		//if(ypersonaje>h.posicion.y)h.posicion.z=s.limite1.z;
}

void Interaccion::apoyo(Personaje &h, Escenario e)// se puede optimizar con un contenedor
{
	if(Interaccion::localizacion2(h,e))
	{
		h.apoyo=-10;
	}
	else
	{
		for(int i=0;i<e.numero;i++)
		{
			if(e.plano==i)
			{
				h.apoyo=e.lista[i]->limite2.y;
				return;
			}
		}
	}
}


bool Interaccion::localizacion(Personaje &h, Suelo *s)
{
	if((s->limite1.x)<=h.posicion.x && (s->limite4.x)>=h.posicion.x 
		&& (s->limite1.z)<=h.posicion.z && (s->limite2.z)>=h.posicion.z)
		return 1;
	return 0;
}
bool Interaccion::localizacion2(Personaje &h, Suelo *s) //Para planos con altura
{
	if((s->limite1.x)<=h.posicion.x && (s->limite4.x)>=h.posicion.x 
		&& (s->limite1.z)<=h.posicion.z && (s->limite2.z)>=h.posicion.z
		&& (s->limite1.y+h.radio)<=(h.posicion.y))
		return 1;//Si está en este plano devuelve un 1
	return 0;
}


bool Interaccion::localizacion2(Personaje &h,Escenario &e)
{
	for(int i=0;i<e.numero;i++)
	{
		if(Interaccion::localizacion2(h,e.lista[i])){e.plano=i;return 0;}//si está en este plano devuelve un cero y e.plano sabe donde está
	}
	return 1;
}
void Interaccion::rebote(Personaje &h, Escenario &e)
{
	if(Interaccion::localizacion2(h,e))//si es true es porque no esta en ningun plano y se aplican condiciones del e.plano donde estaba
	{
		for(int i=0;i<e.numero;i++)
		{
			if(e.plano==i)
			{
				Interaccion::rebote(h,e.lista[i]);
				return;
			}
		}
	}
}

bool Interaccion::choque(Personaje &h, Monstruo &m)
{
	float distancia=(h.posicion-m.posicion).modulo(); 

	if(distancia < h.getRadio()+m.getRadio()) 
		{
			return true;
		}
	return false;

}

bool Interaccion::choque(Personaje &h, Manzana &n)
{
	float distancia=(h.posicion-n.posicion).modulo(); 

	if(distancia < h.getRadio()+n.getRadio()) return true;
	return false;

}
bool Interaccion::ataque(Personaje &h, Monstruo &m) // es como el 
	//choque pero esta se activara a una distancia inferior
	// y dentro del keypressed
{
	float distancia=(h.posicion-m.posicion).modulo(); 
	if(distancia < h.getRadio()+m.getRadio()+0.16) 
	{
			return true;
	}
	return false;
}


