#include<windows.h>
#include <GL/glut.h>
#include <cmath>

float carPosX = 0.0f; // Car's initial position
float wheelAngle = 0.0f; // Initial rotation angle for wheels
float wheelSpeed = 2.0f; // Rotation speed for wheels

void drawCar() {
    // Car body
    glColor3f(0.8f, 0.2f, 0.2f); // Red color for the car body
    glBegin(GL_QUADS);
    glVertex2f(carPosX - 0.3f, -0.1f);
    glVertex2f(carPosX + 0.3f, -0.1f);
    glVertex2f(carPosX + 0.2f, 0.1f);
    glVertex2f(carPosX - 0.2f, 0.1f);
    glEnd();

    // Wheels
    glPushMatrix(); // Save current matrix
    glColor3f(0.1f, 0.1f, 0.1f); // Black color for wheels
    glTranslatef(carPosX - 0.2f, -0.1f, 0.0f); // Translate to the position of the first wheel
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation to the wheel
    glutSolidTorus(0.05, 0.1, 20, 20); // Draw first wheel
    glPopMatrix(); // Restore previous matrix

    glPushMatrix(); // Save current matrix
    glTranslatef(carPosX + 0.2f, -0.1f, 0.0f); // Translate to the position of the second wheel
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation to the wheel
    glutSolidTorus(0.05, 0.1, 20, 20); // Draw second wheel
    glPopMatrix(); // Restore previous matrix
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawCar(); // Draw the car

    glutSwapBuffers();
}

void update(int value) {
    carPosX += 0.01f; // Move the car
    wheelAngle += wheelSpeed; // Rotate the wheels

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car with Rotating Wheels");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background color
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D Orthographic projection
    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0);
    glutMainLoop();
    return 0;
}
