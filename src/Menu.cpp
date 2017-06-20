#include "Menu.h"
#include "ETSIDI.h"
#include <stdlib.h>


Menu::Menu()
{
	estado=INICIO;
}
void Menu::Inicializa()
{

}
void Menu::Dibuja()
{
	if(estado==INICIO)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1,1,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("PASA EL LABERINTO", -5,8);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5,7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5,6);
		ETSIDI::printxy("Alvaro & Nacho",2,1);
	}
	else if(estado==JUEGO)
	{
		mundo.Dibuja();
	}
	else if(estado==GAMEOVER)
	{
		//mundo.Dibuja();
		gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1,1,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("GAMEOVER: Has perdido",-5,10);
		ETSIDI::printxy("Pulsa -C- para continuar",-5,5);
	}
	else if(estado==FIN)
	{
		//mundo.Dibuja();
		gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!  SUUUUU!",-5,10);
		ETSIDI::printxy("Pulsa -C- para continuar",-5,9);
	}
}

void Menu::Mueve()
{
	if(estado==JUEGO)
	{
		mundo.Mueve();
		if(mundo.getCristal())
		{
			if(!mundo.cargarNivel())//Si superas el Nivel vas al estado FIN
				estado=FIN;
		}
		if(mundo.getVidas())//Si te matan vas al estado GAMEOVER
		{
			estado=GAMEOVER;
		}
	}
}


void Menu::VariasTeclas(bool keystatus[], bool keyspecial[]) 
{
	if(estado==INICIO)
	{
		if(keystatus['e'])
		{
			mundo.Inicializa();
			estado=JUEGO;
		}
		if(keystatus['s'])
			exit(0);
		}
	else if(estado==JUEGO)
	{
		mundo.VariasTeclas(keystatus, keyspecial);
	}
	else if(estado==GAMEOVER)
	{
		if((keystatus['c']))
			estado=INICIO;
	}
	else if(estado==FIN)
	{
		if(keystatus['e'])
			estado=INICIO;
	}
}

