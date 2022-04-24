#include "chess.h"
#include <iostream>
#include <cmath>
#include <string>



void Tabla::setTabla()
{
	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[0][1].setFAC(CABALLO, BLANCO);
	casilla[0][2].setFAC(ALFIL, BLANCO);
	casilla[0][3].setFAC(REINA, BLANCO);
	casilla[0][4].setFAC(REY, BLANCO);
	casilla[0][5].setFAC(, BLANCO);
	casilla[0][6].setFAC(TORRE, BLANCO);
	casilla[0][7].setFAC(TORRE, BLANCO);

	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[0][0].setFAC(TORRE, BLANCO);
	casilla[0][0].setFAC(TORRE, BLANCO);


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
	
}
