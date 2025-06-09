//
// Created by MiaKim on 09/06/2025.
//
#include <iostream>
#include "admin_panel.h"
using namespace std;

void adminPanel() {
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

        switch (choice) {
            case 1:
                viewInventory();
                break;
            case 2: {
                int sub_choice;
                cout << "\n--- Manage Products ---" << endl;
                cout << "1) Add Product" << endl;
                cout << "2) Edit Product" << endl;
                cout << "3) Delete Product" << endl;
                cout << "Enter your choice: ";
                cin >> sub_choice;

                switch (sub_choice) {
                    case 1: addProduct(); break;
                    case 2: editProduct(); break;
                    case 3: deleteProduct(); break;
                    default: cout << "Invalid choice.\n";
                }
                break;
            }
            case 3:
                viewPurchaseOrders();
                markAsReady();
                break;
            case 4:
                cout << "Here is the staff scheduling";
                break;
            case 5:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }
}

// ===== Stub 함수들 =====

void viewInventory() {
    cout << "View All Inventory" << endl;
    filterByStore();
    viewLowStock();
}

void filterByStore() {
    cout << " (1-0)" << endl;
}

void viewLowStock() {
    cout << "(1-1)" << endl;
}

void addProduct() {
    cout << "(2-1)" << endl;
}

void editProduct() {
    cout << "(2-2)" << endl;
}

void deleteProduct() {
    cout << "(2-3)" << endl;
}

void viewPurchaseOrders() {
    cout << "(3)" << endl;
}

void markAsReady() {
    cout << "(3-1)" << endl;
}

// + staff scheduling