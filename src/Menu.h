#include "Mundo.h"
class Menu
{
public:
	Menu();

	void Tecla(unsigned char key);
	void Mueve();
	void VariasTeclas(bool keystatus[], bool keyspecial[]);  // ESTA ES LA FUNCION QUE USAREMOSS
	void TeclaEspecial(unsigned char key);
	void Dibuja();
	void Inicializa();
protected:
	Mundo mundo;
	enum Estado {INICIO, JUEGO, GAMEOVER, FIN};
	Estado estado;
};
