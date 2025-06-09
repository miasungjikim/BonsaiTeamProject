//
// Created by MiaKim on 09/06/2025.
//
// signin.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "signin.h"

bool checkLogin(const string& file_name, const string& email, const string& password) {
    ifstream file(file_name);
    if (!file) return false;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, file_email, name, file_password;
        getline(ss, id, ',');
        getline(ss, file_email, ',');
        getline(ss, name, ',');
        getline(ss, file_password, ',');

        if (file_email == email && file_password == password) {
            return true;
        }
    }
    return false;
}

void loginMenu() {
    cout << "========== Log In ==========" << endl;
    cout << "1) User" << endl;
    cout << "2) Admin" << endl;
    cout << "Choose role: ";
    int role_choice;
    cin >> role_choice;

    string email, password;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    string file_name;
    if (role_choice == 1) {
        file_name = "users.txt";
    } else if (role_choice == 2) {
        file_name = "admins.txt";
    } else {
        cout << "Invalid role. Back to menu." << endl;
        return;
    }

    bool success = checkLogin(file_name, email, password);
    if (success) {
        cout << "Login successful!" << endl;
        if (role_choice == 1) {
            cout << "Redirecting to User Panel..." << endl;
            // userPanel();  // 나중에 연결할 예정
        } else {
            cout << "Redirecting to Admin Panel..." << endl;
            // adminPanel();  // 나중에 연결할 예정
        }
    } else {
        cout << "Incorrect email or password." << endl;
    }
}
