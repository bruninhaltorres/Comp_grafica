/* Bruno Molina Rosaboni n°USP: 7656533
 * Werik Amaral Fachim n°USP: 7656512
 *
 * Para compilar:
 *		gcc -o catavento catavento.c -lGL -lglut -lm
 */

#include <gl/glut.h>

int dir = 1;
int NumeroFrames = 0;
int HEX_ANGLE = 0;


void catavento() {


	glColor3f(1.0, 1.0, .0);
	glBegin(GL_POLYGON);
	glVertex3f(249.0f, 250.0f, -1.0f);
	glVertex3f(251.0f, 250.0f, -1.0f);
	glVertex3f(249.0f, 100.0f, -1.0f);
	glVertex3f(251.0f, 100.0f, -1.0f);
	glEnd();

	glTranslatef(0, 3, 0);

	glRotated((dir * (HEX_ANGLE * (180.0 / 70))), 0, 0, 1);

	//HEX_ANGLE += 5;//gira 5 graus a cada redisplay
	//HEX_ANGLE %= 360;//mantém o angulo entre 0 e 360

	//glRotatef(HEX_ANGLE, 0, 0, dir);


	/* Desenhar um polígono branco  */
	glColor3f(1.0, 1.0, 1.0);
	//glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(230.0f, 200.0f);
	glVertex2f(270.0f, 200.0f);
	glEnd();

	/* Desenhar um polígono vermelho */
	glColor3f(1.0, 0.0, 0.0);
	//glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(300.0f, 230.0f);
	glVertex2f(300.0f, 270.0f);
	glEnd();

	/* Desenhar um polígono verde */
	glColor3f(0.0, 1.0, 0.0);
	//glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(230.0f, 300.0f);
	glVertex2f(270.0f, 300.0f);
	glEnd();

	/* Desenhar um polígono vermelho */
	glColor3f(0.0, 0.0, 1.0);
	//glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(200.0f, 270.0f);
	glVertex2f(200.0f, 230.0f);
	glEnd();


	/* Não esperar! */
	glFlush();

	
}


void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	//glTranslated(35, 50, 1);
	//glScaled(1.0, 1.0, 1);

	/*glPushMatrix();
	glTranslated(250, 30, 1);
	glScaled(100, 100, 10);*/

	catavento();
	glPopMatrix();

	glutSwapBuffers();

}

void teclado(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':
		dir = 1;
		glutDisplayFunc(display);
		break;
	case 'e':
		dir = -1;
		glutDisplayFunc(display);
		break;
	case 'm':
		HEX_ANGLE += 10;
		glutDisplayFunc(display);
		break;
	case 'n':
		HEX_ANGLE -= 4;
		glutDisplayFunc(display);
		break;
	}
}

/*
* Altera os frames por segundo
*/
void doFrame(int v) {
	//NumeroFrames++;
	glutPostRedisplay();
	glutTimerFunc(20, doFrame, 0);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(0, 7, -1, 4, -1, 1);
	glOrtho(0.0, 500.0, 0, 400.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flor de Abril");

	init();

	glutDisplayFunc(display);
	glutTimerFunc(200, doFrame, 0);
	glutKeyboardFunc(teclado);

	glutMainLoop();
	return 0;
}
