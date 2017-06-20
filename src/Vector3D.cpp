#include "Vector3D.h"
#include <math.h>


Vector3D::Vector3D(float xv,float yv, float zv)
{
	x=xv;
	y=yv;
	z=zv;
}


Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x=x-v.x;
	res.y=y-v.y;
	res.z=z-v.z;
	return res;
}

Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x=x+v.x;
	res.y=y+v.y;
	res.z=z+v.z;
	return res;
}

float Vector3D::operator *(Vector3D &v)
{
	float res;
	res = (x*v.x)+(y*v.y)+(z*v.z);
	return res;
}


Vector3D Vector3D::operator *(float k)
{
	Vector3D res;
	res.x = x*k;
	res.y = y*k;
	res.z = z*k;
	return res;
}
float Vector3D::modulo()
{
	return (float)sqrt(x*x+y*y+z*z);
}

Vector3D Vector3D::unitario()
{
	Vector3D retorno(x,y,z);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
		retorno.z/=mod;
	}
	return retorno;
}
Vector3D Vector3D::pvectorial(Vector3D v)
{
	Vector3D resultado;
	resultado.x=y*v.z-z*v.y;
	resultado.y=-(x*v.z-z*v.x);
	resultado.z=x*v.y-y*v.x;
	return resultado;

}
float Vector3D::angulo_con_vector(Vector3D v)
{
	Vector3D copia = *this;
	float angulo = acos((copia*v)/((copia.modulo())*(v.modulo()))); 
	return angulo;
}