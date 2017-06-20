#include "Escenario.h"
#include "Suelo.h"
#include "glut.h"

Escenario::Escenario()
{
	numero=0;
	for(int i=0;i<MAX_SUELOS;i++)lista[i]=0;

	numero2=0;
	for(int i=0;i<MAX_SUELOS;i++)lista2[i]=0;

	plano=0;

	/*Suelo *n1=new Suelo;
	n1->SetPos(-5.0F,0,-20.0F,
		-5.0F,0,5.0F,
		5.0F,0,5.0F,
		5.0F,0,-20.0F);
	agregar(n1);

	Suelo *n2=new Suelo;
	n2->SetPos(-5.0F,0,-30.0F,
		-5.0F,0,-20.0F,
		25.0F,0,-20.0F,
		25.0F,0,-30.0F);
	agregar(n2);

	Suelo *n3=new Suelo;
	n3->SetPos(15.0F,0,-50.0F
		,15.0F,0,-30.0F,
		25.0F,0,-30.0F,
		25.0F,0,-50.0F);
	agregar(n3);

	Suelo *n4=new Suelo;
	n4->SetPos(5.0F,0,-50.0F,
		5.0F,0,-40.0F,
		15.0F,0,-40.0F,
		15.0F,0,-50.0F);
	agregar(n4);

	Suelo *n5=new Suelo;
	n5->SetPos(5.0F,0,-70.0F,
		5.0F,0,-50.0F,
		15.0F,0,-50.0F,
		15.0F,0,-70.0F);
	agregar(n5);

	Suelo *n6=new Suelo;
	n6->SetPos(5.0F,3.0F,-100.0F,
		5.0F,3.0F,-70.0F,
		15.0F,3.0F,-70.0F,
		15.0F,3.0F,-100.0F);
	agregar(n6);

	Suelo *n7=new Suelo;
	n7->SetPos(15.0F,3.0F,-100.0F,
		15.0F,3.0F,-85.0F,
		50.0F,3.0F,-85.0F,
		50.0F,3.0F,-100.0F);
	agregar(n7);

	Suelo *n8=new Suelo;
	n8->SetPos(50.0F,6,-100.0F,
		50.0F,6,-85.0F,
		58.0F,6,-85.0F,
		58.0F,6,-100.0F);
	agregar(n8);

	Suelo *n9=new Suelo;
	n9->SetPos(58.0F,9.5,-100.0F,
		58.0F,9.5,-85.0F,
		74.0F,9.5,-85.0F,
		74.0F,9.5,-100.0F);
	agregar(n9);

	Suelo *n10=new Suelo;
	n10->SetPos(74.0F,8,-100.0F,
		74.0F,8,-85.0F,
		80.0F,8,-85.0F,
		80.0F,8,-100.0F);
	agregar(n10);
	
	Suelo *n11=new Suelo;
	n11->SetPos(80.0F,6,-100.0F,
		80.0F,6,-85.0F,
		105.0F,6,-85.0F,
		105.0F,6,-100.0F);
	agregar(n11);
	
	Suelo *n12=new Suelo;
	n12->SetPos(90.0F,6,-85.0F,
		90.0F,6,-78.0F,
		105.0F,6,-78.0F,
		105.0F,6,-85.0F);
	agregar(n12);

	Suelo *n13=new Suelo;
	n13->SetPos(90.0F,6,-85.0F,
		90.0F,6,-78.0F,
		105.0F,6,-78.0F,
		105.0F,6,-85.0F);
	agregar(n13);

	Suelo *n14=new Suelo;
	n14->SetPos(90.0F,2,-78.0F,
		90.0F,2,-68.0F,
		105.0F,2,-68.0F,
		105.0F,2,-78.0F);
	agregar(n14);

	Suelo *n15=new Suelo;
	n15->SetPos(90.0F,0,-68.0F,
		90.0F,0,-45.0F,
		105.0F,0,-45.0F,
		105.0F,0,-68.0F);
	agregar(n15);

	Suelo *n16=new Suelo;
	n16->SetPos(90.0F,0,-45.0F,
		90.0F,0,-35.0F,
		160.0F,0,-35.0F,
		160.0F,0,-45.0F);
	agregar(n16);

	Suelo *n17=new Suelo;
	n17->SetPos(140.0F,0,-128.0F,
		140.0F,0,-55.0F,
		160.0F,0,-55.0F,
		160.0F,0,-128.0F);
	agregar(n17);*/

	/*Suelo *p1=new Suelo;
	p1->SetPos(-5.0F,0,-30.0F,
		-5.0F,0,5.0F,
		-5.0F,4.5,5.0F,
		-5.0F,4.5,-30.0F);
	agregar2(p1);

	Suelo *p2=new Suelo;
	p2->SetPos(15.0F,0,-30.0F,
		-5.0F,0,-30.0F,
		-5.0F,4.5,-30.0F,
		15.0F,4.5,-30.0F);
	agregar2(p2);

	Suelo *p3=new Suelo;
	p3->SetPos(5.50F,0,-16.0F,
		5.50F,0,5.0F,
		5.50F,4.5,5.0F,
		5.50F,4.5,-16.0F);
	agregar2(p3);*/

}

void Escenario::Dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->Dibuja();
	for(int i=0;i<numero2;i++)
		lista2[i]->Dibuja2();
}

bool Escenario::agregar(Suelo *m)
{
	for(int i=0;i<numero;i++)//para evitar que se añada una manzana ya existente
		if(lista[i]==m)
			return false;

	if(numero<MAX_SUELOS)
	   lista[numero++]=m;
	else 
		return false;
	return true;
}

bool Escenario::agregar2(Suelo *m)
{
	for(int i=0;i<numero2;i++)//para evitar que se añada una manzana ya existente
		if(lista2[i]==m)
			return false;

	if(numero2<MAX_SUELOS)
	   lista2[numero2++]=m;
	else 
		return false;
	return true;
}

void Escenario::eliminar()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	numero=0;
	for(int i=0;i<numero2;i++)
		delete lista2[i];
	numero2=0;
	plano=0;
}
void Escenario::operator+=(Suelo *m)
{
	agregar(m);
}