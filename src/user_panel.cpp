// Created by MiaKim on 11/06/2025.

#include <iostream>
#include "user_panel.h"
#include "../user/inventory.h"
#include "../user/purchase.h"
#include "../user/history.h"


using namespace std;


void userPanel(const string& user_email) {
    // string user_email;
    cout << "\nWelcome," << user_email << endl;

    int choice;
    while (true) {
        cout << "\n======= User Panel =======" << endl;
        cout << "1) View Inventory" << endl;
        cout << "2) Purchase Product" << endl;
        cout << "3) View Purchase History" << endl;
        cout << "4) Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewInventoryMenu(user_email);
                break;
            case 2:
                purchaseProduct(user_email);
                break;
            case 3:
                viewPurchaseHistory(user_email);
                break;
            case 4:
                cout << "Logging out...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


