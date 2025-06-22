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
#include "admin_panel.h"
#include "user_panel.h"


//checkLogin()
LoginInfo checkLogin(const string& file_name, const string& email, const string& password, bool is_user) {
    ifstream file(file_name);
    LoginInfo result{ false, "", "", "", "" };

    if (!file) return result;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, file_email, name, file_password, store;

        getline(ss, id, ',');
        getline(ss, file_email, ',');
        getline(ss, name, ',');
        getline(ss, file_password, ',');

        if (is_user) {
            getline(ss, store, ','); // For users only
        }

        if (file_email == email && file_password == password) {
            result.success = true;
            result.id = id;
            result.email = file_email;
            result.name = name;
            result.store = store;
            return result;
        }
    }

    return result;
}
//loginMenu()
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
    }
    else if (role_choice == 2) {
        file_name = "admins.txt";
    }
    else {
        cout << "Invalid role. Back to menu." << endl;
        return;
    }

    //LoginInfo login()
    bool is_user = (role_choice == 1);
    LoginInfo login = checkLogin(file_name, email, password, is_user);

    if (login.success) {
        cout << "Login successful!" << endl;

        if (role_choice == 1) {
            cout << "Redirecting to User Panel..." << endl;
            userPanel(login.email, login.store);  // Pass store to userPanel
        }
        else {
            cout << "Redirecting to Admin Panel..." << endl;
            adminPanel();
        }

    }
    else {
        cout << "Incorrect email or password." << endl;
    }
}
