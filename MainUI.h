//
// Created by zyada on 11/2/2024.
//

#ifndef ASSIGN_1_T4_MAINUI_H
#define ASSIGN_1_T4_MAINUI_H
#include "Machine.h"
#include "CPU.h"

class MainUI {
private:
    Machine machine;
    bool enterFileOrInstructions;
    map<char,int>hexMap;
public:
    void displayMenu();
    void inputFileName();
    string inputInstruction();
    char inputChoice();

};


#endif //ASSIGN_1_T4_MAINUI_H
