#include<windows.h>

#include <GL/glut.h>
#include <cmath>

float bladeAngle = 0.0f; // Initial rotation angle for blades
float bladeSpeed = 2.0f; // Rotation speed for blades

void drawWindmill() {
    // Main post
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray color for the post
    glLineWidth(4.0f); // Set line width
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.8f); // Bottom of the post
    glVertex2f(0.0f, 0.0f); // Top of the post
    glEnd();

    // Blades at the center of the screen
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for blades

    // Draw each blade with rotation
    for (int i = 0; i < 4; ++i) {
        glPushMatrix(); // Save current matrix
        glTranslatef(0.0f, 0.0f, 0.0f); // Translate to the center of the window
        glRotatef(bladeAngle + i * 90.0f, 0.0f, 0.0f, 1.0f); // Apply rotation to the blades

        // Draw blade
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.4f, 0.1f);
        glVertex2f(0.4f, -0.1f);
        glEnd();

        glPopMatrix(); // Restore previous matrix
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawWindmill(); // Draw the windmill

    glutSwapBuffers();
}

void update(int value) {
    bladeAngle += bladeSpeed; // Rotate the blades

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Windmill with Rotating Blades at Center");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background color
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D Orthographic projection
    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0);
    glutMainLoop();
    return 0;
}
