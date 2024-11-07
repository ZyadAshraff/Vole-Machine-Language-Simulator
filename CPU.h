//
// Created by zyada on 11/2/2024.
//

#ifndef ASSIGN_1_T4_CPU_H
#define ASSIGN_1_T4_CPU_H
#include <iostream>
#include <string>
#include <fstream>
#include "Register.h"
#include "Alu.h"
#include "Cu.h"
using namespace std;

class CPU {
private:
    int PC;
    vector<string>instructs;
    Register reg;
    memory mem;
    Alu alu;
    Cu cu;
    string location;
    vector<string> HexaPrint;
    vector<char> AsciiPrint;
public:
    void setLocation(const string &location);
    CPU() : PC(0) {}
    int getPC();
    void fetch(ifstream& file, vector<string>& instructions);
    void decode_execute1(ifstream& file);
    void decode_execute2(ifstream& file);


};


#endif //ASSIGN_1_T4_CPU_H
