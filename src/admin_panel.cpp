//
// Created by MiaKim on 09/06/2025.
//
// admin_panel.cpp
#include <iostream>
#include "admin_panel.h"
#include "../admin/stockmanagement.h"
#include "../admin/admin_functions.h"
using namespace std;

void adminPanel() {
    StockManagement stock;
    stock.loadFromFile("products.txt");

    int choice;

    while (true) {
        cout << "\n========== Admin Panel ==========" << endl;
        cout << "1) View All Inventory" << endl;
        cout << "2) Manage Products" << endl;
        cout << "3) View Purchase Orders" << endl;
        cout << "4) View Staff Scheduling" << endl;
        cout << "5) Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                adminViewInventory(stock);
                break;
            case 2: {
                int sub_choice;
                cout << "\n--- Manage Products ---" << endl;
                cout << "1) Add Product" << endl;
                cout << "2) Edit Product" << endl;
                cout << "3) Delete Product" << endl;
                cout << "Enter your choice: ";
                cin >> sub_choice;
                cin.ignore();

                switch (sub_choice) {
                    case 1: adminAddProduct(stock); break;
                    case 2: adminEditProduct(stock); break;
                    case 3: adminDeleteProduct(stock); break;
                    default: cout << "Invalid choice.\n";
                }
                break;
            }
            case 3:
                cout << "[Placeholder] Viewing purchase orders...\n";
                break;
            case 4:
                cout << "[Placeholder] Staff scheduling coming soon...\n";
                break;
            case 5:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid option. Try again." << endl;
        }

        stock.saveToFile("products.txt");
    }
}