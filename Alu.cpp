//
// Created by HP on 11/2/2024.
//

#include "Alu.h"

Alu::Alu() {
    for (char i = '0'; i <= '9'; ++i) {
        hexMap[i] = 1;
    }
    for (char i = 'A'; i <= 'F'; ++i) {
        hexMap[i] = 1;
    }
    for (char i = '1'; i <= '6'; ++i) {
        instructions[i] = 1;
    }
    instructions['B']=1;
    instructions['C']=1;

}

bool Alu::isValid(string instruction) {
    return (instruction.length()==4) && (instructions[instruction[0]]) &&
           (hexMap[instruction[1]]) && (hexMap[instruction[2]]) && (hexMap[instruction[3]]);
}

void Alu::Add(string instruction, Register& aRegister) {
    string register_1 = aRegister.getCell(instruction.substr(2,1));
    string register_2 = aRegister.getCell(instruction.substr(3,1));

    int a = stoi(register_1, nullptr, 16);
    int b = stoi(register_2, nullptr, 16);
    a = (a>=128? -1*twoComplement(a):a);
    b = (b>=128? -1*twoComplement(b):b);
    int res = a+b;
    res = (res<0? res+128:res);
    string result = decimalToHex(res);

    aRegister.setCell(instruction.substr(1,1), result);
}

string Alu::decimalToHex(int decimal) {
    if (decimal == 0) return "0";

    string hex = "";
    char hexChars[] = "0123456789ABCDEF";

    while (decimal > 0) {
        int remainder = decimal % 16;
        hex = hexChars[remainder] + hex;  // Prepend the character
        decimal /= 16;
    }

    return hex;
}


string Alu::hexToBin(string& hex) {
    int decimal = stoi(hex, nullptr, 16);
    bitset<8> binary(decimal);
    return binary.to_string();
}


int Alu::binToDec(string& binary) {
    int decimal = stoi(binary, nullptr, 2);
    return decimal;
}


double Alu::hexToFloat(string& hex) {
    string binary = hexToBin(hex);

    int s = stoi(binary.substr(0, 1));
    string exp = binary.substr(1, 3);
    string mant = binary.substr(4, 4);

    double newExp = binToDec(exp);
    double newMant = binToDec(mant) / 16.0;

    return pow(-1, s) * newMant * pow(2, newExp - 4);
}


string Alu::floatingAdd(string instruction, Register& aRegister) {
    string register_1 = aRegister.getCell(instruction.substr(2,1));
    string register_2 = aRegister.getCell(instruction.substr(3,1));
    double f1 = hexToFloat(register_1);
    double f2 = hexToFloat(register_2);
    double res = f1+f2;
    string result = decimalToHex(res);
    aRegister.setCell(instruction.substr(1,1), result);
}


int Alu::twoComplement(int number) {
    string binary = "";
    while (number > 0) {
        binary = (number % 2 == 0 ? "1" : "0") + binary;
        number /= 2;
    }
    binary = addOne(binary);
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (1<<power);
        }
        power++;
    }
    return decimal;
}

string Alu::addOne(string binary) {
    int n = binary.length();
    for (int i = n - 1; i >= 0; i--) {
        if (binary[i] == '0') {
            binary[i] = '1';
            return binary;
        }
        else {
            binary[i] = '0';
        }
    }
    return "1" + binary;
}


