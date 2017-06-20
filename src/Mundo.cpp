#include "Mundo.h"
#include "Escenario.h"
#include "Caja.h"
#include"Interaccion.h"
#include "glut.h"
#include <math.h>

bool Mundo::getVidas()
{
	if(Vidas==0)
	{
		return true;
	}
	else
		return false;
}

bool Mundo::getCristal()
{
	if(escenario.plano==15)
	{
		return true;
	}
	else
		return false;
}
void inicializaMonstruos(ListaMonstruos &monstruos)  //USAREMOS ESTA FUNCION PARA INICIALIZAR LOS MONSTRUOS
	// DE ESTA MANERA ADEMAS CUANDO NOS MATEN PODREMOS VOLVER A GENERAR TODOS LOS MONSTRUOS DE NUEVO UNA VEZ DESTRUIDA LA LISTA
{
		//Inicializando monstruos para lista
	
	float y1xz=(new MonstruoZ)->getRadio()-0.3; // LA ALTURA A LA QUE ESTARAN LOS MONSTRUOS X Y Z EN EL PRIMER PLANO
	float y2xz=y1xz+3; //ALTURA 2o plano
	//Monstruos que se mueven en X
	monstruos+=new MonstruoX(0,y1xz,-17);
	monstruos+=new MonstruoX(0,y1xz,-8.5);
	monstruos+=new MonstruoX(20,y1xz,-35);
	monstruos+=new MonstruoX(10,y1xz,-50);
	monstruos+=new MonstruoX(10,y1xz,-54);

	//Monstruos que se mueven en Z
	monstruos+=new MonstruoZ(10,y1xz,-25);
	monstruos+=new MonstruoZ(15,y1xz,-25);
	monstruos+=new MonstruoZ(15,y1xz,-45);
	monstruos+=new MonstruoZ(9,y2xz,-76);
	monstruos+=new MonstruoZ(12.65,y2xz,-83);
	//Monstruos que saltan						//HACEMOS QUE CAIGAN DESDE ALTURAS DIFERENTES PARA DESINCRONIZAR LOS SALTOS
	monstruos+=new MonstruoSalto(15,y1xz+1,-26);
	monstruos+=new MonstruoSalto(-2,y1xz,-25);
	monstruos+=new MonstruoSalto(12.3,y1xz+3,-48);
	monstruos+=new MonstruoSalto(9,y1xz,-44);
	monstruos+=new MonstruoSalto(8,y1xz+5,-59);
}

void Mundo::SeguirPersonaje()
{
	x_ojo=personaje.GetPos().x + 0;
	y_ojo=personaje.GetPos().y + 4;
	z_ojo=personaje.GetPos().z + 10;  //Seguimiento cutre de camara*/

}

void Mundo::Dibuja()
{

	//Look at sin seguir al personaje

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			personaje.GetPos().x, personaje.GetPos().y, personaje.GetPos().z,      // hacia que punto mira, en 
																				   // este caso al personaje
		   //personaje.GetPos().x*0.4, 0, personaje.GetPos().z,
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) */

	//dibujo del suelo
	escenario.Dibuja();
	personaje.Dibuja();
	caja1.Dibuja();
	caja2.Dibuja();
	caja3.Dibuja();
	monstruos.Dibuja();
	escenario.Dibuja();
	manzanas.dibuja();
}

