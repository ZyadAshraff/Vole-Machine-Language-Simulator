//
// Created by HP on 11/2/2024.
//

#ifndef OOP_ALU_H
#define OOP_ALU_H

#include <bits/stdc++.h>
#include "Register.h"
using namespace std;

class Alu {
public:
    explicit Alu();
    string decimalToHex(int decimal);
    bool isValid(string instruction);
    string hexToBin(string& hex);
    int binToDec(string& binary);
    double hexToFloat(string&hex);
    string floatingAdd(string instruction, Register&aRegister);
    void Add(string instruction , Register& aRegister);
    int twoComplement(int number);
    string addOne(string binary);
private:
    map<char,int> hexMap;
    map<char,int> instructions;

};


#endif //OOP_ALU_H
