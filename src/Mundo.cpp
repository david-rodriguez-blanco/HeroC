#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja(int color_tablero)
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	tablero.pintartablero(color_tablero);
	piezas.dibujar();
	//c.dibujar();
	//p1.dibujar();
	
	
}

void Mundo::movimiento()
{
	if (seleccionado == true)
		seleccionado = false;
}

void Mundo::mueve()
{
	if (seleccionado == false && click == true)
	{
		bool color = true; //true blanco falsr negro
		Figura* aux = piezas.seleccionar(mouse_x, mouse_y);
		if (aux == NULL)
			seleccionado = false;
		else if (aux != NULL)
		{
			if (color == aux->devolverColor() && n_turnos % 2 == 0)
			{
				seleccionado = aux->estado();
				selec_x = mouse_x;
				selec_y = mouse_y;
				n_turnos++;

			}
			else if (color != aux->devolverColor() && n_turnos % 2 != 0)
			{
				seleccionado = aux->estado();
				selec_x = mouse_x;
				selec_y = mouse_y;
				n_turnos++;

			}
		}
	}
	if(seleccionado == false && click == false && selec_x != NULL)
	{
		piezas.deseleccionar();
		selec_x = -10;
		selec_y = -20;
	}
	if (seleccionado == true && click == true)
	{
		if(mouse_x != selec_x || mouse_y != selec_y)
		{
			click = !(piezas.mover(selec_x, selec_y, mouse_x, mouse_y));
			seleccionado = click;
		}
		//piezas.mover(mouse_x, mouse_y);
	}
	//mouse_x = -1;
	//mouse_y = -1;
}

void Mundo::inicializa()
{
	seleccionado = false;
	click = false;
	mouse_x = -1;
	mouse_y = -1;
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 12;

	Reina* aux_reina_b = new Reina(Figura::BLANCO, 4, 0);
	piezas.agregar(aux_reina_b);
	Reina* aux_reina_n = new Reina(Figura::NEGRO, 4, 7);
	piezas.agregar(aux_reina_n);
	Rey* aux_r_b = new Rey(Figura::BLANCO, 3, 0);
	piezas.agregar(aux_r_b);
	Rey* aux_r_n = new Rey(Figura::NEGRO, 3, 7);
	piezas.agregar(aux_r_n);

	for (int i = 0; i < 8; i++)
	{
		Peon* aux_p_b_1 = new Peon(Figura::BLANCO, i, 1);
		piezas.agregar(aux_p_b_1);
		Peon* aux_p_b_2 = new Peon(Figura::NEGRO, i, 6);
		piezas.agregar(aux_p_b_2);
	}
	for (int i = 0; i < 8;i = i + 7)
	{
		Torre* aux_t_1 = new Torre(Figura::BLANCO, i, 0);
		piezas.agregar(aux_t_1);
		Torre *aux_t_2 = new Torre(Figura::NEGRO, i, 7);
		piezas.agregar(aux_t_2);
	}

	for (int i = 2; i < 6;i = i + 3)
	{
		Alfil* aux_a_1 = new Alfil(Figura::BLANCO, i, 0);
		piezas.agregar(aux_a_1);
		Alfil* aux_a_2 = new Alfil(Figura::NEGRO, i, 7);
		piezas.agregar(aux_a_2);
	}

	

	for (int i = 1; i < 7;i = i + 5)
	{
		Caballo* aux_c_b_1 = new Caballo(Figura::BLANCO, i, 0);
		piezas.agregar(aux_c_b_1);
		Caballo* aux_c_b_2 = new Caballo(Figura::NEGRO, i, 7);
		piezas.agregar(aux_c_b_2);
	}

}

void Mundo::raton(int button,int state, int _x, int _y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			//si el ratón está fuera de tablero
			if ((_x < 125 || _x>677) || (_y < 25 || _y>577))
			{
				mouse_x = -10;
				mouse_y = -20;
				click = false;
			}
			else
				for (int i = 0; i < 8; i++)//calcular casilla según pixeles
				{
					if (_x > i * 69 + 125 && _x < i * 69 + 125 + 69) {
						mouse_x = i;
						for (int j = 0; j < 8; j++)
						{
							if (_y > j * 69 + 25 && _y < j * 69 + 25 + 69)
								mouse_y = 7 - j;
						}
					}
				}
			click = true;
			cout << _x << "," << _y << endl;
			cout << mouse_x << "," << mouse_y << endl;
		}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		click = false;
		seleccionado = false;
	}
	}




Mundo::~Mundo()
{
	
	piezas.destruirContenido();
}

void Mundo::tecla(unsigned char key)
{

}
