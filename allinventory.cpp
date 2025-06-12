//
// Created by MiaKim on 11/06/2025.
//
#include "allinventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

void viewAllPurchaseHistory() {
    ifstream file("purchase_history.txt");
    if (!file) {
        cout << "No purchase history file found.\n";
        return;
    }

    string line;
    cout << "\n========== All Purchase History ==========\n";
    cout << left << setw(25) << "Email"
        << setw(15) << "Product ID"
        << setw(20) << "Product Name"
        << setw(10) << "Qty"
        << setw(20) << "Date/Time"
        << setw(15) << "Store" << endl;
    cout << "--------------------------------------------------------------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string email, product_id, product_name, quantity, datetime, store;

        getline(ss, email, ',');
        getline(ss, product_id, ',');
        getline(ss, product_name, ',');
        getline(ss, quantity, ',');
        getline(ss, datetime, ',');
        getline(ss, store, ',');

        cout << left << setw(25) << email
            << setw(15) << product_id
            << setw(20) << product_name
            << setw(10) << quantity
            << setw(20) << datetime
            << setw(15) << store << endl;
    }
}
