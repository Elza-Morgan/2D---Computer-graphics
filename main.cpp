
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>


void display();
void reshape(int w, int h );
void timer(int);
int y=0;//for lamp
int x=0.1;//for eyes
int z=0; //for top
//float d=0;
int q=1; //for size of lamp cicle play for 90/270 or  0/360/180
float a=10;
static bool rotation = true;
void init()
{

    glClearColor(1,1,1,1);
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

        /*windows change*/
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("Elza-18100260,Youssef-18102698,Ahmed-18101475, Monster House");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
     init();

    glutMainLoop();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(3);

    /*Thats the road*/
            glBegin(GL_POLYGON);
            glColor3f(0,0,0);
            glVertex2f(-25,-25);
            glVertex2f(25,-25);
            glVertex2f(25,-11);
            glVertex2f(-25,-11);
            glEnd();
            glFlush();

  glBegin(GL_POLYGON);
//down frame should be gray (road lines) (left)
           glColor3f(1,1,1);

            glVertex2f(-10,-16);
            glVertex2f(-20,-16);
             glVertex2f(-20,-20);
             glVertex2f(-10,-20);

glEnd();
glFlush();
glBegin(GL_POLYGON);  //down frame should be gray (road lines) (right)
           glColor3f(1,1,1);
            glVertex2f(10,-16);
            glVertex2f(20,-16);
            glVertex2f(20,-20);
            glVertex2f(10,-20);


glEnd();
glFlush();




 glBegin(GL_POLYGON);  //middle road frame should be yellow
           glColor3f(1,0.8,0);

    glVertex2f(-25,-11);
    glVertex2f(25,-11);
    glVertex2f(25,0);
    glVertex2f(-25,0);

glEnd();
glFlush();

glBegin(GL_LINES);  // lines of middle road
glColor3f(0,0.7,0);
    glVertex2f(20,-11);
    glVertex2f(20,-10);
    glVertex2f(10,-11);
    glVertex2f(10,-10);
    glVertex2f(0,-11);
    glVertex2f(0,-10);
glVertex2f(-10,-11);
    glVertex2f(-10,-10);
    glVertex2f(-20,-11);
    glVertex2f(-20,-10);
    glEnd();
    glFlush();

    //The Land
    glBegin(GL_POLYGON);
           glColor3f(0.2, 0.439, 0.219);

         glVertex2f(-25,20);
        glVertex2f(25,20);
        glVertex2f(25,-10);
        glVertex2f(-25,-10);
glEnd();
glFlush();
 /*The sky which is blue*/
glBegin(GL_POLYGON);
           glColor3f(0.58,0.8,0.9);

    glVertex2f(-25,15);
    glVertex2f(25,15);
    glVertex2f(25,25);
     glVertex2f(-25,25);
glEnd();
glFlush();


    /*This is used to draw the square*/
    glBegin(GL_POLYGON);
    glColor3f(0.639, 0.650, 0.431);
    glVertex2f(-5,-10);
    glVertex2f(5,-10);
    glVertex2f(5,5);
    glVertex2f(-5,5);
    glEnd();
    glFlush();

    /*The triangle above the square*/
    /*left-bottom,right-bottom,right-top,left-top, the points are drawn in this order*/
    glBegin(GL_TRIANGLES);
    glColor3f(0.956, 0.796, 0.501);
    glVertex2f(-5,5);
    glVertex2f(5,5);
    glVertex2f(0,15);
    glEnd();
    glFlush();

     /*The outline for square*/
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
   glVertex2f(5,5);
    glVertex2f(-5,5);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(-5,-10);
    glVertex2f(5,-10);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(-5,5);
    glVertex2f(-5,-10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(5,5);
    glVertex2f(5,-10);
    glEnd();

    /*outline for triangle*/
     glBegin(GL_LINES);
    glColor3f(1, 0, 1);
    glLineWidth(10);
    glVertex2f(-z-5,5); //animated from the both sides
    glVertex2f(0,15);
    glEnd();

       glBegin(GL_LINES);
    glColor3f(1, 0, 1);
    glLineWidth(10);
    glVertex2f(z+5,5);
    glVertex2f(0,15);
    glEnd();

    /*Rectangle is used to draw the door*/

       glBegin(GL_POLYGON);

    glColor3f(0.243, 0.176, 0.058);
    glVertex3f(-1.5,-10,0.0);
    glVertex3f(1.5,-10,0.0);
    glVertex3f(1.5,-3,0.0);
    glVertex3f(-1.5,-3,0.0);


    glEnd();
    glFlush();

    /*circle is used for the door knob*/
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
        for(int i=1; i<360; i++)
        {
            double angle=i*3.14/180;
            /*animated*/
            glVertex2f(0.3*cos(angle)+1, 0.3*sin(angle)-6.5);
        }
        z--;
        if(z<-1.8)
        {
            z=0;
        }

    glEnd();
  /*windows as i oval left */

     glBegin(GL_POLYGON);
    glColor3f(0,0,1);
        for(int i=1; i<360; i++)
        {
            double angle=i*3.14/180;
            glVertex2f(1.3*cos(angle)-2.5, 0.9*sin(angle)+0);
        }


    glEnd();

    /*windows as oval right */
     glBegin(GL_POLYGON);
    glColor3f(0,0,1);
        for(int i=1; i<360; i++)
        {
            double angle=i*3.14/180;
            glVertex2f(1.3*cos(angle)+2.5, 0.9*sin(angle)-0);
        }


    glEnd();


    /*drawing lines in the triangle*/

         glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(-3,5);
    glVertex2f(0,15);
    glEnd();

         glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(3,5);
    glVertex2f(0,15);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(10);
    glVertex2f(0,5);
    glVertex2f(0,15);
    glEnd();


    /*eyeballs in the window for right side*/
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
        for(int i=1; i<360; i++)
        {
            double angle=i*3.14/180;
           //animated
            glVertex2f(x+0.3*cos(angle)-2.5, 0.3*sin(angle)+0);
        }

    glEnd();

      /*eyeballs in the window for left side*/
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
        for(int i=1; i<360; i++)
        {
            double angle=i*3.14/180;
             //animated
            glVertex2f(x+0.3*cos(angle)+2.5, 0.3*sin(angle)-0);
        }
        x++;
if(x>=1.3)
{
    x=-1;
}

    glEnd();


   /*the straight line coming out of the house horizontalLy */
         glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-5,-10);
    glVertex2f(-10,-10);
    glEnd();

    /*doing lap stand*/

      glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-9,-10);
    glVertex2f(-9,-1);
    glEnd();

