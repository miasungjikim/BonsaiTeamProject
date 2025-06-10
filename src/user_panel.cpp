//
// Created by MiaKim on 10/06/2025.
//
// user_panel.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "user_panel.h"

void userPanel() {
    int choice;

    while (true) {
        cout << "\n========== User Panel ==========" << endl;
        cout << "1) View Inventory" << endl;
        cout << "2) View Purchase History" << endl;
        cout << "3) Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                userViewInventory();
                break;
            case 2:
                viewPurchaseHistory();
                break;
            case 3:
                cout << "Logging out...\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

void userViewInventory() {
    ifstream file("products.txt");
    if (!file) {
        cout << "No inventory file found.\n";
        return;
    }

    cout << "\n----- Product List -----\n";
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, store, stock, price;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, store, ',');
        getline(ss, stock, ',');
        getline(ss, price, ',');

        cout << "ID: " << id
             << " | Name: " << name
             << " | Store: " << store
             << " | Stock: " << stock
             << " | Price: $" << price << endl;
    }

    file.close();

}

void viewPurchaseHistory() {
    ifstream file("purchase_history.txt");
    if (!file) {
        cout << "No purchase history found.\n";
        return;
    }

    cout << "\n----- Purchase History -----\n";
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string date, product_name, quantity, store;
        getline(ss, date, ',');
        getline(ss, product_name, ',');
        getline(ss, quantity, ',');
        getline(ss, store, ',');

        cout << "Date: " << date
             << " | Product: " << product_name
             << " | Qty: " << quantity
             << " | Store: " << store << endl;
    }

    file.close();
}
