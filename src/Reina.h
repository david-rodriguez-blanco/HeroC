#ifndef REINA_H
#define REINA_H
#include "Figura.h"
#include "vector2D.h"

class Reina : public Figura
{
private:
	SpriteSequence sprite_reina_blanco{ "imagenes/Pieza_Reina_Blanco.png",1 };
	SpriteSequence sprite_reina_negro{ "imagenes/Pieza_Reina_Negro.png",1 };
public:
	Reina();
	Reina(Figura::COLOR c, int x = -1, int y = -1);
	virtual ~Reina();
	void print();
	void dibujar();
	bool mover(int x, int y);
	bool seleccionar(int x, int y);

};

#endif // !REY_H

