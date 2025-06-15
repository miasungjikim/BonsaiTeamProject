//
// Created by MiaKim on 05/06/2025.
//


#include <iostream>
#include "entry.h"
#include "signup.h"
#include "signin.h"

using namespace std;

void showMainMenu() {
    int choice;

    while (true) {
        cout << "=====================================================" << endl;
        cout << "   Welcome to Aotearoa Boutique Retailer      " << endl;
        cout << "    Stock and Purchase Management System      " << endl;

        cout << " This program is designed to help manage:      " << endl;
        cout << " - Product inventory across multiple stores    " << endl;
        cout << " - User purchases and admin stock control      " << endl;
        cout << " - Admin manage staff scheduling" << endl;
        cout << "-----------------------------------------------------" << endl;




        cout << "< Main Menu >" << endl;
        cout << "1. Log In (User / Admin)" << endl;
        cout << "2. Sign Up (User / Admin)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            loginMenu();
            break;
        case 2:
            signUp();
            break;
        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void login() {
    loginMenu();
}

void signUp() {
    signupMenu();
}