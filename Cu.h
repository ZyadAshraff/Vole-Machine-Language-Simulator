//
// Created by HP on 11/2/2024.
//

#ifndef OOP_CU_H
#define OOP_CU_H
#include "Memory.h"
#include "Register.h"
class Cu {
public:
    void load(string instruction , memory& Memory , Register& aRegister);
    void load(string instruction , Register& aRegister);
    void store(string instruction , memory& Memory , Register& aRegister);
    void move(string instruction , Register& aRegister);
    void jump(string instruction , Register& aRegister , int& PC ,string location);
    void halt();
};


#endif //OOP_CU_H
