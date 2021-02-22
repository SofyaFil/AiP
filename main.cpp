#include <GL/glut.h>
#include <math.h>
#include <ctime>
#include <vector>

struct Figure {
    float xs, ys ;
    float xt, yt ;
    float xr, yr ;
    float rc, gc, bc;
    float r, g, b;
};

/*
    место для творчества
*/
clock_t curTime, startTime;

Figure bg;
Figure lawn = {-.1,0.5,-.9,-.9,0,0,0,0,0,0,0,0};
std::vector <Figure> forest;

void drawCat(Figure cat);
void drawShip(Figure ship);
void drawHome(Figure home);
void drawTree(Figure tree);
void drawTrees(Figure trees);
void drawTres(Figure tres);
void drawTress(Figure tress);
void drawFon(Figure f);

void animateScene(int Value);

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна здесь жить


   drawFon(bg);

 //Фон

 //газон
    glBegin(GL_QUADS);
    glColor3f(.8,.7,.1);
    glVertex2f(1,-.3);
    glVertex2f(-1,-.3);
    glColor3f(.1,.9,.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();

 //море
    glBegin(GL_QUADS);
    glColor3f(.1,.2,.9);
    glVertex2f(1,-.3);
    glVertex2f(-1,-.3);
    glColor3f(.1,.2,.9);
    glVertex2f(-1,-.45);
    glVertex2f(.5,-.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.2,.9);
    glVertex2f(-.2,-.45);
    glVertex2f(-.3,-.65);
    glVertex2f(-1,-.55);
    glVertex2f(-1,-.45);
    glEnd();

 //песочек
    glBegin(GL_QUADS);
    glColor3f(.8,.7,.1);
    glVertex2f(-.3,-.75);
    glVertex2f(-1,-.65);
    glColor3f(.1,.2,.9);
    glVertex2f(-1,-.55);
    glVertex2f(-.2,-.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.2,.9);
    glVertex2f(1,-.3);
    glColor3f(.8,.7,.1);
    glVertex2f(1,-.55);
    glColor3f(.8,.7,.1);
    glVertex2f(-.4,-.65);
    glColor3f(.1,.2,.9);
    glVertex2f(-.4,-.4);
    glEnd();

    glPushMatrix();
    Figure ship;

    ship.xs=0.3;
    ship.ys=0.3;
    ship.xt=0.99;
    ship.yt=-1.6;
    ship.xr=0;
    ship.yr=0;

    drawShip(ship);
    glPopMatrix();

    glPushMatrix();
    Figure home;

    home.xs=.9;
    home.ys=.9;
    home.xt=-0.5;
    home.yt=-0.5;
    home.xr=0;
    home.yr=0;
    home.rc=9;
    home.gc=9;
    home.bc=9;

    drawHome(home);
    glPopMatrix();

    curTime=clock() - startTime;

    float x = 2.6, y=-4.6;

    if(curTime < 1000){
        y= -4.6 - 3 -(curTime-1000)*0.003;
    }else{
       if(curTime < 2000){
          x = 2.6 - (curTime-1000)*0.009;
          y = -2.6 - 5 ;
       }else{
           x=-2.1;
           y=-5.1;
           /*startTime= clock ();*/
       }
    }


    glPushMatrix();
    Figure cat;

    cat.xs=0.1;
    cat.ys=0.1;
    cat.xt=x;
    cat.yt=y;

    drawCat(cat);
    glPopMatrix();




    glPushMatrix();
    Figure tree;

    tree.xs=.4;
    tree.ys=.5;
    tree.xt=1.8;
    tree.yt=-1.6;

    drawTree(tree);
    glPopMatrix();

    glPushMatrix();
    Figure trees;

    trees.xs=.4;
    trees.ys=.5;
    trees.xt=1.5;
    trees.yt=-1.7;

    drawTrees(trees);
    glPopMatrix();

    glPushMatrix();
    Figure tres;

    tres.xs=.4;
    tres.ys=.5;
    tres.xt=2.1;
    tres.yt=-1.7;

    drawTres(tres);
    glPopMatrix();

    glPushMatrix();
    Figure tress;

    tress.xs=.4;
    tress.ys=.5;
    tress.xt=2.4;
    tress.yt=-1.6;

    drawTress(tress);
    glPopMatrix();


    // эта функция должна здесь жить
    glutSwapBuffers();
}

