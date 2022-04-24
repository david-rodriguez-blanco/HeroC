#include "chess.h"
#include <iostream>
#include <cmath>
#include <string>

//Constructor Casilla

void Casilla::setVacio()
{
	color = NS;
	figura = VACIO;
}
void Casilla::setCas(Casilla* cas)
{
	color = cas->getColor();
	figura = cas->getFigura();
}



Figura Casilla::getFigura()
{
	return figura;
}

Color Casilla::getColor()
{
	return color;
}

//Funcion setter para X
void Casilla :: sX(int _x)
{
	x = _x;
}
//Funcion setter para y
void Casilla::sY(int _y)
{
	y = _y;
}
//Funcion getter para X
int Casilla::gX()
{
	return x;
}
//Funcion getter para X
int  Casilla::gY()
{
	return y;
}

//Destructor Casilla

Casilla::~Casilla()
{

}


void Tabla::setTabla()
{
	//Las figuras blacncas y negras en las filas 0 y 7
	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[1][0].setFAC(CABALLO, BLANCO);
	casilla[2][0].setFAC(ALFIL, BLANCO);
	casilla[3][0].setFAC(REINA, BLANCO);
	casilla[4][0].setFAC(REY, BLANCO);
	casilla[5][0].setFAC(ALFIL, BLANCO);
	casilla[6][0].setFAC(CABALLO, BLANCO);
	casilla[7][0].setFAC(TORRE, BLANCO);

	casilla[0][7].setFAC(TORRE, BLANCO);
	casilla[1][7].setFAC(CABALLO, BLANCO);
	casilla[2][7].setFAC(ALFIL, BLANCO);
	casilla[3][7].setFAC(REINA, BLANCO);
	casilla[4][7].setFAC(REY, BLANCO);
	casilla[5][7].setFAC(ALFIL, BLANCO);
	casilla[6][7].setFAC(CABALLO, BLANCO);
	casilla[7][7].setFAC(TORRE, BLANCO);

	//El resto de la tabla en blanco sin figuras
	for (int j = 0; j <= 5; j++)
	{
		for (int k = 0; k <= 7; k++)
		{
			casilla[k][j].setFAC(VACIO,NS);
		}
	}

	//Peones blancos y negros
	for (int i = 0; i <= 7; i++)
	{
		casilla[i][1].setFAC(PEON, BLANCO);
		casilla[i][6].setFAC(PEON, NEGRO);
	}

}

	//prototipo función menú

int menu()
{
	int eleccion;
	//representación visual del menú inicial y las distintas opciones
	enum Opciones {JUGAR=1, CARGAR_PARTIDA=2, RANKING=3, SALIR=0};//estan por ahora opciones de las características opcionales, ya veremos si las dejamos o se van
	//se elige mediante el ratón o teclado una de las opciones, dando así valor a "eleccion"
	cin >> eleccion;//ejemplo basico de esto ^
	if (eleccion == JUGAR)
		elegir(); //aun sin definir
	if (eleccion == CARGAR_PARTIDA)
		cargar();//aun sin definir
	if (eleccion == SALIR)
		return 0;
	if (eleccion == RANKING)
		ranking();//aun sin definir
}
	

