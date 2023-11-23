#include<windows.h>

#include <GL/glut.h>
#include <cmath>

float ballPosY = 1.0f; // Initial position of the ball
float initialHeight = 1.0f; // Initial height of the ball drop
int numBounces = 0; // Number of times the ball has bounced

/*
void drawBall(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
    glEnd();
}
*/

void drawBall() {
    glColor3f(0.8f, 0.2f, 0.2f); // Red color for the ball
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(0.05f * cos(theta), 0.05f * sin(theta) + ballPosY);
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBall(); // Draw the ball
    //drawBall(1,0,0,255,150,34);

    glutSwapBuffers();
}

void update(int value) {
    // Simulate ball drop and bounce
    if (numBounces < 4) {
        ballPosY -= 0.01f; // Decrease height by 0.02 units (simulating gravity)

        if (ballPosY <= 0.0f) {
            ballPosY = 0.0f; // Prevent ball from going below the floor
            initialHeight *= 0.5f; // Reduce the height of subsequent bounces
            ballPosY += initialHeight; // Set the new height for the next bounce
            numBounces++;
        }
    }

    glutPostRedisplay();

    if (numBounces < 4) {
        glutTimerFunc(10, update, 0); // Update every 10 milliseconds
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bouncing Ball");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background color
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D Orthographic projection
    glutDisplayFunc(display);
    glutTimerFunc(1000, update, 0); // Start updating after 1 second delay
    glutMainLoop();
    return 0;
}
