#ifndef CASILLA_H
#define CASILLA_H
//lista para gestionar las figuras
#include "Figura.h"
#define MAX 100

class Casilla
{
private:
	int tam;
	Figura* figu[MAX];
public:
	Casilla() :tam(0)
	{
		for (int i = 0;i < MAX;i++)
			figu[i] = NULL;
	}
	virtual ~Casilla();
	bool agregar(Figura* f);
	void dibujar();
	void destruirContenido();
	Figura* seleccionar(int x, int y);
	bool mover(int x, int y, int xf, int yf);
	void eliminar(int index);//new
	void eliminar(Figura* e);//new
	bool colision(Figura *f, vector2D op);
	void Dibujar_rango(Figura *f);//new
	void posibilidad_comer(Figura* f);
	void comer(vector2D op);
	void deseleccionar();
};

#endif



