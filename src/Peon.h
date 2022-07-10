#ifndef PEON_H
#define PEON_H
#include "Figura.h"
#include "vector2D.h"

class Peon:public Figura  
{
private:
	SpriteSequence sprite_peon_blanco{ "imagenes/peon_blanco.png", 1 };
	SpriteSequence sprite_peon_negro{ "imagenes/peon_negro.png", 1 };
	bool iniciar;//diferencia si el peon ha hecho el primer paso o no
public:
	Peon();
	Peon(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Peon();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
	void dibujar_rango();
};

#endif