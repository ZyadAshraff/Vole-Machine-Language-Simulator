#include "Machine.h"

Machine::Machine() {
    for (char i = '0'; i <= '9'; ++i) {
        hexMap[i] = 1;
    }
    for (char i = 'A'; i <= 'F'; ++i) {
        hexMap[i] = 1;
    }
}

ifstream Machine::loadProgramFile(string filename) {
    ifstream instructions(filename);

    while (!instructions.is_open()) {
        cout << "Error opening file " << filename << endl;
        cout << "Please enter the name of the instructions file you want to read:" << endl;
        cin >>filename;
        instructions.open(filename);
    }

    return instructions;
}

void Machine::outputState(string filename) {
    ifstream instructions = loadProgramFile(filename);
    string option;
    string location;

    cout << "Please enter the memory location to store instructions ex.['0A']: \n";
    cin>>location;
    while (!(validLocation(location))){
        cout << "Invalid input\n";
        cout << "Please enter the memory location to store instructions: \n";
        cin>>location;
    }
    processor.setLocation(location);

    while (true) {
        cout << "Choose The System You want:" << endl;
        cout << "1. Run till Halt [display the Memory cells once at the end]" << endl;
        cout << "2. step by step [display the Memory cells after each operation]" << endl;
        cout << "3. Exit" << endl;
        cin >> option;

        if (option == "1") {
            processor.decode_execute2(instructions);
            break;
        }

        else if (option == "2") {
            processor.decode_execute1(instructions);
            break;
        }

        else if (option == "3") {
            exit(0);
        }

        else{
            cout << "Wrong Choice, Please enter a valid choice" << endl;
            continue;
        }

    }

}

bool Machine::validLocation(string location) {
    return (location.size()==2) && (hexMap[location[0]]) && (hexMap[location[1]]);
}
