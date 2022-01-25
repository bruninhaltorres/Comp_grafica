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

void setup_lighting() {
    float mat_specular[] = {1.0f, 1.0f, 1.0f};
	float mat_shininess[] = {50.0f};
	float light_position[] = {0.0f, 65.0f, 0.0f, 1.0f};
    float light_diffuse [] = {1.0f , 1.0f , 1.0f }; // Luz branca

    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //spot : ponto luminoso
    float spot_direction [] = {-0.7f , -0.3f , 0.0f };
    float spot_cutoff [] = {15.0f }; // Ângulo de dispersão da luz
    float spot_specular[] = {1.0f, 1.0f, 0.0f}; // Amarelo
    float spot_position[] = {20 , 25 , -61, 1.0 };
    float spot_difuse[] = {1.0, 1.0, 0.0};

    glMaterialfv(GL_LIGHT0 , GL_SPECULAR , spot_specular);
    glLightfv ( GL_LIGHT0 , GL_DIFFUSE , spot_difuse ) ;

    glLightfv(GL_LIGHT0, GL_POSITION, spot_position);
    glLightfv ( GL_LIGHT0 , GL_SPOT_DIRECTION , spot_direction ) ;
    glLightfv ( GL_LIGHT0 , GL_SPOT_CUTOFF , spot_cutoff ) ;
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
    glEnable(GL_COLOR_MATERIAL);
}

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

    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
    glDepthRange(0.0f, 1.0f);

    setup_lighting();
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
