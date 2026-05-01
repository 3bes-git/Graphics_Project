#include <GL/glut.h>
#include <math.h>

bool isNight = false;

void Background() {

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); //Day
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'n' || key == 'N') {
        isNight = true;
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); //Night
    }
    if (key == 'l' || key == 'L') {
        isNight = false;
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); //Day
    }
    if (key == 27) exit(0);

    glutPostRedisplay();
}

void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawSquare(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);

        glVertex2f(x - size/2, y - size/2);
        glVertex2f(x + size/2, y - size/2);
        glVertex2f(x + size/2, y + size/2);
        glVertex2f(x - size/2, y + size/2);
    glEnd();
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!isNight) {  //sun

        drawCircle(150, 150, 50, 1.0f, 1.0f, 0.0f);
    }
    else {           //moon

        drawCircle(150, 150, 50, 0.9f, 0.9f, 0.9f);

        drawCircle(170, 150, 50, 0.0f, 0.0f, 0.2f);
    }

    //Ground
    drawSquare(0,-500,600,0,0.6,0);













    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Project");

    Background();

    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
