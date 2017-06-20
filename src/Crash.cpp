#include "Menu.h"
#include "glut.h"


bool keystatus[256] = {false}; //PARA USAR TECLAS NORMALES SI ESTAN PULSADAS
bool keySpecialStates[246] = {false}; // PARA USAR TECLAS ESPECIALES PULSADAS
Menu menu;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y);

void KeySpecialDown(int key, int x, int y);
void KeySpecialUp(int key, int x, int y);

// void onSpecialKeyboardDown(int key, int x, int y); // Para teclas especiales como el cursor
// Nos esta dando error LNK2019

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutSpecialFunc(KeySpecialDown); 
	glutSpecialUpFunc(KeySpecialUp); 

	// glutSpecialFunc(onSpecialKeyboardDown); 
	// El callback de teclas especiales No nos funciona


	// Nuestro código para inicializar cosas ajenas a glut


	menu.Inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	


	menu.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	//mundo.Tecla(key);   AHORA USAMOS LA FUNCION TECLAS
	keystatus[key]=true;   //AL PRESIONAR LA TECLA PONEMOS EL ESTADO EN TRUE
	glutPostRedisplay();
}
void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	keystatus[key]=false;    //AL LEVANTAR LA TECLA PONEMOS EL ESTADO EN FALSE
	glutPostRedisplay();
}
void KeySpecialDown(int key, int x_t, int y_t)
{
	keySpecialStates[key]=true;    //AL BAJAR A TECLA SE PONE EN TRUE
	glutPostRedisplay();
}

void KeySpecialUp(int key, int x_t, int y_t) 
{
	keySpecialStates[key]=false;    //AL LEVANTAR LA TECLA PONEMOS EL ESTADO EN FALSE
	glutPostRedisplay();
} 
/*void OnSpecialKeyboardDown(int key, int x_t, int y_t) 
{
	mundo.TeclaEspecial(key);
	glutPostRedisplay();
}*/  //Lo quito porque da error

void OnTimer(int value)
{
//poner aqui el código de animacion
	menu.Mueve();
	menu.VariasTeclas(keystatus, keySpecialStates);    // ESTA FUNCION AQUI CONSIGUE QUE PUEDA PULSAR VARIAS TECLAS
	//no borrar estas lineas
	glutTimerFunc(8,OnTimer,0);
	glutPostRedisplay();
}

//Nuevo merge
//otro merge a ver
// otra prueba