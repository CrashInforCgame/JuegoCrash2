#include "ListaManzanas.h"



ListaManzanas::ListaManzanas(void){
	numero=0;
	for(int i=0;i<MAX_MANZANAS;i++)lista[i]=0;
}


ListaManzanas::~ListaManzanas(void)
{
}

bool ListaManzanas::agregar(Manzana *e)
{
	for(int i=0;i<numero;i++)//para evitar que se añada una manzana ya existente
		if(lista[i]==e)
			return false;

	if(numero<MAX_MANZANAS)
	   lista[numero++]=e;
	else 
		return false;
	return true;

}

void ListaManzanas::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->Dibuja();
}

void ListaManzanas::mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->Mueve(t);
}



void ListaManzanas::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	numero=0;
}

void ListaManzanas::eliminar(int index)
{
	if((index<0)||(index>=numero))
		return;
	
	delete lista[index];

	numero--;
	for(int i=index;i<numero;i++)
		lista[i]=lista[i+1];

}

void ListaManzanas::eliminar(Manzana *e)
{
	for(int i=0;i<numero;i++)
  		if(lista[i]==e)
		{
	  		eliminar(i);
	  		return;
		}
}

/*bool ListaManzanas::choque(Personaje &h)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::choque(h,*(lista[i])))
			return true;
	}
	return 0; //no hay colisión
}*/

Manzana* ListaManzanas::choque(Personaje &h)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::choque(h,*lista[i]))
			return lista[i];
	}
	return 0; //no hay colisión

}
Manzana *ListaManzanas::operator [](int i)
{
	if(i>=numero)
		i=numero-1;
	if(i<0)
		i=0;
	
	return lista[i];
}
void ListaManzanas::operator+=(Manzana *m)
{
	agregar(m);
}
