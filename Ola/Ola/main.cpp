#include <GLFW/glfw3.h>

// Comandos:
//      Subir: T, Y, U, I, O
//      Descer: G, H, J, K, L

static GLfloat pos_y[10] = {
    -1, 1,
    -1, 1,
    -1, 1,
    -1, 1,
    -1, 1
};

void renderizar() {
    // 1º
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-5, pos_y[0], 0.0);
    glVertex3f(-4, pos_y[0], 0.0);
    glVertex3f(-4, pos_y[1], 0.0);
    glVertex3f(-5, pos_y[1], 0.0);
    glEnd();

    // 2º
    glColor3f(2.0f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-3, pos_y[2], 0.0);
    glVertex3f(-2.0, pos_y[2], 0.0);
    glVertex3f(-2.0, pos_y[3], 0.0);
    glVertex3f(-3, pos_y[3], 0.0);
    glEnd();

    // 3º
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1, pos_y[4], 0.0);
    glVertex3f(0, pos_y[4], 0.0);
    glVertex3f(0, pos_y[5], 0.0);
    glVertex3f(-1, pos_y[5], 0.0);
    glEnd();

    // 4º
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.0, pos_y[6], 0.0);
    glVertex3f(2.0, pos_y[6], 0.0);
    glVertex3f(2.0, pos_y[7], 0.0);
    glVertex3f(1.0, pos_y[7], 0.0);
    glEnd();

    // 5º
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(3, pos_y[8], 0.0);
    glVertex3f(4, pos_y[8], 0.0);
    glVertex3f(4, pos_y[9], 0.0);
    glVertex3f(3, pos_y[9], 0.0);
    glEnd();

    glFlush();
}

void teclado(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_T && action == GLFW_PRESS) {
        pos_y[0] += 1;
        pos_y[1] += 1;
        renderizar();
    } if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
        pos_y[2] += 1;
        pos_y[3] += 1;
        renderizar();
    } if (key == GLFW_KEY_U && action == GLFW_PRESS) {
        pos_y[4] += 1;
        pos_y[5] += 1;
        renderizar();
    } if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        pos_y[6] += 1;
        pos_y[7] += 1;
        renderizar();
    } if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        pos_y[8] += 1;
        pos_y[9] += 1;
        renderizar();
    } if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        pos_y[0] -= 1;
        pos_y[1] -= 1;
        renderizar();
    } if (key == GLFW_KEY_H && action == GLFW_PRESS) {
        pos_y[2] -= 1;
        pos_y[3] -= 1;
        renderizar();
    } if (key == GLFW_KEY_J && action == GLFW_PRESS) {
        pos_y[4] -= 1;
        pos_y[5] -= 1;
        renderizar();
    } if (key == GLFW_KEY_K && action == GLFW_PRESS) {
        pos_y[6] -= 1;
        pos_y[7] -= 1;
        renderizar();
    } if (key == GLFW_KEY_L && action == GLFW_PRESS) {
        pos_y[8] -= 1;
        pos_y[9] -= 1;
        renderizar();
    }
}

int main() {

    GLFWwindow* window;

    glfwInit();
    window = glfwCreateWindow(1920, 1080, "Ola!", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, teclado);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);

        renderizar();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}