//
// Created by HP on 10/31/2024.
//

#include "memory.h"

memory::memory() {
    Memory.resize(Size,"00");
}

string memory::getCell(string Address) {
    return Memory[stoi(Address, nullptr, 16)];
}

void memory::setCell(string Address, string HexaValue) {
    Memory[stoi(Address, nullptr, 16)] = HexaValue;
}

void memory::Print() {
    cout << "Memory: \n";
    for(int i = 0 ; i < Size; i++){
        if (i%16==0 && i)cout <<endl;
        cout << Memory[i]<<' ';
    }
    cout << "\n===============================================\n";
}