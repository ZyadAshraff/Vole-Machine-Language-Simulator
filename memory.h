//
// Created by HP on 10/31/2024.
//

#ifndef OOP_MEMORY_H
#define OOP_MEMORY_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


class memory {
private:
    int Size = 256;
    vector <string> Memory;
public:
    memory();
    string getCell(string Address);
    void setCell(string Address,string HexaValue);
    void Print();
};


#endif //OOP_MEMORY_H
