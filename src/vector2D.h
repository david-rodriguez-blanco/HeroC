#pragma once
#include <cmath>

class vector2D
{
public:
	virtual ~vector2D();
	int x;
	int y;
	
	vector2D(int xv = -10, int yv = -20); // (1)constructor
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	vector2D unitario(); // (4) devuelve un vector unitario
	vector2D operator - (vector2D); // (5) resta de vectores
	vector2D operator + (vector2D); // (6) suma de vectores
	bool operator ==(const vector2D);
	int operator *(vector2D); // (7) producto escalar
	vector2D operator *(int); // (8) producto por un escalar 
};



