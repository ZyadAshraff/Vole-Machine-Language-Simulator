#include "MainUI.h"



void MainUI::displayMenu() {
    cout << "======== Vole Machine Simulator Program =======" << endl;
    cout << "Please enter the name of the instructions file you want to read:" << endl;
}

void MainUI::inputFileName() {
    string filename;
    cin >> filename;
    machine.outputState(filename);
}


