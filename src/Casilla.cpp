#include "Casilla.h"

Casilla::~Casilla()
{
}

void Casilla::destruirContenido()
{
	for (int i = 0;i < tam;i++)
	{
		figu[i] = 0;
	}
	tam = 0;
}

Figura* Casilla::seleccionar(int x, int y)
{
	bool var;
	Figura* aux=0;
	for (int i = 0;i < tam;i++)
	{
		var = figu[i]->seleccionar(x, y);
		if (var == true)
			aux = figu[i];
	}
	return aux;
}
///////////////////////////////////////////////////
bool Casilla::mover(int x, int y, int xf, int yf)
{
	bool retorno=false;
	Figura* aux = 0;
	aux = seleccionar(x, y);
	if (aux == 0)
		return retorno;
	Dibujar_rango(aux);
	retorno = aux->mover(xf, yf);
	return retorno;
}
///////////////////////////////////////////////////
void Casilla::eliminar(int index)
{
	if ((index < 0) || (index >= tam))
		return;
	delete figu[index];
	tam--;
	for (int i = index;i < tam;i++)
		figu[i] = figu[i + 1];
}
void Casilla::eliminar(Figura* e)
{
	for (int i = 0;i < tam;i++)
		if (figu[i] == e)
		{
			eliminar(i);
			return;
		}
}

bool Casilla::colision(Figura* f, vector2D op)
{
	for(int i = 0;i<tam;i++)
	{
		if (figu[i]->get_pos() == op)
			if (f->get_tipo() == Figura::PEON)
				return true;
			else
			{
				if (figu[i]->get_color() == f->get_color())
					return true;
			}
	}
	return false;
}
///////////////////////////////////////////////////
void Casilla::Dibujar_rango(Figura* f)
{
	vector2D op;
	switch(f->get_tipo())
	{
	case Figura::ALFIL:
		for (int i = f->get_pos().x - 1;i <= f->get_pos().x + 1;i = i + 2)
			break;
	case Figura::PEON:
		op.x = f->get_pos().x;
		if (f->get_color() == Figura::BLANCO)
		{
			for (int i = f->get_pos().y + 1;i <= f->get_pos().y + 2;i++)
			{
				op.y = i;
				bool colisionar = colision(f,op);
				if (colisionar == true)
				{
					f->set_limite_y_p(op);
					break;
				}
			}
			
		}
		else
		{
			for (int i = f->get_pos().y - 1;i >= f->get_pos().y - 2;i--)
			{
				op.y = i;
				bool colisionar = colision(f,op);
				if (colisionar == true)
				{
					f->set_limite_y_n(op);
					break;
				}
			}
		}

		break;
	}
}
void Casilla::posibilidad_comer(Figura* f)
{
	vector2D op;
	switch(f->get_tipo())
	{
	case Figura::PEON:
		if (f->get_color() == Figura::BLANCO)
			op.y = f->get_pos().y + 1;
		else
			op.y = f->get_pos().y - 1;
		for (int i = f->get_pos().x - 1;i <= f->get_pos().x + 1;i = i + 2)
			{
				op.x = i;
				comer(op);
			}
	break;
	}
}
void Casilla::comer(vector2D op)
{
	for (int i = 0;i < tam;i++)
	{
		if (figu[i]->get_pos() == op)
		{
			figu[i]->peligrosidad();
			break;
		}
	}
}
void Casilla::deseleccionar()
{
	for(int i = 0;i<tam;i++)
	{
			figu[i]->deseleccionar();
	}
}
///////////////////////////////////////////////////


bool Casilla::agregar(Figura* f)//para agregar figuras
{
	if (tam < MAX)
	{
		figu[tam++] = f;
		return true;
	}
	else return false;
}

void Casilla::dibujar()
{
	for (int i = 0;i < tam;i++)
		figu[i]->dibujar();
}
