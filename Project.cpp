#include <GL/glut.h>
#include <math.h>

bool isNight = false;
float angle = 0.0f;

void Background() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); //Day
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450, 450, -300, 300); //900*600
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


void drawHouse(float x, float y)
{
    //Main Square
    glColor3f(0.96f, 0.87f, 0.70f);
    glBegin(GL_QUADS);
        glVertex2f(x-60, y);
        glVertex2f(x+60, y);
        glVertex2f(x+60, y+80);
        glVertex2f(x-60, y+80);
    glEnd();

    //Triangle
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x-80, y+80);
        glVertex2f(x+80, y+80);
        glVertex2f(x, y+140);
    glEnd();

    //Door
    glColor3f(0.25f, 0.13f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(x-15, y);
        glVertex2f(x+15, y);
        glVertex2f(x+15, y+50);
        glVertex2f(x-15, y+50);
    glEnd();
    if (isNight) {
        glColor3f(1.0f, 1.0f, 0.0f);
    } else {
        glColor3f(0.7f, 0.9f, 1.0f);
    }

    //L window
    glBegin(GL_QUADS);
        glVertex2f(x-45, y+40);
        glVertex2f(x-20, y+40);
        glVertex2f(x-20, y+65);
        glVertex2f(x-45, y+65);
    glEnd();

    //R window
    glBegin(GL_QUADS);
        glVertex2f(x+20, y+40);
        glVertex2f(x+45, y+40);
        glVertex2f(x+45, y+65);
        glVertex2f(x+20, y+65);
    glEnd();
}

void timer(int v) {
    angle += 2.0f;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if (!isNight) {
        drawCircle(300, 200, 50, 1.0f, 1.0f, 0.0f);
    } else { //moon
        drawCircle(300, 200, 50, 0.9f, 0.9f, 0.9f);
        drawCircle(320, 200, 50, 0.0f, 0.0f, 0.2f);
    }

    //Ground
      glColor3f(0, 0.6, 0);
    glBegin(GL_QUADS);
        glVertex2f( -450, -1050);
        glVertex2f(450, -1050);
        glVertex2f(450, -150);
        glVertex2f(-450, -150);
    glEnd();

    //Houses
    drawHouse(140, -200);
    drawHouse(340, -200);

    //Tree
     glColor3f(0.25f, 0.13f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-60, -40);
        glVertex2f(-40, -40);
        glVertex2f(-40, -200);
        glVertex2f(-60, -200);
    glEnd();
        drawCircle(-50,-60,40,0,0.6,0);

    //Windmill

    glPushMatrix();
    glTranslatef(50, 0, 0);


      glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-269, 1);
        glVertex2f(-351, 1);
        glVertex2f(-351, -199);
        glVertex2f(-269, -199);
    glEnd();
      glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-270, 0);
        glVertex2f(-350, 0);
        glVertex2f(-350, -200);
        glVertex2f(-270, -200);
    glEnd();
     glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-360, 0);
        glVertex2f(-260, 0);
        glVertex2f(-310, 60);
    glEnd();

      glColor3f(0.25f, 0.13f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-285, -200);
        glVertex2f(-330, -200);
        glVertex2f(-330, -140);
        glVertex2f(-285, -140);
    glEnd();

      glPushMatrix();
    glTranslatef(-310, 20, 0);
    glRotatef(angle, 0, 0, 1);
  glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 4; i++) {
        glRotatef(90, 0, 0, 1);
        glBegin(GL_QUADS);
            glVertex2f(-5, 0); glVertex2f(5, 0);
            glVertex2f(5, 100); glVertex2f(-5, 100);
        glEnd();
    }
    glPopMatrix();
    glPopMatrix();



    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Project");

    Background();

    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
