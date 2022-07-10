#pragma once
//#ifndef MUNDO_H
//#define MUNDO_H
#include "Tablero.h"
#include "Casilla.h"
#include "Peon.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Torre.h"
#include "Rey.h"

class Mundo
{
protected: 
	int mouse_x, mouse_y;
	int selec_x, selec_y;
	Tablero tablero;
	//Figura peon_b;//test
	Casilla piezas;
	bool seleccionado;
	bool click;
	static const int N_turnos_max = 50;
	int n_turnos = 0;

public://Peon p2;
	void raton(int button,int state, int _x, int _y);
	~Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja(int color_tablero);
	void movimiento();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};

//#endif
