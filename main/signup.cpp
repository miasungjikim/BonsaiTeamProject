//
// Created by MiaKim on 07/06/2025.
//
// signup.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "signup.h"

//Checks if the given email already exists in the file.
bool isDuplicateEmail(const string& filename, const string& email) { //takes a filename and an email as input.
    ifstream file(filename); //open file for reading
    string line; //to store each line from the file
    while (getline(file, line)) { // A loop that reads the file line by line until the end
        stringstream ss(line); //!! stringstream to treat the string like an input stream, we can easily split the line using commans
        string id, stored_email, name, password;
        getline(ss, id, ',');
        getline(ss, stored_email, ',');
        if (stored_email == email) return true;
    }
    return false;
}

int generateUserID(const string& filename) {
    ifstream file(filename);
    if (!file) {
        return 1; // 파일이 없으면 첫 ID를 1로 시작
    }
    string line;
    int max_id = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string id_str;
        getline(ss, id_str, ',');
        int id = stoi(id_str);
        if (id > max_id) max_id = id;
    }
    return max_id + 1;
}

void signupMenu() {
    cout << "========== Sign Up ==========" << endl;
    cout << "Choose role: " << endl;
    cout << "1) User" << endl;
    cout << "2) Admin" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    string email, name, password, admin_key;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;

    string filename;
    string store;

    if (choice == 1) {
        filename = "users.txt";
        cout << "When you enter the store, please write down on uppercase" << endl;
        cout << "Select Store (AUCKLAND / WELLINGTON CBD / CHRISTCHURCH) : ";
        cin.ignore();
        getline(cin, store);

        if (store != "AUCKLAND" && store != "WELLINGTON CBD" && store != "CHRISTCHURCH") {
            cout << "Invalid store name. Sign up failed";
        }

    }
    else if (choice == 2) {
        cout << "Enter Admin Key: ";
        cin >> admin_key;
        if (admin_key != "admin1234") {
            cout << "Incorrect admin key. Sign up failed." << endl;
            return;
        }
        filename = "admins.txt";
    }
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    if (isDuplicateEmail(filename, email)) {
        cout << "This email is already registered." << endl;
        return;
    }

    int user_id = generateUserID(filename);

    ofstream out_file(filename, ios::app);
    out_file << user_id << "," << email << "," << name << "," << password << "," << store << endl;
    out_file.close();

    cout << "Sign up successful! Your ID: " << user_id << endl;
    cout << "Returning to main menu..." << endl;
}
