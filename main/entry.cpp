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
        cout << "Kia Ora, We're Aotearoa Treasures Ltd.      " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << " We are a New Zealand boutique retailer specialising" << endl;
        cout << " in authentic New Zealand-made handicrafts and souvenirs." << endl;
        cout << " Our stores are located in AUCKLAND, WELLINGTON CBD, " << endl;
        cout << " and CHRISTCHURCH.                                   " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << " This system is designed for both customers and admins." << endl;
        cout << " (Sign-up and login required to access features)      " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << " If you are a USER, you can:                         " << endl;
        cout << "  - View available stock in your registered store    " << endl;
        cout << "  - Purchase items                                   " << endl;
        cout << "  - Check your purchase history                      " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << " If you are an ADMIN, you can:                       " << endl;
        cout << "  - View and manage stock across all stores          " << endl;
        cout << "  - View customer purchase records                   " << endl;
        cout << "  - Manage staff schedules                           " << endl;
        cout << "=====================================================" << endl;





        cout << "< Main Menu >" << endl;
        cout << "1. Log In (User / Admin)" << endl;
        cout << "2. Sign Up (User / Admin)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            login();
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