void Mundo::Mueve()
{
	personaje.Mueve(0.025f); // Con 25 ms funciona bien la gravedad

	monstruos.Mueve(0.025f);
	if(monstruos.choque(personaje)||(personaje.posicion.y<-2))
	{
		std::cout<< "HAS MUERTO" << std::endl;	//AQUI HABRIA QUE PONER QUE PASA SI TE DA
		monstruos.destruirContenido();
		inicializaMonstruos(monstruos);
		Vidas--;
		escenario.plano=0;//nivel de dificultad, te vuelve al inicio o al principio del suelo donde has muerto
		personaje.SetPos(0,personaje.radio,0);
		contador_monstruos=0; // AL RESETEARSE LOS MONSTRUOS TAMBIEN LO HACE LA CUENTA
	}
	if(personaje.estado_ataque == 1) //AQUI EL PERSONAJE REVISA LAS INTERACCIONES DE ATAQUE PARA MATAR MONSTRUOS
	{
			Monstruo *aux = monstruos.ataque(personaje);
			if(aux!=0) 
			{
				monstruos.eliminar(aux);
				contador_monstruos++;
			}
	}
	personaje.ataca(); // AQUI PERSONAJE SE ENCARGA DE SUS ESTADOS DE ATAQUE
	manzanas.choque(personaje);
	manzanas.mueve(0.025f);
	Manzana *aux=manzanas.choque(personaje); 
	if(!aux==0)
	{
		manzanas.eliminar(aux);
		contador_manzanas++;	// AUMENTA LA CUENTA DE MANZANAS
	}
	Interaccion::rebote(personaje,escenario);
	Interaccion::rebotecaja(personaje,caja1);
	Interaccion::rebotecaja(personaje,caja2);
	Interaccion::rebotecaja(personaje,caja3);
	Interaccion::apoyo(personaje, escenario);
	SeguirPersonaje(); // Desactivar para no seguirlo
	verpos_consola(); //ESTA FUNCION NOS VA DANDO LA POSICION EN CONSOLA, UTIL PARA LUEGO PONER COSAS
}

void Mundo::verpos_consola()
{
	if(contador_pos%80 == 0) { // AQUI SE AJUSTA CADA CUANTO TIEMPO QUEREMOS QUE SE ACTUALICE LA CONSOLA. MAS O MENOS 40 ES CADA 1 SEGUNDO, POR TANTO 80 ES CADA 2

		if(contador_ciclos>0)  
		{
			system("cls");
			contador_ciclos=0;
		} 

		std::cout << "Posicion personaje [X Y Z]:               "<< personaje.posicion.x << "       " << personaje.posicion.y << "      " << personaje.posicion.z << std::endl;
		std::cout << "Manzanas:       "<< contador_manzanas << std::endl;
		std::cout << "Monstruos muertos:         " << contador_monstruos << std::endl;
		std::cout << "Quedan " << monstruos.getNumero() << std::endl;
		std::cout<< c << std::endl;
		contador_pos = 0;	
		contador_ciclos++;
	}
	contador_pos++;
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;

	Nivel=0;
	Vidas=3;
	cargarNivel();

}


/*void Mundo::TeclaEspecial(unsigned char key)
{

	switch(key)
	{
	case GLUT_KEY_LEFT:
		personaje.SetDesplazamientoX(-1.0f);
		break;
	case GLUT_KEY_RIGHT:
		personaje.SetDesplazamientoX(1.0f);
		break;
	case GLUT_KEY_UP:
		personaje.SetDesplazamientoZ(-1.0f);
		break;
	case GLUT_KEY_DOWN:
		personaje.SetDesplazamientoZ(1.0f);
		break;
	}
}*/

void Mundo::VariasTeclas(bool keystatus[], bool keyspecial[])  // LA FUNCION IMPORTANTE PARA EL MOVIMIENTO
{
	if(keystatus['a'] || keystatus['A'] || keyspecial[GLUT_KEY_LEFT])personaje.SetDesplazamientoX(-0.075f);
	if(keystatus['d'] || keystatus['D'] || keyspecial[GLUT_KEY_RIGHT])personaje.SetDesplazamientoX(0.075f);
	if(keystatus['w'] || keystatus['W'] || keyspecial[GLUT_KEY_UP])personaje.SetDesplazamientoZ(-0.075f);
	if(keystatus['s'] || keystatus['S']|| keyspecial[GLUT_KEY_DOWN])personaje.SetDesplazamientoZ(0.075f);
	if(keystatus[' '] || keystatus['n'] || keystatus['N'])
	{
		if(personaje.posicion.y<=(personaje.apoyo+personaje.radio))//Solo puede dar un salto si está en el suelo
		//if(personaje.posicion.y<=personaje.radio)//Solo puede dar un salto si está en el suelo
		personaje.SetVel(6.0f);		
	}

	if(keystatus['p']||keystatus['P'])
		{
			if(personaje.estado_ataque==0) personaje.estado_ataque=1;
		}

}

