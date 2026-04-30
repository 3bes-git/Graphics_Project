#include <GL/glut.h>
#include<math.h>


void Background() {

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}
void keyboard(unsigned char key, int x, int y)
{

    if (key == 'n' || key == 'N') glClearColor(0.0f, 0.0f, 0.3f, 1.0f); //night

    if (key == 'l' || key == 'L') glClearColor(0.5f, 0.8f, 1.0f, 1.0f); //light


    if (key == 27) exit(0);

    glutPostRedisplay();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);





    glFlush();
}

void create_window(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Project");
    Background();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}

int main(int argc, char *argv[])
{
    create_window(argc, argv);
    return 0;
}

