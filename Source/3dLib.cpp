#include <iostream>
#include <time.h>
#include <thread>
#include <math.h>
#include<float.h>
#include "console_3d_lib.h" 

#define _CRT_SECURE_NO_WARNINGS
 
#include <vector> 
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <cwchar> 

bool exitProgram = 0;
camera C = *new camera();
frame Screen = *new frame(70, 45 );





HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
INPUT_RECORD InputRecord;
DWORD Events;
COORD coord;
CONSOLE_CURSOR_INFO cci;
CONSOLE_SCREEN_BUFFER_INFO SBInfo;
COORD NewSBSize;
int Status;
unsigned int FONT_SIZE;

HWND consoleH;
RECT r;

const bool MWHEEL_UP = true;
const bool MWHEEL_DOWN = false;

bool lmDown;

 

float fx;
int fy;


model m = *new model("ship.obj", 180);;

void changeFontSize(int size) {


    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = size;                   // Width of each character in the font
    cfi.dwFontSize.Y = size;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    //std::wcscpy(cfi.FaceName, L"Cascadia Code"); // FONT MUST ENABLE UNICODE
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    FONT_SIZE = size;

    fx = size / 2;
    fy = cfi.dwFontSize.Y;


    GetConsoleScreenBufferInfo(hOut, &SBInfo);
    int width = SBInfo.srWindow.Right - SBInfo.srWindow.Left + 1;
    int height = SBInfo.srWindow.Bottom - SBInfo.srWindow.Top + 1;



};





void lMouseClicked() {};

void rMouseClicked() {};

void mouseScrolled(bool dir) {};

void gameLoop() {

    bool exit = false;
    while (!exit) {





        wprintf(L"\033[?25l");

        //GetConsoleScreenBufferInfo(hOut, &SBInfo);
        NewSBSize.X = SBInfo.dwSize.X;
        NewSBSize.Y = SBInfo.dwSize.Y;

        Status = SetConsoleScreenBufferSize(hOut, NewSBSize);

        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
        ReadConsoleInput(hIn, &InputRecord, 1, &Events);

        if (InputRecord.EventType == MOUSE_EVENT) {
            if (InputRecord.Event.MouseEvent.dwEventFlags == MOUSE_WHEELED) {//FROM_LEFT_1ST_BUTTON_PRESSED) {

                if ((InputRecord.Event.MouseEvent.dwButtonState >> 24) == 0) {


                    //Scroll in logic

                    mouseScrolled(MWHEEL_UP);

                }
                else if ((InputRecord.Event.MouseEvent.dwButtonState >> 24) == 255) {

                    //scroll down logic
                    mouseScrolled(MWHEEL_DOWN);
                }


            }
            else if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {

                if (lmDown == false || 1) {
                    lMouseClicked();
                }
                lmDown = true;
            }
            if (InputRecord.Event.MouseEvent.dwButtonState == 0x0000 && lmDown == true) {
                lmDown = false;
            }
        }
        ShowScrollBar(consoleH, SB_BOTH, FALSE); 

    }

}
void setUpMouseInfo() {


    ShowScrollBar(consoleH, SB_BOTH, FALSE);
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);
    SetConsoleMode(hIn, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}



float characterSpeed = 0.6;
void findKeys() {
    if (GetKeyState(' ') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveY(-characterSpeed);
    }
    else if (GetKeyState('Z') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveY(characterSpeed);
    }
    if (GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveZ(characterSpeed);
    }
    else if (GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveZ(-characterSpeed);
    }
    if (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveX(characterSpeed);
    }
    else if (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        C.moveX(-characterSpeed);
    }
    if (GetKeyState('Q') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        m.rotate(C.getPoint(), 0, 0, -0.1);
    }
    else if (GetKeyState('E') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        m.rotate(C.getPoint(), 0, 0, 0.1);
    }
}




int main()
{

    changeFontSize(7);

    printf("\033[?25l");


    // circle c = *new circle(6, 20, 10);
    // circle c2 = *new circle(1, 25, 30);
    Screen.addModelToRenderStack(m);


    point  r = *new point(0, 0, 450);

    m.rotate(point(0, 20, 55), -45, 0, 0);
    //C.moveZ(25);
    //c.addGravity();
    float i = 0;
    int n = 0;
    double speed = 0.04;
    while (!exitProgram && n < 100000) {
        //C.moveZ(0.01
        i += speed;
        n += 1;
        //TheLiteralVoid.LiterallyHoldEverythingTogether(); 
        if (i < 360 * 99) {
            // m.rotate(r, 0, 0, speed);
        }
        else if (i < 2 * 360) {
            // m.rotate(r, 0, speed, 0);
        }
        else if (i < 3 * 360) {
            //m.rotate(r, speed, 0, 0);
        }
        else {
            i = 0;
            speed *= 1.1;
        }
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
         // Screen.drawModel(m, C);

        Screen.drawRenderStack(C);

        Screen.show();
        Screen.clear();
        //std::cout << i;
        WaitForMs(1);
        findKeys();
    }

    Screen.clear();

    return 0;
}
