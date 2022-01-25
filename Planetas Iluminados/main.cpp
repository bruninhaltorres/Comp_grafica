#include <gl/glut.h>

/* Nome: Bruna Leal Torres Silva
 * Matrícula: 19111149
 *
 * Comandos do teclado:
 *		y: Ativa translação dos planetas
 *      y novamente: Aumenta a velocidade
 */

#define LARANJA  0.8, 0.5, 0.1
#define AMARELO  1.0, 1.0, 0.0
#define VERMELHO 1.0, 0.0, 0.0
#define PINK     0.7, 0.1, 0.6
#define ROSE     0.8, 0.4, 0.3
#define AZUL     0.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0
#define CINZA    0.6, 0.6, 0.6

int frame = 0;
double velocidade = 1.0;

void reshape(int w, int h) {

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, (double)w / h, 1, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void doFrame(int value) {

    glutTimerFunc(10, doFrame, 0);
    frame++;
    glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y) {

    switch (key) {
        case 'y':
            glutTimerFunc(10, doFrame, 1);
            break;
        default:
            break;
    }
}

void PlanetaLua() {

    // PLANETA 1:
    glPushMatrix();

    glColor3f(AZUL);
    velocidade = 0.5;
    glRotatef(velocidade * frame, 0, 1, 0);
    glTranslatef(-2.5, 0.4, -1);
    glPushMatrix();
    glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    // LUA 1
    glPushMatrix();
    glColor3f(CINZA);
    velocidade = 1.5;
    glRotatef(velocidade * frame, 0, 1, 0);
    glTranslatef(0.45, 0.1, 0);
    glutSolidSphere(0.05, 100, 100);
    glPopMatrix();

    // LUA 2
    glPushMatrix();
    glColor3f(ROSE);
    velocidade = 2.0;
    glRotatef(velocidade * frame, 1, 1, 0);
    glTranslatef(0.35, 0, 0);
    glutSolidSphere(0.07, 100, 100);
    glPopMatrix();

    glPopMatrix();
}

void SistemaSolar() {

    // SOL:
    glPushMatrix();
    glColor3f(LARANJA);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();

    PlanetaLua();

    // PLANETA 2:
    glPushMatrix();
    glColor3f(VERDE);
    velocidade = 2;
    glRotatef(velocidade * frame, 0, -1, 0);
    glTranslatef(-1, -0.05, 0);
    glutSolidSphere(0.1, 100, 100); 
    glPopMatrix();

    // PLANETA 3:
    glPushMatrix();
    glColor3f(VERMELHO);
    velocidade = 2.5;
    glRotatef(velocidade * frame, 0, 1, 0);
    glTranslatef(1.1, 0.4, 1);
    glutSolidSphere(0.1, 100, 100); 
    glPopMatrix();

    // PLANETA 4:
    glPushMatrix();
    glColor3f(AMARELO);
    velocidade = 1.5;
    glRotatef(velocidade * frame, 0, -1, 0);
    glTranslatef(-2, -0.4, 0);
    glutSolidSphere(0.1, 100, 100);
    glPopMatrix();

    // PLANETA 5:
    glPushMatrix();
    glColor3f(PINK);
    velocidade = 1;
    glRotatef(velocidade * frame, 0, 1, 0);
    glTranslatef(2, 0, 0);
    glutSolidSphere(0.1, 100, 100);
    glPopMatrix();
}

void display() {

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    SistemaSolar();
    glPopMatrix();

    // Executa os comandos OpenGL
    glutSwapBuffers();
}

void init() {

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // cor do background
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
} 

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1200, 500);
    glutCreateWindow("Sistema Solar - Planetas");
    glutInitWindowPosition(200, 200);

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}