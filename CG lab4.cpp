#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <bits/stdc++.h>

using namespace std;


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

void lamppost (){

    circle(1.0, 52.5, 10, 234, 221, 14);
    circle(0.75, 52.5, 10, 255, 240, 0);

    glBegin(GL_POLYGON);  //red
	glColor3ub(255, 255, 255);

        glVertex2f(55.0, -8.75);
        glVertex2f(55.75, -8.75);

        glVertex2f(55.75, -8.75);
        glVertex2f(55.75, 8.75);

        glVertex2f(55.75, 8.75);
        glVertex2f(55.0, 8.75);

        glVertex2f(55.0, 8.75);
        glVertex2f(55.0, -8.75);

    glEnd();

    glBegin(GL_POLYGON);  //red
	glColor3ub(255, 255, 255);

        glVertex2f(51.75, 11.0);
        glVertex2f(56.5, 7.75);

        glVertex2f(56.5, 7.75);
        glVertex2f(56.5, 8.5);

        glVertex2f(56.0, 8.5);
        glVertex2f(52.75, 11.0);

        glVertex2f(52.75, 11.0);
        glVertex2f(51.75, 11.0);

    glEnd();

}






void house1(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b, float lr, float lg, float lb ){


    rectangle( x1, y1, x2, y2, x3, y3, x4, y4, r, g, b);  // main building

	float hight = sqrt( pow( abs(x2-x3), 2) + pow( abs(y2-y3), 2) );
	float width = sqrt( pow( abs(x1-x2), 2) + pow( abs(y1-y2), 2) );
	float distanceY = hight / 5;
	float distanceX = width / 3;
	float gap = (hight / 30)/2;
    float out = 0;
    float tmp =distanceY;

    for(int i=1; i<6; i++){             // line x

        distanceY = distanceY + out;

        float l1x1=x1;
        float l1y1=(y1+distanceY-gap);
        float l1x2=x2;
        float l1y2=(y2+distanceY-gap);
        float l1x3=x2;
        float l1y3=(y2+distanceY+gap);
        float l1x4=x1;
        float l1y4=(y1+distanceY+gap);

        rectangle( l1x1, l1y1, l1x2, l1y2, l1x3, l1y3, l1x4, l1y4, lr, lg, lb);
        out = tmp;
    }

    out = 0;
    tmp =distanceX;
    for(int i=1; i<3; i++){             // line y
        distanceX = distanceX + out;

        float l1x1=(x1+distanceX-gap);
        float l1y1=y1;
        float l1x2=(x1+distanceX+gap);
        float l1y2=y2;
        float l1x3=(x4+distanceX+gap);
        float l1y3=y3;
        float l1x4=(x1+distanceX-gap);
        float l1y4=y4;

        rectangle( l1x1, l1y1, l1x2, l1y2, l1x3, l1y3, l1x4, l1y4, lr, lg, lb);
        out = tmp;
    }

    rectangle( x1, y1, x1+(gap*2), y2, x4+(gap*2), y3, x4, y4, lr, lg, lb);  // sile line
    rectangle( x2-(gap*2), y1, x2, y2, x3, y3, x3-(gap*2), y3, lr, lg, lb);  // sile line
}


void tree(){

    glBegin(GL_POLYGON);  //red
	glColor3ub(106, 86, 25);

        glVertex2f(-1.5, -8.75);
        glVertex2f(1.5, -8.75);

        glVertex2f(1.5, -8.75);
        glVertex2f(1.0, 1.0);

        glVertex2f(1.0, 1.0);
        glVertex2f(-1.0, 1.0);

        glVertex2f(-1.0, 1.0);
        glVertex2f(-1.5, -8.75);

    glEnd();


    circle(2.5, -2, 0, 96, 198, 34);
    circle(2.5, 2, 0, 96, 198, 34);
    circle(2.5, -2.5, 2.75, 96, 198, 34);
    circle(2.5, 2.5, 2.75, 96, 198, 34);
    circle(2.5, 0, 3.75, 96, 198, 34);

}

void bench(){

    rectangle( 10.5, 4, 11.5, 4, 11.5, 16, 10.5, 16, 255, 99, 99);
    rectangle( 16, 7, 17, 7, 17, 20, 16, 20, 255, 99, 99);
    rectangle( 31, 4, 32, 4, 32, 16, 31, 16, 255, 99, 99);
    rectangle( 35, 7, 36, 7, 36, 20, 35, 20, 255, 99, 99);

    rectangle( 10.5, 16, 11.5, 16, 17, 17, 16, 18, 255, 99, 99);
    rectangle( 31, 16, 32, 16, 36, 17, 35, 18, 255, 99, 99);

    rectangle( 10.5, 12, 11.5, 12, 17, 13, 16, 15, 255, 99, 99);
    rectangle( 31,   12, 32,   12, 36, 13, 35, 15, 255, 99, 99);

    rectangle( 16, 19, 36, 19, 36, 20, 16, 20, 255, 99, 99);
    rectangle( 16, 14, 36, 14, 36, 15, 16, 15, 255, 99, 99);

    rectangle( 11.5, 11, 31, 11, 31, 12, 11.5, 12, 255, 99, 99);


}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    house1( -40, 0, -20, 0, -20, 30, -40, 30, 255, 255, 255, 0, 32, 255);
    rectangle( -33, 0, -27, 0, -27, 11.5, -33, 11.5, 255, 255, 255);



    lamppost ();

    tree();

    bench();


    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);// Set the window's initial width & height         // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    gluOrtho2D(-70.0, 70.0, -40.0, 40.0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
