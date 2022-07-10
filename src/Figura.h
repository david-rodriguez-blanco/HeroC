#ifndef FIGURA_H
#define FIGURA_H
//Es la clase base de las piezas
#include "ETSIDI.h"
#include "freeglut.h"
#include "vector2D.h"
#include <string>
#include <iostream>
using namespace std;
using namespace ETSIDI;

class Figura
{
public:
	enum COLOR { NS = -1, BLANCO, NEGRO };//color de la pieza
	enum TIPO{NF = -1, PEON, CABALLO,TORRE,REINA,REY,ALFIL};
	Figura();
	Figura(TIPO t, COLOR c, int x, int y);
	virtual bool estado();
	virtual void print();
	virtual void dibujar();
	virtual bool mover(int x, int y);
	virtual bool seleccionar(int x,int y);
	virtual bool detec_peligro();//new
	virtual vector2D get_pos();//new
	virtual TIPO get_tipo();//new
	virtual COLOR get_color();//new
	virtual void deseleccionar();
	virtual void peligrosidad();
	virtual bool comer(int x,int y);
	//Asignar los límites del movimiento//new
	virtual void dibujar_rango();
	virtual void set_limite_x_p(vector2D v);
	virtual void set_limite_x_n(vector2D v);
	virtual void set_limite_y_p(vector2D v);
	virtual void set_limite_y_n(vector2D v);
	virtual void set_limite_p_p(vector2D v);
	virtual void set_limite_p_n(vector2D v);
	virtual void set_limite_n_p(vector2D v);
	virtual void set_limite_n_n(vector2D v);
	virtual bool devolverColor();

protected:
	TIPO tipo;
	COLOR Color;
	int pos_x;
	int pos_y;
	bool seleccionado;//pieza está seleccionado?
	bool peligro;//La pieza hay peligro de ser comido?//new
	//limitacion de los movimientos//new
	vector2D limite_x_p;//x+
	vector2D limite_x_n;//x-
	vector2D limite_y_p;//y+
	vector2D limite_y_n;//y-
	vector2D limite_p_p;//x+ y+
	vector2D limite_p_n;//x+ y-
	vector2D limite_n_n;//x- y-
	vector2D limite_n_p;//x- y+
};

#endif