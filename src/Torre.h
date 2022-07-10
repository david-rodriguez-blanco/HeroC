#ifndef TORRE_H
#define TORRE_H
#include "Figura.h"
#include "vector2D.h"

class Torre : public Figura
{
private:
	SpriteSequence sprite_torre_blanco{ "imagenes/Pieza_Torre_Blanco.png",1 };
	SpriteSequence sprite_torre_negro{ "imagenes/Pieza_Torre_Negro.png",1 };
public:
	Torre();
	Torre(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Torre();
	void print();
	void dibujar();
	bool mover(int x, int y);
	bool seleccionar(int x, int y);

};

#endif // !TORRE_H

