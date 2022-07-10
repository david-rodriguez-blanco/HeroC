#include "Figura.h"


Figura::Figura()
{
	tipo = NF;
	Color = NS;
	pos_x = -1;
	pos_y = -1;
}

Figura::Figura(TIPO t, COLOR c, int x, int y)
{
	tipo = t;
	Color = c;
	pos_x = x;
	pos_y = y;
}
bool Figura::devolverColor() 
{
	if (this->Color == BLANCO)
	{
		return true;
	}
	else
		return false;
}

bool Figura::estado()
{
	return seleccionado;
}

void Figura::print()
{
}

void Figura::dibujar()
{
}

bool Figura::mover(int x, int y)
{
	return false;
}

bool Figura::seleccionar(int x, int y)
{
	return false;
}

bool Figura::detec_peligro()
{
	return peligro;
}

vector2D Figura::get_pos()
{
	vector2D op;
	op.x = pos_x;
	op.y = pos_y;
	return op;
}

Figura::TIPO Figura::get_tipo()
{
	return tipo;
}

Figura::COLOR Figura::get_color()
{
	return Color;
}

void Figura::deseleccionar()
{
	seleccionado = false;
}

void Figura::peligrosidad()
{
		peligro = true;
}

bool Figura::comer(int x, int y)
{
	return false;
}

void Figura::dibujar_rango()
{
}

void Figura::set_limite_x_p(vector2D v)
{
	limite_x_p = v;
}

void Figura::set_limite_x_n(vector2D v)
{
	limite_x_n = v;
}

void Figura::set_limite_y_p(vector2D v)
{
	limite_y_p = v;
}

void Figura::set_limite_y_n(vector2D v)
{
	limite_y_n = v;
}

void Figura::set_limite_p_p(vector2D v)
{
	limite_p_p = v;
}

void Figura::set_limite_p_n(vector2D v)
{
	limite_p_n = v;
}

void Figura::set_limite_n_p(vector2D v)
{
	limite_n_p = v;
}

void Figura::set_limite_n_n(vector2D v)
{
	limite_n_n = v;
}



