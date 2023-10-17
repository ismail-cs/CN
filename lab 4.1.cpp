#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
    glEnd();
}

void rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b){
    glBegin(GL_POLYGON);       // line 1
	glColor3ub(r, g, b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glVertex2f(x4, y4);
        glVertex2f(x1, y1);
    glEnd();
}


void road (){

    rectangle(-50, 10, 25, -20, 35, 0, -40, 30, 255, 236, 0);

    rectangle(-45.5, 19, 29.5, -11, 30.5, -9, -44.5, 21, 255, 255, 255);

   // rectangle(-30.5, 14, 20.5, -11, 30.5, -9, -44.5, 21, 255, 255, 255);

    rectangle(-37, 4, -32.8, 2.2, -28.5, 10.3, -32.7, 12.3, 0,0,0);

    rectangle(-37, 4, -37.9, 2, -37.3, 1, -36, 4, 0,0,0);

    circle(1.2, -34, 4.5, 255, 0, 0);
    circle(1.2, -32.5, 7, 247, 255, 0);
    circle(1.2, -31.0, 9.5, 27, 255, 0);
}


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);


    road ();


    glFlush();  // Render now
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);// Set the window's initial width & height         // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    gluOrtho2D(-70.0, 70.0, -40.0, 40.0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}

