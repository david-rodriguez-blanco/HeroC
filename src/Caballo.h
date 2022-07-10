#ifndef CABALLO_H
#define CABALLO_H
#include "Figura.h"
#include "vector2D.h"

class Caballo : public Figura
{
private:
	SpriteSequence sprite_caballo_blanco{ "imagenes/Pieza_Caballo_Blanco.png",1 };
	SpriteSequence sprite_caballo_negro{ "imagenes/Pieza_Caballo_Negro.png",1 };
public:
	Caballo();
	Caballo(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Caballo();
	void print();
	void dibujar();
	bool mover(int x, int y);
	bool seleccionar(int x, int y);

};

#endif // !CABALLO_H

