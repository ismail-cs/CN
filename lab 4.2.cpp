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

void tangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b){
    glBegin(GL_POLYGON);       // line 1
	glColor3ub(r, g, b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x3, y3);
        glVertex2f(x1, y1);
    glEnd();
}


void house (){

    rectangle(-10, 0, 10, 0, 10, 15, -10, 15, 159, 159, 159);
    rectangle(10, 0, 35, 0, 35, 15, 10, 15,149, 145, 140);
    rectangle(10, 15, 35, 15, 25, 25, 0, 25,150, 104, 33);
    tangle(-10, 15, 10, 15, 0, 25, 177, 124, 41);
    rectangle(20, 0, 25, 0, 25, 10, 20, 10, 94, 97, 96);
    rectangle(-3, 6, 1, 6, 1, 11, -3, 11, 94, 97, 96);
    rectangle(13, 7, 17, 7, 17, 11, 13, 11, 94, 97, 96);
    rectangle(28, 7, 32, 7, 32, 11, 28, 11, 94, 97, 96);

}


void tree1(){



    rectangle(-23, 0, -17, 0, -18.5, 15, -21.5, 15,129, 109, 42);

    circle(4, -15, 17, 26, 171, 0);
    circle(4, -18, 17, 33, 217, 0);

    circle(4, -23, 17, 33, 217, 0);
    circle(4, -25, 17, 26, 171, 0);

    circle(4, -28, 21.5, 30, 200, 0);

    circle(4, -23, 21.5, 28, 183, 0);
    circle(4, -18, 21.5, 28, 183, 0);

    circle(4, -13, 21.5, 30, 190, 0);

    circle(4, -15, 25.5, 28, 184, 0);

    circle(4, -26.5, 26,  55, 191, 30);

    circle(4, -22, 25.5, 28, 184, 0);

    circle(4, -19, 26.5, 28, 184, 0);

}

void tree2(){

    rectangle(-43, 0, -37, 0, -38.5, 15, -41.5, 15,129, 109, 42);

    circle(4, -35, 17, 26, 171, 0);
    circle(4, -38, 17, 33, 217, 0);

    circle(4, -43, 17, 33, 217, 0);
    circle(4, -45, 17, 26, 171, 0);

    circle(4, -48, 21.5, 30, 200, 0);

    circle(4, -43, 21.5, 28, 183, 0);
    circle(4, -38, 21.5, 28, 183, 0);

    circle(4, -33, 21.5, 30, 190, 0);

    circle(4, -35, 25.5, 28, 184, 0);

    circle(4, -46.5, 26,  55, 191, 30);

    circle(4, -42, 25.5, 28, 184, 0);

    circle(4, -39, 26.5, 28, 184, 0);
    circle(4, -42, 28.5, 28, 184, 0);

}

void sky(){

    rectangle(-70, 20, 70, 20, 70, 40, -70, 40, 145, 180, 255);
}


void sun(){

    circle(5.5, 35, 33, 245, 255, 0);

}


void cloud(){

    circle(2, 17, 33, 255, 255, 255);
    circle(2, 15, 33, 255, 255, 255);
    circle(3, 14, 34.5, 255, 255, 255);
    circle(2, 12, 33, 255, 255, 255);

    circle(2, 7, 33, 255, 255, 255);
    circle(2, 5, 33, 255, 255, 255);
    circle(3, 4, 34.5, 255, 255, 255);
    circle(2, 6, 34.5, 255, 255, 255);
    circle(2, 2, 33, 255, 255, 255);
}



void fild(){

    rectangle(-70, -40, 70, -40, 70, 20, -70, 20, 113, 167, 91);

}
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */




/* Main function: GLUT runs as a console application starting at main()  */




/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);


    sky();

    fild();

    cloud();

    house ();

    tree1();

    tree2();

    sun();



    //moon();


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
