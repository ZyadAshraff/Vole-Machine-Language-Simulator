#include<windows.h>
#include "MainUI.h"
using namespace std;

// for colorful CLI
void color(int color_value){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,color_value);
}

int main() {
    MainUI mainUI;
    color(0x0D);
    mainUI.displayMenu();
    mainUI.inputFileName();
}