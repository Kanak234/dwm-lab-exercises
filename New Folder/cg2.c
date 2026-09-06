#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float startX, startY, endX, endY;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3.0f);

    float dx = endX - startX;
    float dy = endY - startY;
    float steps = fmaxf(fabsf(dx), fabsf(dy));

    glBegin(GL_POINTS);

    if (steps == 0)
    {
        glVertex2f(startX, startY);
    }
    else
    {
        float x = startX;
        float y = startY;
        float xinc = dx / steps;
        float yinc = dy / steps;

        for (int i = 0; i <= (int)steps; i++)
        {
            glVertex2f(x, y);
            x += xinc;
            y += yinc;
        }
    }

    glEnd();
    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    printf("Enter the start coordinates (x y): ");
    scanf("%f %f", &startX, &startY);

    printf("Enter the end coordinates (x y): ");
    scanf("%f %f", &endX, &endY);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DDA Line Drawing Algorithm");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
