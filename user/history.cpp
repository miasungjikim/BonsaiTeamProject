// history.cpp
#include "history.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

void viewPurchaseHistory(const string& user_email) {
    ifstream file("purchase_history.txt");
    if (!file) {
        cout << "No purchase history found.\n";
        return;
    }

    string line;
    bool found = false;
    cout << "\n=================== Your Purchase History ===================\n";
    cout << left << setw(20) << "Date/Time"
         << setw(20) << "Product"
         << setw(10) << "Qty"
         << setw(15) << "Store" << endl;
    cout << "-----------------------------------------------------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string email, datetime, product_name, quantity, store;

        getline(ss, email, ',');
        getline(ss, datetime, ',');
        getline(ss, product_name, ',');
        getline(ss, quantity, ',');
        getline(ss, store, ',');

        if (email == user_email) {
            found = true;
            cout << left << setw(20) << datetime
                 << setw(20) << product_name
                 << setw(10) << quantity
                 << setw(15) << store << endl;
        }
    }

    if (!found) {
        cout << "No purchases found for this account.\n";
    }
}
