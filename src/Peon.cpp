#include "Peon.h"

Peon::Peon()
{
	tipo = Figura::PEON;
	Color = Figura::NS;
	pos_x = -1;
	pos_y = -1;
	seleccionado = false;
	iniciar = true;
	peligro = false;
	//procesar = false;

	//sprite de peon blanco
	sprite_peon_blanco.setCenter(1, 0);
	sprite_peon_blanco.setSize(0.9, 0.9);//como z de la figura es 1, se establece una relación entre casilla y figura de 1:0.9

	//sprite de peon negro
	sprite_peon_negro.setCenter(1, 0);
	sprite_peon_negro.setSize(0.9, 0.9);
}
Peon::Peon(Figura::COLOR c, int x, int y)
{
	tipo = Figura::PEON;
	Color = c;
	pos_x = x;
	pos_y = y;
	seleccionado = false;
	iniciar = true;
	peligro = false;
	//procesar = false;
	//sprite de peon blanco
	sprite_peon_blanco.setCenter(1, 0);
	sprite_peon_blanco.setSize(0.9, 0.9);//como z de la figura es 1, se establece una relación entre casilla y figura de 1:0.9

	//sprite de peon negro
	sprite_peon_negro.setCenter(1, 0);
	sprite_peon_negro.setSize(0.9, 0.9);
}
Peon::~Peon()
{
}
//Constructor que pasa los parámetros al clase base

void Peon::print()
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
	cout << "[PEON " << color <<" "<< pos_x + 1 << "," << pos_y + 1 << "]" << endl;
}

