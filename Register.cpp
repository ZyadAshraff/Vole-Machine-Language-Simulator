//
// Created by HP on 10/31/2024.
//

#include "Register.h"
Register::Register() {
    registers.resize(Size,"00");
}

string Register::getCell(string Address) {
    return registers[stoi(Address, nullptr, 16)];
}

void Register::setCell(string Address, string HexaValue) {
    registers[stoi(Address, nullptr, 16)] = HexaValue;
}

void Register::Print() {
    cout << "Register: ";
    for (auto item : registers){
        cout <<item <<' ';
    }
    cout << endl;
}
