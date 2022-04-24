#pragma once


	enum Figura { REY, REINA, ALFIL, CABALLO, TORRE, PEON, VACIO };
	enum Color { BLANCO, NEGRO, VACIO };

	class Casilla
	{
	private:
		Figura figura;
		Color color;
		int x, y;
	public:
		void setFAC(Figura, Color);

	};
	class Tabla
	{
		Casilla casilla[8][8];
		//Color def = BLANCO;



		//funciones para mover figuras
		bool moverRey(Casilla* thisRey, Casilla* thisSpace);


		/*Aniadir mov para el resto de figuras*/

		//obtener la posicion de la casilla
		//devuelve dato de tipo casilla 
		//Getter
			Casilla* getCasilla(int x, int y)
		{
			return &casilla[x][y];
		}
		//establecer la posicion de la casilla
		//Setter
			void setCasilla(Casilla* c, int x, int y)
			{
				casilla[x][y] = *c;
			}
		//Funcion para realizar movimiento
			bool hacerMov();
		//Funcion para establecer la tabla 
			void setTabla();
		// bool jugarAjedrez(); ????



	};


