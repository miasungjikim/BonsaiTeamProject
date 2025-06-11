//
// Created by MiaKim on 11/06/2025.
//
// inventory.cpp
#include "inventory.h"
#include "../admin/stockmanagement.h"
#include <iostream>
#include <iomanip>
using namespace std;

void viewInventoryMenu(const string& user_email) {
    StockManagement stock;
    stock.loadFromFile("products.txt");

    cout << "\n======= Available Products =======\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Qty"
         << setw(15) << "Release Date"
         << setw(15) << "Store" << endl;
    cout << "---------------------------------------------\n";

    for (const auto& product : stock.getProducts()) {
        cout << left << setw(10) << product.product_id
             << setw(20) << product.name
             << setw(15) << product.category
             << setw(10) << product.quantity
             << setw(15) << product.release_date
             << setw(15) << product.store << endl;
    }

    //enter --> back feature
    cout << "\nPress Enter to go back to the menu...";
    cin.ignore();
    cin.get();

}