bool Mundo::cargarNivel()
{
	Nivel++;
	personaje.SetPos(0,0,0);
	monstruos.destruirContenido();
	manzanas.destruirContenido();
	escenario.eliminar();

	if(Nivel==1)
	{
		FuncionInicializa();
	}
	if(Nivel==2)
	{
		FuncionInicializa();
	}
	if(Nivel==3)
	{
		FuncionInicializa();
	}
	if(Nivel<=3)
		return true;
	return false;
}

void Mundo::FuncionInicializa()
{
		if(Nivel==1)
		{
			escenario+=new Suelo(-5.0F,0,-50.0F,-5.0F,0,5.0F,5.0F,0,5.0F,5.0F,0,-50.0F);
			escenario+=new Suelo(-5.0F,-20,-55.0F,-5.0F,-20,-50.0F,5.0F,-20,-50.0F,5.0F,-20,-55.0F);
			escenario+=new Suelo(-5.0F,0,-85.0F,-5.0F,0,-55.0F,5.0F,0,-55,5.0F,0,-85.0F);

			/*inicializaMonstruos(monstruos);
			manzanas+=new Manzana(3,-10); // AL USAR NEW MANZANA AHORA LOS PARAMETROS SON: (X,Z,Y=0.3)

			caja1.SetPos(4.5,0.5,-5);
			caja2.SetPos(4.5,1.5,-5);
			caja3.SetPos(0.5,0.5,-2);*/

		}
		if(Nivel==2)
		{
			escenario+=new Suelo(-5.0F,0,-20.0F,-5.0F,0,5.0F,5.0F,0,5.0F,5.0F,0,-20.0F);
			escenario+=new Suelo(-5.0F,0,-30.0F,-5.0F,0,-20.0F,25.0F,0,-20.0F,25.0F,0,-30.0F);
			escenario+=new Suelo(15.0F,0,-50.0F,15.0F,0,-30.0F,25.0F,0,-30.0F,25.0F,0,-50.0F);
			escenario+=new Suelo(5.0F,0,-50.0F,5.0F,0,-40.0F,15.0F,0,-40.0F,15.0F,0,-50.0F);
			escenario+=new Suelo(5.0F,0,-70.0F,5.0F,0,-50.0F,15.0F,0,-50.0F,15.0F,0,-70.0F);
			escenario+=new Suelo(5.0F,3.0F,-100.0F,5.0F,3.0F,-70.0F,15.0F,3.0F,-70.0F,15.0F,3.0F,-100.0F);
			escenario+=new Suelo(15.0F,3.0F,-100.0F,15.0F,3.0F,-85.0F,50.0F,3.0F,-85.0F,50.0F,3.0F,-100.0F);
			escenario+=new Suelo(50.0F,6,-100.0F,50.0F,6,-85.0F,58.0F,6,-85.0F,58.0F,6,-100.0F);
			escenario+=new Suelo(58.0F,9.5,-100.0F,58.0F,9.5,-85.0F,74.0F,9.5,-85.0F,74.0F,9.5,-100.0F);
			escenario+=new Suelo(74.0F,8,-100.0F,74.0F,8,-85.0F,80.0F,8,-85.0F,80.0F,8,-100.0F);
			escenario+=new Suelo(80.0F,6,-100.0F,80.0F,6,-85.0F,105.0F,6,-85.0F,105.0F,6,-100.0F);
			escenario+=new Suelo(90.0F,6,-85.0F,90.0F,6,-78.0F,105.0F,6,-78.0F,105.0F,6,-85.0F);
			escenario+=new Suelo(90.0F,6,-85.0F,90.0F,6,-78.0F,105.0F,6,-78.0F,105.0F,6,-85.0F);
			escenario+=new Suelo(90.0F,2,-78.0F,90.0F,2,-68.0F,105.0F,2,-68.0F,105.0F,2,-78.0F);
			escenario+=new Suelo(90.0F,0,-68.0F,90.0F,0,-45.0F,105.0F,0,-45.0F,105.0F,0,-68.0F);
			escenario+=new Suelo(90.0F,0,-45.0F,90.0F,0,-35.0F,160.0F,0,-35.0F,160.0F,0,-45.0F);
			escenario+=new Suelo(140.0F,0,-128.0F,140.0F,0,-55.0F,160.0F,0,-55.0F,160.0F,0,-128.0F);

			inicializaMonstruos(monstruos);
			manzanas+=new Manzana(3,-10); // AL USAR NEW MANZANA AHORA LOS PARAMETROS SON: (X,Z,Y=0.3)

			caja1.SetPos(4.5,0.5,-5);
			caja2.SetPos(4.5,1.5,-5);
			caja3.SetPos(0.5,0.5,-2);
		}
		if(Nivel==3)
		{
	
			escenario+=new Suelo(-5.0F,0,-20.0F,-5.0F,0,5.0F,5.0F,0,5.0F,5.0F,0,-20.0F);
			escenario+=new Suelo(-5.0F,0,-30.0F,-5.0F,0,-20.0F,25.0F,0,-20.0F,25.0F,0,-30.0F);
			escenario+=new Suelo(15.0F,0,-50.0F,15.0F,0,-30.0F,25.0F,0,-30.0F,25.0F,0,-50.0F);
			escenario+=new Suelo(5.0F,0,-50.0F,5.0F,0,-40.0F,15.0F,0,-40.0F,15.0F,0,-50.0F);
			escenario+=new Suelo(5.0F,0,-70.0F,5.0F,0,-50.0F,15.0F,0,-50.0F,15.0F,0,-70.0F);
			escenario+=new Suelo(5.0F,3.0F,-100.0F,5.0F,3.0F,-70.0F,15.0F,3.0F,-70.0F,15.0F,3.0F,-100.0F);
			escenario+=new Suelo(15.0F,3.0F,-100.0F,15.0F,3.0F,-85.0F,50.0F,3.0F,-85.0F,50.0F,3.0F,-100.0F);
			escenario+=new Suelo(50.0F,6,-100.0F,50.0F,6,-85.0F,58.0F,6,-85.0F,58.0F,6,-100.0F);
			escenario+=new Suelo(58.0F,9.5,-100.0F,58.0F,9.5,-85.0F,74.0F,9.5,-85.0F,74.0F,9.5,-100.0F);
			escenario+=new Suelo(74.0F,8,-100.0F,74.0F,8,-85.0F,80.0F,8,-85.0F,80.0F,8,-100.0F);
			escenario+=new Suelo(80.0F,6,-100.0F,80.0F,6,-85.0F,105.0F,6,-85.0F,105.0F,6,-100.0F);
			escenario+=new Suelo(90.0F,6,-85.0F,90.0F,6,-78.0F,105.0F,6,-78.0F,105.0F,6,-85.0F);
			escenario+=new Suelo(90.0F,6,-85.0F,90.0F,6,-78.0F,105.0F,6,-78.0F,105.0F,6,-85.0F);
			escenario+=new Suelo(90.0F,2,-78.0F,90.0F,2,-68.0F,105.0F,2,-68.0F,105.0F,2,-78.0F);
			escenario+=new Suelo(90.0F,0,-68.0F,90.0F,0,-45.0F,105.0F,0,-45.0F,105.0F,0,-68.0F);
			escenario+=new Suelo(90.0F,0,-45.0F,90.0F,0,-35.0F,160.0F,0,-35.0F,160.0F,0,-45.0F);
			escenario+=new Suelo(140.0F,0,-128.0F,140.0F,0,-55.0F,160.0F,0,-55.0F,160.0F,0,-128.0F);

			inicializaMonstruos(monstruos);
			manzanas+=new Manzana(3,-10); // AL USAR NEW MANZANA AHORA LOS PARAMETROS SON: (X,Z,Y=0.3)

			caja1.SetPos(4.5,0.5,-5);
			caja2.SetPos(4.5,1.5,-5);
			caja3.SetPos(0.5,0.5,-2);
		}
}