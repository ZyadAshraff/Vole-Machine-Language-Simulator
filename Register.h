//
// Created by HP on 10/31/2024.
//

#ifndef OOP_REGISTER_H
#define OOP_REGISTER_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


class Register {
private:
    int Size = 16;
    vector <string> registers;
public:
    Register();
    string getCell(string Address);
    void setCell(string Address,string HexaValue);
    void Print();
};


#endif //OOP_REGISTER_H
