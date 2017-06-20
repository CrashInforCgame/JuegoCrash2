#include "ListaMonstruos.h"


ListaMonstruos::ListaMonstruos(void)
{
	numero=0;
	for(int i=0;i<MAX_MONSTRUOS;i++)
	{
		lista[i]=0;
	}
}


ListaMonstruos::~ListaMonstruos(void)
{
}
bool ListaMonstruos::agregar (Monstruo *e)
{
bool repetido=0;
	for(int i=0;i<numero;i++)
	{
		if(e==lista[i]) repetido = 1;
	}
	if(numero<MAX_MONSTRUOS && !repetido)
		lista[numero++]=e;
	else
		return false;
	return true;
}
void ListaMonstruos::Dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->Dibuja();
}
void ListaMonstruos::Mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->Mueve(t);
}

void ListaMonstruos::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	numero=0;
}

void ListaMonstruos::eliminar(int index)
{
	if((index<0)||(index>=numero))
	return;
	delete lista[index];
	numero--;
	for(int i=index;i<numero;i++)
	lista[i]=lista[i+1]; //Esto esta bien porque hace retroceder a los siguientes elementos para llenar el hueco
}

void ListaMonstruos::eliminar(Monstruo *e)
{
	for(int i=0;i<numero;i++)
	if(lista[i]==e)
	{
		eliminar(i);
		return;
	}
}
bool ListaMonstruos::choque(Personaje &h)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::choque(h,*(lista[i])))
			return true;
	}
	return 0; //no hay colisión
}

Monstruo * ListaMonstruos::ataque(Personaje &h)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::ataque(h,*(lista[i])))
		{
			return lista[i];
		}
	}
		return 0;
}
Monstruo *ListaMonstruos::operator [](int i)
{
	if(i>=numero)//si me paso, devuelvo la ultima
		i=numero-1;
	if(i<0) //si el indice es negativo, devuelvo la primera
		i=0;
	return lista[i];
}

void ListaMonstruos::operator+=(Monstruo *m)
{
	agregar(m);
}