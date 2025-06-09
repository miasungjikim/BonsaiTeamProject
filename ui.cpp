//
// Created by MiaKim on 07/06/2025.
//
#include <iostream>
#include "ui.h"
using namespace std;

void displayWelcome() {
    int choice;

    cout << "+++++==============================================+++++" << endl;
    cout << "   Welcome to Aotearoa Treasures' Inventory App" << endl;
    cout << "+++++==============================================+++++" << endl;
    cout << "Aotearoa Treasures is a boutique retailer" << endl;
    cout << "specialising in handcrafted and locally sourced goods." << endl;
    cout << "We operate across three key locations in New Zealand:" << endl;
    cout << " - Auckland" << endl;
    cout << " - Wellington CBD" << endl;
    cout << " - Christchurch" << endl;
    cout << "This application helps us manage inventory efficiently." << endl;
    cout << "+++++----------------------------------------------+++++" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit Program" << endl;
    cout << "+++++----------------------------------------------+++++" << endl;
    cout << "Select an option: ";
    cin >> choice;
}

