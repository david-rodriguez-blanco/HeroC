#ifndef ALFIL_H
#define ALFIL_H
#include "Figura.h"
#include "vector2D.h"

class Alfil : public Figura
{
private:
	SpriteSequence sprite_alfil_blanco{ "imagenes/Pieza_Alfil_Blanco.png",1 };
	SpriteSequence sprite_alfil_negro{ "imagenes/Pieza_Alfil_Negro.png",1 };
public:
	Alfil();
	Alfil(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Alfil();
	void print();
	void dibujar();
	bool mover(int x, int y);
	bool seleccionar(int x, int y);

};

#endif // !Alfil_H