void drawFon(Figure f){
    glPushMatrix();
    curTime = clock();
    float phi = curTime*0.0003;
    float x = sin(phi), y = cos(phi), del = curTime*0.0001;

    if(y>0.2)
      f.r = 0.1, f.g = 0.6, f.b = 0.9;
        else if (y<0.2 & y>-0.2 & x>0)
          f.r = 1.0, f.g = 0.8, f.b = 0.3;
            else if (y<0.3 & y>-0.3 & x>0)
             f.r = 0.9, f.g = 0.5, f.b = 0.2;
              else if (y<0.4 & y>-0.4 & x>0)
                f.r = 0.6, f.g = 0.2, f.b = 0.4;
                 else if(y<-0.2)
                   f.r = 0.2, f.g = 0.0, f.b = 0.5;
                    else if(y<0.2 & y>-0.2 & x<0)
                     f.r = 0.9, f.g = 0.5, f.b = 0.1;
                       else if(y<0.3 & y>-0.3 & x<0)
                        f.r = 0.3, f.g = 0.4, f.b = 0.1;
                         else if(y<0.4 & y>-0.4 & x<0)
                          {f.r = 0.9,  f.g = 0.6, f.b = 0.2;}

    glBegin(GL_QUADS);
    glColor3f(f.r,f.g,f.b);
    glVertex2f(1.0,-0.3);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,-0.3);
    glEnd();

    glPushMatrix();
    glTranslatef(x,y,.0);
    glScalef(0.1,0.1,1.0);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(1.0,0.6,0.3);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
        glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();

}

void drawWindow(Figure w){
    glPushMatrix();
    curTime = clock();
      float r, g, b;

      if(curTime < 1000){
          (w.r = 0.9, w.g = 0, w.b = 0 );
       }else{
         startTime= clock ();
         }

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(w.r,w.g,w.b);
    glVertex2f(.1,.0);
    glVertex2f(.3,.0);
    glVertex2f(.3,-.2);
    glVertex2f(.1,-.2);
    glEnd();

    glPopMatrix();
    glEnd();
    glPopMatrix();

}

void animateScene(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/60, animateScene, 1);
}

