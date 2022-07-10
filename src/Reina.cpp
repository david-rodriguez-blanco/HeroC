#include "Reina.h"

Reina::Reina()
{
	tipo = Figura::REINA;
	Color = Figura::NS;
	pos_x = -1;
	pos_y = -1;
	seleccionado = false;
	peligro = false;

	//sprite de caballo blanco
	sprite_reina_blanco.setCenter(1, 0);
	sprite_reina_blanco.setSize(0.9, 0.9);//como z de la figura es 1, se establece una relación entre casilla y figura de 1:0.9

	//sprite de peon negro
	sprite_reina_negro.setCenter(1, 0);
	sprite_reina_negro.setSize(0.9, 0.9);

}

Reina::Reina(Figura::COLOR c, int x, int y)
{
	tipo = Figura::REINA;
	Color = c;
	pos_x = x;
	pos_y = y;
	seleccionado = false;
	peligro = false;
	//sprite de caballo blanco
	sprite_reina_blanco.setCenter(1, 0);
	sprite_reina_blanco.setSize(0.9, 0.9);//como z de la figura es 1, se establece una relación entre casilla y figura de 1:0.9

	//sprite de caballo negro
	sprite_reina_negro.setCenter(1, 0);
	sprite_reina_negro.setSize(0.9, 0.9);
}
Reina::~Reina()
{

}

void Reina::print()
{
	string color;
	switch (Color)
	{
	case Figura::BLANCO:
		color = "BLANCO";
		break;
	case Figura::NEGRO:
		color = "NEGRO";
		break;
	default:
		color = "NS";
	}
	cout << "[Reina " << color << " " << pos_x + 1 << "," << pos_y + 1 << "]" << endl;
}


void Reina::dibujar()
{
	//común para todos los figuras, solo hay que cambiar el sprite
	if (Color == Figura::BLANCO)
	{
		//dibujar un peon blanco
		glPushMatrix();
		glTranslatef(1.325 + pos_x * 0.925, 0.325 + pos_y * 0.925, 1);/*z = 1 para que la figura se ponga por encima del tablero,
				(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
				+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_reina_blanco.draw();
		glPopMatrix();
	}

	if (Color == Figura::NEGRO)
	{
		//dibujar un peon negro
		glPushMatrix();
		glTranslatef(1.325 + pos_x * 0.925, 0.325 + pos_y * 0.925, 1);/*z = 1 para que la figura se ponga por encima del tablero,
				(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
				+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_reina_negro.draw();
		glPopMatrix();
	}
	if (seleccionado == true)
	{
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 255);
		glVertex3d(pos_x + 1, pos_y + 1, 0.01);
		glVertex3d(pos_x + 1, pos_y, 0.01);
		glVertex3d(pos_x, pos_y, 0.01);
		glVertex3d(pos_x, pos_y + 1, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		
	}
	if (peligro == true)
	{
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(pos_x + 1, pos_y + 1, 0.01);
		glVertex3d(pos_x + 1, pos_y, 0.01);
		glVertex3d(pos_x, pos_y, 0.01);
		glVertex3d(pos_x, pos_y + 1, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
	}
}

bool Reina::mover(int x, int y)
{
	if (seleccionado == false)
		return false;
	else
	{
		if (abs(pos_x - x) == abs(pos_y - y) || ((pos_x == x) || (pos_y == y)))
		{
			pos_x = x;
			pos_y = y;
			seleccionado = false;
			return true;
		}
		else
			return false;
	}
}


bool Reina::seleccionar(int x, int y)
{
	if (pos_x == x && pos_y == y)
	{
		seleccionado = true;
	}
	return seleccionado;
}
