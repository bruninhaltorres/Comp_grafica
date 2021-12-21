/* Nome: Bruna Leal Torres Silva
 * Matrícula: 19111149
 *
 * Comandos do teclado:
 *		e: Esquerda
 *		d: Direita
 *		m: Aumentar velocidade
 *		n: Diminui velocidade
 *		p: Velocidade normal
 */

#include <gl/glut.h>

int dir = 1;
int vel = 25;
int NumeroFrames = 0;


void flor() {

	int i;
	glColor3f(1.0f, 1.0f, 1.0f);

	/* Suporte da flor */
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();

	glTranslatef(0, 3, 0);
	glRotated((dir * (NumeroFrames * (180.0 / 70))), 0, 0, 1);

	/* Rotate com 90 graus, pois são 4 triângulos, logo 360/4 = 90 */
	/* Desenhar um polígono verde */
	glColor3f(0.0, 1.0, 0.0);
	glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(1.0f, 0.3f);
	glVertex2f(1.0f, -0.3f);
	glEnd();

	/* Desenhar um polígono azul */
	glColor3f(0.0, 0.0, 1.0);
	glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(1.0f, 0.3f);
	glVertex2f(1.0f, -0.3f);
	glEnd();

	/* Desenhar um polígono branco  */
	glColor3f(1.0, 1.0, 1.0);
	glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(1.0f, 0.3f);
	glVertex2f(1.0f, -0.3f);
	glEnd();

	/* Desenhar um polígono vermelho */
	glColor3f(1.0, 0.0, 0.0);
	glRotated(90, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(1.0f, 0.3f);
	glVertex2f(1.0f, -0.3f);
	glEnd();

}


void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslated(3.5, -0.7, 1);
	glScaled(1.0, 1.0, 1);

	flor();
	glPopMatrix();

	glutSwapBuffers();

}

void teclado(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':
		dir = -1;
		glutDisplayFunc(display);
		break;
	case 'e':
		dir = 1;
		glutDisplayFunc(display);
		break;
	case 'm':
		vel = 10;
		glutDisplayFunc(display);
		break;
	case 'n':
		vel = 40;
		glutDisplayFunc(display);
		break;
	case 'p':
		vel = 25;
		glutDisplayFunc(display);
		break;
	}
}

/* Altera os frames por segundo */
void doFrame(int v) {
	NumeroFrames++;
	glutPostRedisplay();
	glutTimerFunc(vel, doFrame, 0);
}

void init() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	//glMatrixMode(GL_MODELVIEW);
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
