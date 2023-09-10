#include <iostream>
#include <time.h>
#include <thread>
#include <math.h>
#include<float.h>
#include "console_3d_lib.h" 

bool exitProgram = 0;
camera C = *new camera();
frame Screen = *new frame(70, 30);


int main()
{
    printf("\e[?25l");
    //printf("s %d", 2);
     
    C.moveZ(-15000);


    // circle c = *new circle(6, 20, 10);
    // circle c2 = *new circle(1, 25, 30);

    model  m = *new model("thingy.obj");
    point  r = *new point(20, 0, 200);

    //c.addGravity();
    int i = 0;
    double speed = 2;
    while (!exitProgram) {
        C.moveZ(-5);
        i++;
        //TheLiteralVoid.LiterallyHoldEverythingTogether(); 
        m.rotate(r, speed / 5.0, -speed / 2.0, speed);
        // c.move();
        // c2.move();
         //Screen.drawCircle(c);
         //Screen.drawCircle(c2);
         /*
         Screen.drawPoly_3d(triangle,  C);
         Screen.drawPoly_3d(triangle2, C);
         Screen.drawPoly_3d(triangle3, C);
         Screen.drawPoly_3d(triangle4, C);
         */
        Screen.drawModel(m, C);

        Screen.show();
        Screen.clear();
        //std::cout << i;
        WaitForMs(10);
    }

    return 0;
}