/* doing the light/plate effect*/
    glBegin(GL_POLYGON);

    glColor3f(0.996, 1, 0.058);

        for(int i=1; i<360; i++)
        {
             double angle=i*3.14/180;
            ///////////rotated // 1 in y change to q to change size of circle
            glVertex2f(1.3*cos(angle)-9,1*sin(y+angle));
   }

        if (rotation) {
            y +=90;
            if (y > 360&&y!=180) {
            y=90;
            }
        }
    glEnd();
    glFlush();
glPopMatrix();


        //right cloud

    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+6.5,1.5*sin(angle)+23);

    }
    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+4.8,1.5*sin(angle)+23);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+3.8,1.5*sin(angle)+21.7);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+4.8,1.5*sin(angle)+21);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+6.5,1.5*sin(angle)+21);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)+7.7,1.5*sin(angle)+21.7);

    }
    glEnd();

//left cloud

glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-6.5,1.5*sin(angle)+21);

    }
    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-4.8,1.5*sin(angle)+21);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-3.8,1.5*sin(angle)+19.7);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-4.8,1.5*sin(angle)+19);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-6.5,1.5*sin(angle)+19);

    }
    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.815, 0.843, 0.862);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(1.5*cos(angle)-7.7,1.5*sin(angle)+19.7);

    }
    glEnd();



//SUN
    glBegin(GL_POLYGON);

    glColor3f(0.925, 0.709, 0.317);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(2*cos(angle)-24,3*sin(angle)+24);

    }
    glEnd();

    //FIRST LINE TOP
    glBegin(GL_LINES);

    glColor3f(0.925, 0.709, 0.317);
    glVertex2f(-23,23);
    glVertex2f(-20,20);
    glEnd();

    //SECOND LINE MIDDLE
     glBegin(GL_LINES);

    glColor3f(0.925, 0.709, 0.317);
    glVertex2f(-25,25);
    glVertex2f(-20,24);
    glEnd();

    //THRID LINE FROM BELOW
    glBegin(GL_LINES);

    glColor3f(0.925, 0.709, 0.317);
    glVertex2f(-24,22);
    glVertex2f(-23,19);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.290, 0.827, 0.329);

    for(int i=0;i< 360;i++){
        double angle=i*3.14/180;
            glVertex2f(3*cos(angle)+14.5,3*sin(angle)+3);

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.650, 0.454, 0.149);
    glVertex2f(14,-10);
    glVertex2f(15,-10);
    glVertex2f(15,0);
    glVertex2f(14,0);
    glEnd();
    glFlush();



    glutSwapBuffers();


}

void reshape(int width, int height)
{
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


gluOrtho2D(-25,25,-25,25);
     glMatrixMode(GL_MODELVIEW);

}
void timer(int){

    glutPostRedisplay();

  glutTimerFunc(1000/3, timer, 0);

}

