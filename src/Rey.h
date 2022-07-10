#ifndef REY_H
#define REY_H
#include "Figura.h"
#include "vector2D.h"

class Rey : public Figura
{
private:
	SpriteSequence sprite_rey_blanco{ "imagenes/Pieza_Rey_Blanco.png",1 };
	SpriteSequence sprite_rey_negro{ "imagenes/Pieza_Rey_Negro.png",1 };
public:
	Rey();
	Rey(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Rey();
	void print();
	void dibujar();
	bool mover(int x, int y);
	bool seleccionar(int x, int y);

};

#endif // !REY_H

