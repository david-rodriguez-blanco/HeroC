#pragma once
#include "Mundo.h"
#include "ETSIDI.h"
#include "Tablero.h"


class Coordinador
{
protected:
	Mundo mundo;
	Tablero tablero;
	enum Estado { INICIO, JUEGO_MAQ,JUEGO_IND, FIN, PAUSA,PREGUNTA, INSTRUCCIONES}; //JUEGO_MAQ -> jugador vs máquina, JUEGO_IND -> Jugador vs Jugador
	Estado estado;

public:
	Coordinador(void);
	virtual ~Coordinador(void);

	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void raton(int button,int state, int _x, int _y);
};


