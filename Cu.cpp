//
// Created by HP on 11/2/2024.
//

#include "Cu.h"


void Cu::load(string instruction, memory& Memory, Register& aRegister) {
    string value = Memory.getCell(instruction.substr(2,2));
    aRegister.setCell(instruction.substr(1, 1), value);
}

void Cu::load(string instruction, Register& aRegister) {
    aRegister.setCell(instruction.substr(1, 1), instruction.substr(2, 2));

}

void Cu::store(string instruction, memory& Memory, Register& aRegister) {
    string value = aRegister.getCell(instruction.substr(1,1));
    Memory.setCell(instruction.substr(2,2),value);
}

void Cu::move(string instruction, Register &aRegister) {
    string value = aRegister.getCell(instruction.substr(2,1));
    aRegister.setCell(instruction.substr(3,1),value);
}

void Cu::jump(string instruction, Register &aRegister, int& PC, string location) {
    string register_0 = aRegister.getCell("0");
    string register_x = aRegister.getCell(instruction.substr(1,1));

    int getIndex = stoi(location, nullptr, 16);
    if (stoi(register_0, nullptr, 16) == stoi(register_x, nullptr, 16)){
        PC = (stoi(instruction.substr(2,2), nullptr, 16)-getIndex) / 2;
        PC --;
    }
}

void Cu::halt() {
    exit(0);
}

