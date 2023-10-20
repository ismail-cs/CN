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

    rectangle(-50, -40, 50, -40, 10, 20, -10, 20, 63, 63, 63);
    rectangle(-70, 20, 70, 20, 70, 40, -70, 40, 96, 221, 255);
    rectangle(-60, -40, -50, -40, -10, 20, -15, 20, 159, 159, 159);
    rectangle(50, -40, 60, -40, 15, 20, 10, 20, 159, 159, 159);

    rectangle(-70, -40, -60, -40, -15, 20, -70, 20, 64, 135, 43);
    rectangle(60, -40, 70, -40, 70, 20, 15, 20, 64, 135, 43);

    rectangle(-1, -40, 1, -40, 1, 20, -1, 20, 255, 255, 255);
    rectangle(-2, -40, 2, -40, 2, -37, -2, -37, 63, 63, 63);
    rectangle(-2, -33, 2, -33, 2, -30, -2, -30, 63, 63, 63);
    rectangle(-2, -26, 2, -26, 2, -23, -2, -23, 63, 63, 63);
    rectangle(-2, -19, 2, -19, 2, -16, -2, -16, 63, 63, 63);
    rectangle(-2, -12, 2, -12, 2, -9, -2, -9, 63, 63, 63);
    rectangle(-2, -5, 2, -5, 2, -2, -2, -2, 63, 63, 63);
    rectangle(-2, 2, 2, 2, 2, 5, -2, 5, 63, 63, 63);
    rectangle(-2, 9, 2, 9, 2, 12, -2, 12, 63, 63, 63);
    rectangle(-2, 16, 2, 16, 2, 19, -2, 19, 63, 63, 63);

    rectangle(-47.5, -30, -45.5, -30, -45.5, 18, -47.5, 18, 0, 0, 0);

    rectangle(-47.5, 18, -32, 18, -32, 17, -47.5, 17, 0, 0, 0);

    rectangle(-36, 13, -18, 13, -18, 22, -36, 22, 0, 0, 0);
    rectangle(-35.5, 13.5, -18.5, 13.5, -18.5, 21.5, -35.5, 21.5, 255, 255, 255);
    rectangle(-35, 14, -19, 14, -19, 21, -35, 21, 0, 0, 0);



    circle(2, -32, 17.5, 255, 0, 0);
    circle(2, -27, 17.5, 254, 255, 0);
    circle(2, -22, 17.5, 60, 255, 0);
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
