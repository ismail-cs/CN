#include<windows.h>
#include <GL/glut.h>

float box1PosX = -0.5f; // Initial position of box 1
float box2PosX = 0.5f;  // Initial position of box 2
float speed = 0.005f;   // Speed of movement

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Box 1
    glColor3f(0.3f, 0.5f, 1.0f); // Set color to blue
    glBegin(GL_QUADS);
    glVertex2f(box1PosX, -0.1f);
    glVertex2f(box1PosX + 0.2f, -0.1f);
    glVertex2f(box1PosX + 0.2f, 0.1f);
    glVertex2f(box1PosX, 0.1f);
    glEnd();

    // Box 2
    glColor3f(1.0f, 0.5f, 0.3f); // Set color to orange
    glBegin(GL_QUADS);
    glVertex2f(box2PosX, -0.1f);
    glVertex2f(box2PosX + 0.2f, -0.1f);
    glVertex2f(box2PosX + 0.2f, 0.1f);
    glVertex2f(box2PosX, 0.1f);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    // Update positions
    box1PosX += speed;
    box2PosX -= speed;

    // Check for boundary conditions
    if (box1PosX > 1.0f || box1PosX < -1.0f) {
        speed = -speed; // Reverse direction for box 1
    }

    glutPostRedisplay(); // Render scene
    glutTimerFunc(10, update, 0); // Call update function after 10 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Two Moving Boxes");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0); // Call update function after 10 milliseconds
    glutMainLoop();
    return 0;
}
