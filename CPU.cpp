//
// Created by zyad on 11/2/2024.
//
#include "CPU.h"

void CPU::fetch(ifstream& file, vector<string>& instructions) {
    string line;
    while (getline(file, line)) {
        instructions.push_back(line);
    }
}
void CPU::decode_execute1(ifstream& file) {
    fetch(file, instructs);
    for (int i = 0; i < instructs.size(); ++i) {
        if(!alu.isValid(instructs[i]) || instructs[i] == "C000"){
            reg.Print();
            mem.Print();
            cout << "Hexa output is :";
            for(auto item : HexaPrint) cout << item<<" ";
            cout <<"\nAscii output is : ";
            for(auto item : AsciiPrint) cout << item;
            cout << endl;
            cu.halt();
        }
        if (instructs[i].substr(0,1) == "1") {
            cu.load(instructs[i], mem, reg);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i].substr(0,1) == "2") {
            cu.load(instructs[i], reg);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i].substr(0,1) == "3") {
            if (instructs[i].substr(2,2)=="00") {
                string cell = reg.getCell(instructs[i].substr(1,1));
                HexaPrint.push_back(cell);
                AsciiPrint.push_back(char(stoi(cell, nullptr, 16)));
            }
            cu.store(instructs[i], mem, reg);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i].substr(0,1) == "4") {
            cu.move(instructs[i], reg);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i].substr(0,1) == "5") {
            alu.Add(instructs[i], reg);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i].substr(0,1) == "B") {
            cu.jump(instructs[i], reg, i,location);
            reg.Print();
            mem.Print();
        }

        else if (instructs[i] == "C000") {
            reg.Print();
            mem.Print();
            cu.halt();
        }

        else if(instructs[i].substr(0,1) == "6") {
            alu.floatingAdd(instructs[i],reg);
            }
    }

}

void CPU::decode_execute2(ifstream& file){
    fetch(file, instructs);
    for (int i = 0; i < instructs.size(); ++i) {
        if(!alu.isValid(instructs[i]) || instructs[i] == "C000"){
            cout << endl;
            reg.Print();
            mem.Print();
            cout << "Screen (Hexadecimal): ";
            for(auto item : HexaPrint) cout << item<<" ";
            cout <<"\nScreen (ASCII): ";
            for(auto item : AsciiPrint) cout << item;
            cu.halt();
        }
        if (instructs[i].substr(0,1) == "1") {
            cu.load(instructs[i], mem, reg);
        }

        else if (instructs[i].substr(0,1) == "2") {
            cu.load(instructs[i], reg);
        }

        else if (instructs[i].substr(0,1) == "3") {
            if (instructs[i].substr(2,2)=="00") {
                string cell = reg.getCell(instructs[i].substr(1,1));
                HexaPrint.push_back(cell);
                AsciiPrint.push_back(char(stoi(cell, nullptr, 16)));
            }
            cu.store(instructs[i], mem, reg);
        }

        else if (instructs[i].substr(0,1) == "4") {
            cu.move(instructs[i], reg);
        }

        else if (instructs[i].substr(0,1) == "5") {
            alu.Add(instructs[i], reg);
        }

        else if (instructs[i].substr(0,1) == "B") {
            cu.jump(instructs[i], reg, i,location);
        }

        else if(instructs[i].substr(0,1) == "6") {
            alu.floatingAdd(instructs[i],reg);
        }
    }
}

void CPU::setLocation(const string& location) {
    this-> location = location;
}






