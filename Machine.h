
#ifndef ASSIGN_1_T4_MACHINE_H
#define ASSIGN_1_T4_MACHINE_H

#include "memory.h"
#include "CPU.h"

class Machine {
private:
    CPU processor;
    memory Memory;
    map<char,int> hexMap;
public:
    Machine();
    ifstream loadProgramFile(string filename);
    void outputState(string filename);
    bool validLocation(string location);
};


#endif
