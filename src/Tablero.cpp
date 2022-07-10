#include "Tablero.h"

void Tablero::pintartablero(int c)
{
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			int suma = i + j;
			if ((suma % 2) !=0) {
				glBegin(GL_POLYGON);
				glColor3ub(0, 0, c);
				glVertex3d(i + 1, j + 1, 0);
				glVertex3d(i + 1, j, 0);
				glVertex3d(i, j, 0);
				glVertex3d(i, j + 1, 0);
				glEnd();
				glEnable(GL_LIGHTING);
			}

			if ((suma % 2) == 0) {
				glBegin(GL_POLYGON);
				glColor3ub(255, 255, 255);
				glVertex3d(i + 1, j + 1, 0);
				glVertex3d(i + 1, j, 0);
				glVertex3d(i, j, 0);
				glVertex3d(i, j + 1, 0);
				glEnd();
				glEnable(GL_LIGHTING);
			}

		}
	}
}