void Peon::dibujar()
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
		sprite_peon_blanco.draw();
		glPopMatrix();
	}

	if(Color == Figura::NEGRO)
	{
		//dibujar un peon negro
		glPushMatrix();
		glTranslatef(1.325 + pos_x * 0.925, 0.325 + pos_y * 0.925, 1);/*z = 1 para que la figura se ponga por encima del tablero,
				(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
				+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_peon_negro.draw();
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
	dibujar_rango();
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

bool Peon::mover(int x, int y)
{
	if(seleccionado == false)
	return false;
	else
	{
		if (iniciar == true) // en caso de no ha dado el primer paso
		{
			if (x == pos_x)
				switch (Color)//se puede mover dos casilla
				{
				case(Figura::BLANCO):
					if (limite_y_p.y < 0)
					{
						if (y <= pos_y + 2)
						{
							pos_x = x;
							pos_y = y;
							seleccionado = false;
							iniciar = false;
							limite_y_p.x = -10;
							limite_y_p.y = -20;
							return true;
						}
						else
						{
							limite_y_p.x = -10;
							limite_y_p.y = -20;
							return false;
						}
					}
					else
					{
						if (y < limite_y_p.y)
						{
							pos_x = x;
							pos_y = y;
							seleccionado = false;
							iniciar = false;
							limite_y_p.x = -10;
							limite_y_p.y = -20;
							return true;
						}
						else
						{
							limite_y_p.x = -10;
							limite_y_p.y = -20;
							return false;
						}
					}
					break;
				case(Figura::NEGRO):
					if (limite_y_n.y < 0)
					{
						if (y < pos_y && y >= pos_y - 2)
						{
							pos_x = x;
							pos_y = y;
							iniciar = false;
							seleccionado = false;
							limite_y_n.x = -10;
							limite_y_n.y = -20;
							return true;
						}
						else
						{
							limite_y_n.x = -10;
							limite_y_n.y = -20;
							return false;
						}
					}
					else
					{
						if (y < pos_y && y > limite_y_n.y)
						{
							pos_x = x;
							pos_y = y;
							seleccionado = false;
							iniciar = false;
							limite_y_n.x = -10;
							limite_y_n.y = -20;
							return true;
						}
						else
						{
							limite_y_n.x = -10;
							limite_y_n.y = -20;
							return false;
						}
					}
					break;
				}
			else
				return false;
		}
		else//en caso que ha dado el primer paso
			if (x == pos_x)
				switch (Color)
				{
				case(Figura::BLANCO)://se puede mover una casilla
					if ((y == pos_y + 1 && y < limite_y_p.y) || (limite_y_p.y<0 && y == pos_y + 1))
					{
						pos_x = x;
						pos_y = y;
						seleccionado = false;
						limite_y_p.x = -10;
						limite_y_p.y = -20;
						return true;
					}
					else
					{
						limite_y_p.x = -10;
						limite_y_p.y = -20;
						return false;
					}
					break;
				case(Figura::NEGRO):
					if ((y == pos_y - 1 && y > limite_y_n.y) || (limite_y_n.y < 0 && y == pos_y - 1))
					{
						pos_x = x;
						pos_y = y;
						seleccionado = false;
						limite_y_n.x = -10;
						limite_y_n.y = -20;
						return true;
					}
					else
					{
						limite_y_n.x = -10;
						limite_y_n.y = -20;
						return false;
					}
					break;
				}
			else
				return false;
	}
}

bool Peon::seleccionar(int x, int y)
{
	if (pos_x == x && pos_y == y)
	{
			seleccionado = true;
	}
	return seleccionado;
}

void Peon::dibujar_rango()
{
	if (seleccionado == true)
	{
		/*//
		///
		switch(Color)
		{
		case Figura::BLANCO:
			if (iniciar == true)
			{
				if (limite_y_p.y < 0)
				{
					for (int i = 1; i < 3; i++)
					{
						glBegin(GL_POLYGON);//mostrar la pieza seleccionado
						glColor3ub(255, 255, 0);
						glVertex3d(pos_x + 1, pos_y + 1 + i, 0.01);
						glVertex3d(pos_x + 1, pos_y + i, 0.01);
						glVertex3d(pos_x, pos_y + i, 0.01);
						glVertex3d(pos_x, pos_y + 1 + i, 0.01);
						glEnd();
						glEnable(GL_LIGHTING);
					}
				}
				else
				{
					for (int i = 1;i < pos_y - limite_y_p.y;i++)
					{
						glBegin(GL_POLYGON);//mostrar la pieza seleccionado
						glColor3ub(255, 255, 0);
						glVertex3d(pos_x + 1, pos_y + 1 + i, 0.01);
						glVertex3d(pos_x + 1, pos_y + i, 0.01);
						glVertex3d(pos_x, pos_y + i, 0.01);
						glVertex3d(pos_x, pos_y + 1 + i, 0.01);
						glEnd();
						glEnable(GL_LIGHTING);
					}
				}
			}
			else
			{
				if(limite_y_p.y < 0 || abs(pos_y - limite_y_p.y) == 2)
				{
					glBegin(GL_POLYGON);//mostrar la pieza seleccionado
					glColor3ub(255, 255, 0);
					glVertex3d(pos_x + 1, pos_y + 2, 0.01);
					glVertex3d(pos_x + 1, pos_y + 1, 0.01);
					glVertex3d(pos_x, pos_y + 1, 0.01);
					glVertex3d(pos_x, pos_y + 2, 0.01);
					glEnd();
					glEnable(GL_LIGHTING);
				}
			}
			break;

		case(Figura::NEGRO):
			if (iniciar == true)
			{
				if (limite_y_n.y < 0)
				{
					for (int i = 1; i < 3; i++)
					{
						glBegin(GL_POLYGON);//mostrar la pieza seleccionado
						glColor3ub(255, 255, 0);
						glVertex3d(pos_x + 1, pos_y + 1 - i, 0.01);
						glVertex3d(pos_x + 1, pos_y - i, 0.01);
						glVertex3d(pos_x, pos_y - i, 0.01);
						glVertex3d(pos_x, pos_y + 1 - i, 0.01);
						glEnd();
						glEnable(GL_LIGHTING);
					}
				}
				else
				{
					for (int i = 1;i < pos_y - limite_y_n.y;i++)
					{
						glBegin(GL_POLYGON);//mostrar la pieza seleccionado
						glColor3ub(255, 255, 0);
						glVertex3d(pos_x + 1, pos_y + 1 - i, 0.01);
						glVertex3d(pos_x + 1, pos_y - i, 0.01);
						glVertex3d(pos_x, pos_y - i, 0.01);
						glVertex3d(pos_x, pos_y + 1 - i, 0.01);
						glEnd();
						glEnable(GL_LIGHTING);
					}
				}
			}
			else
			{
				if (limite_y_n.y < 0 || abs(pos_y - limite_y_n.y) == 2)
				{
					glBegin(GL_POLYGON);//mostrar la pieza seleccionado
					glColor3ub(255, 255, 0);
					glVertex3d(pos_x + 1, pos_y - 1, 0.01);
					glVertex3d(pos_x + 1, pos_y, 0.01);
					glVertex3d(pos_x, pos_y, 0.01);
					glVertex3d(pos_x, pos_y - 1, 0.01);
					glEnd();
					glEnable(GL_LIGHTING);
				}
			}
		}
	}
	///
	//*/

	}
}






