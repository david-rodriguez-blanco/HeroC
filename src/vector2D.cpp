#include "vector2D.h"

vector2D::vector2D(int xv, int yv)
{
	x = xv;
	y = yv;
}

float vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}

float vector2D::argumento()
{
	return (float)atan2(y, x);
}

vector2D vector2D::unitario()
{
	vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

vector2D vector2D::operator-(vector2D v)
{
	vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

vector2D::~vector2D()
{
}


vector2D vector2D::operator+(vector2D op)
{
	vector2D resultado;
	resultado.x = x + op.x;
	resultado.y = y + op.y;
	return resultado;
}

bool vector2D::operator==(const vector2D op)
{
	if (this->x == op.x && this->y == op.y)
		return true;
	else return false;
}

int vector2D::operator*(vector2D es)
{
	int product;
	product = x * es.x + y * es.y;
	return product;
}



vector2D vector2D::operator*(int p)
{
	vector2D res;
	res.x = x * p;
	res.y = y * p;
	return res;
}






