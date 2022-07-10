#include "Coordinador.h"

Coordinador::Coordinador()
{
	// El estado incial del programa será el inicio
	estado = INICIO;
}

Coordinador::~Coordinador()
{
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'j')
		{
			mundo.inicializa();
			estado = JUEGO_IND;
		}
		else if(key == 'm')
		{
			mundo.inicializa(); 
			estado = JUEGO_MAQ;
		}
		else if (key == 'i')
		{
			estado = INSTRUCCIONES; 
		}
		if (key == 's')
			exit(0);

	}

	else if (estado == JUEGO_IND || estado == JUEGO_MAQ)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}

	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado = PREGUNTA;
		else if (key == 'f')
		{
			estado = FIN;
			mundo.~Mundo();
		}
	}

	else if (estado == PREGUNTA)
	{
		if (key == 'j')
			estado = JUEGO_IND;
		else if (key == 'm')
			estado = JUEGO_MAQ; 
	}

	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}

	else if (estado == INSTRUCCIONES)
	{
		if (key == 'r')
			estado = INICIO; 
	}
	
}

void Coordinador::mueve()
{
	if (estado == JUEGO_IND || estado == JUEGO_MAQ)
		mundo.mueve();
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HERO C / Ajedrez", -5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -J- PARA EMPEZAR < JUGADOR/JUGADOR >", -10, 8);
		ETSIDI::printxy("PULSE LA TECLA -M- PARA EMPEZAR < JUGADOR/MAQUINA >", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA [ SALIR ]", -10, 6);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA [ INSTRUCCIONES ]", -10, 5);
	}
	else if (estado == JUEGO_IND || estado == JUEGO_MAQ)
	{
		if (estado == JUEGO_IND)
			mundo.dibuja(255);
		else
			mundo.dibuja(75);
	}
	else if (estado == FIN)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(255, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JUEGO FINALIZADO",-5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -C- para dirigirse al menu inicial", -8, 8);
	}
	else if (estado == PAUSA)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Si desea CONTINUAR pulse la tecla -C-", -5, 7);
		ETSIDI::printxy("Si desea FINALIZAR pulse la tecla -F-", -5, 6);

	}
	else if (estado == PREGUNTA)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("¿Con que modo desea continuar?", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("JUGADOR vs JUGADOR -J-", -5, 7);
		ETSIDI::printxy("JUGADOR vs MAQUINA -M-", -5, 6);

	}
	else if (estado == INSTRUCCIONES)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("INSTRUCCIONES", -10, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("1. Si en cualquier instante del juego desea PAUSAR pulse la tecla 'P'", -10, 12);
		ETSIDI::printxy("2. El juego cuenta con dos modos (JUGADOR vs JUGADOR) y (JUGADOR vs MAQUINA)", -10, 11);
		ETSIDI::printxy("     Si desea cambiar de modo debe pasar por el menu de pausa seleccionando la opcion de continuar", -10, 10);
		ETSIDI::printxy("Si desea REGRESAR al inicio pulse la tecla -R-", -10, 1);

	}
}

void Coordinador::raton(int button,int state, int _x, int _y)
{
	if (estado == JUEGO_IND || estado == JUEGO_MAQ)
	{
		mundo.raton(button, state, _x, _y);
	}

}