void drawCat(Figure cat){
    glPushMatrix();
    glScalef(cat.xs, cat.ys, 0);
    glTranslatef(cat.xt,cat.yt,0);
    glRotated(cat.xr,cat.yr,1, 1);

//Лисичка
    glBegin(GL_TRIANGLES);

 //мордочка
    glColor3f(.8,.4,.1);
    glVertex2f(.3,.4);
    glVertex2f(-.3,.4);
    glVertex2f(.0,-.1);

 //правое ушко
    glColor3f(.8,.4,.1);
    glVertex2f(.2,.4);
    glVertex2f(.3,.4);
    glVertex2f(.1,.7);

 //левое ушко
    glColor3f(.8,.4,.1);
    glVertex2f(-.2,.4);
    glVertex2f(-.3,.4);
    glVertex2f(-.1,.7);

 //Тело
    glColor3f(.8,.4,.1);
    glVertex2f(.0,.1);
    glVertex2f(-.3,-.3);
    glVertex2f(.3,-.3);

    glColor3f(.8,.4,.1);
    glVertex2f(.0,-.7);
    glVertex2f(-.3,-.3);
    glVertex2f(.3,-.3);

 //Воротничок
    glColor3f(.9,.9,.9);
    glVertex2f(.0,.0);
    glVertex2f(0.15,-0.15);
    glVertex2f(-0.15,-0.15);

    glEnd();

    glPopMatrix();

}
void drawShip(Figure ship){
    glPushMatrix();
    glScalef(ship.xs,ship.ys, 0);
    glTranslatef(ship.xt,ship.yt,0);
    glRotated(ship.xr,ship.yr,1, 1);

//Кораблик
     //Основание
    glBegin(GL_QUADS);
    glColor3f(.8,.6,.2);
    glVertex2f(.2,.0);
    glVertex2f(-.2,.0);
    glVertex2f(-.2,-.2);
    glVertex2f(.2,-.2);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(.8,.6,.2);
    glVertex2f(.4,.0);
    glVertex2f(.2,.0);
    glVertex2f(.2,-.2);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(.8,.6,.2);
    glVertex2f(-.4,.0);
    glVertex2f(-.2,.0);
    glVertex2f(-.2,-.2);
    glEnd();

     //Мачта
    glBegin(GL_QUADS);
    glColor3f(.32,.3,.32);
    glVertex2f(0.015,.4);
    glVertex2f(-0.015,.4);
    glVertex2f(-0.015,.0);
    glVertex2f(0.015,.0);
    glEnd();

     //Парус
    glBegin(GL_TRIANGLES);
    glColor3f(.9,.9,.9);
    glVertex2f(-.2,.2);
    glVertex2f(-0.015,.4);
    glVertex2f(-0.015,.1);
    glEnd();

   glPopMatrix();
}
void drawHome(Figure home){
    glPushMatrix();
    glScalef(home.xs,home.ys, 0);
    glTranslatef(home.xt,home.yt,0);
    glRotated(home.xr,home.yr,1, 1);
    glColor3f(home.rc,home.gc,home.bc);


//Домик

    glBegin(GL_QUADS);
    glColor3f(.5,.5,.6);
    glVertex2f(.4,.1);
    glVertex2f(-.4,.1);
    glVertex2f(-.4,-.4);
    glVertex2f(.4,-.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.8,.5,.6);
    glVertex2f(.45,.1);
    glVertex2f(-.45,.1);
    glVertex2f(.0,.4);
    glEnd();

    float ct = cos(clock()*0.0003);

    glBegin(GL_QUADS);
    if(ct<-0.2){
        glColor3f(.9,.9,.1);
    } else {
        glColor3f(.9,.9,.9);
    }

    glVertex2f(.1,.0);
    glVertex2f(.3,.0);
    glVertex2f(.3,-.2);
    glVertex2f(.1,-.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.9,.7,.9);
    glVertex2f(.3,-0.16);
    glVertex2f(.1,-0.16);
    glVertex2f(.1,-0.13);
    glVertex2f(.3,-0.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.9,.7,.9);
    glVertex2f(0.2,-.2);
    glVertex2f(0.2,0);
    glVertex2f(0.17,0);
    glVertex2f(0.17,-.2);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(.9,.7,.9);
    glVertex2f(-.1,0.015);
    glVertex2f(-.3,0.015);
    glVertex2f(-.3,-.3);
    glVertex2f(-.1,-.3);
    glEnd();

   glPopMatrix();
}
void drawTree(Figure tree){
    glPushMatrix();
    glScalef(tree.xs,tree.ys, 0);
    glTranslatef(tree.xt,tree.yt,0);


//Ёлочка

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,.0);
   glVertex2f(.0,.3);
   glVertex2f(-.2,.0);

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,-.2);
   glVertex2f(.0,.1);
   glVertex2f(-.2,-.2);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(.7,.5,.3);
   glVertex2f(0.05,-.2);
   glVertex2f(-0.05,-.2);
   glVertex2f(-0.05,-.3);
   glVertex2f(0.05,-.3);
   glEnd();

   glPopMatrix();

}
void drawTrees(Figure trees){
    glPushMatrix();
    glScalef(trees.xs,trees.ys, 0);
    glTranslatef(trees.xt,trees.yt,0);

//Ёлочка

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,.0);
   glVertex2f(.0,.3);
   glVertex2f(-.2,.0);

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,-.2);
   glVertex2f(.0,.1);
   glVertex2f(-.2,-.2);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(.7,.5,.3);
   glVertex2f(0.05,-.2);
   glVertex2f(-0.05,-.2);
   glVertex2f(-0.05,-.3);
   glVertex2f(0.05,-.3);
   glEnd();

   glPopMatrix();

}
void drawTres(Figure tres){
    glPushMatrix();
    glScalef(tres.xs,tres.ys, 0);
    glTranslatef(tres.xt,tres.yt,0);

//Ёлочка

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,.0);
   glVertex2f(.0,.3);
   glVertex2f(-.2,.0);

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,-.2);
   glVertex2f(.0,.1);
   glVertex2f(-.2,-.2);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(.7,.5,.3);
   glVertex2f(0.05,-.2);
   glVertex2f(-0.05,-.2);
   glVertex2f(-0.05,-.3);
   glVertex2f(0.05,-.3);
   glEnd();

   glPopMatrix();

}
void drawTress(Figure tress){
    glPushMatrix();
    glScalef(tress.xs,tress.ys, 0);
    glTranslatef(tress.xt,tress.yt,0);

//Ёлочка

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,.0);
   glVertex2f(.0,.3);
   glVertex2f(-.2,.0);

   glBegin(GL_TRIANGLES);
   glColor3f(.0,.3,.0);
   glVertex2f(.2,-.2);
   glVertex2f(.0,.1);
   glVertex2f(-.2,-.2);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(.7,.5,.3);
   glVertex2f(0.05,-.2);
   glVertex2f(-0.05,-.2);
   glVertex2f(-0.05,-.3);
   glVertex2f(0.05,-.3);
   glEnd();

   glPopMatrix();


}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 0, Start");
    glutDisplayFunc(renderScene);
    glutTimerFunc(1000/60, animateScene,1);
    startTime = clock();
    glutMainLoop();
    return 0;
}
