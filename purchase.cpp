// Created by MiaKim on 11/06/2025.
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include "purchase.h"
#include "stockmanagement.h"
using namespace std;

void purchaseProduct(const string& user_email) {
    StockManagement stock;
    stock.loadFromFile("products.txt");

    string product_id;
    cout << "\nEnter Product ID to purchase: ";
    cin >> product_id;

    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    bool found = false;

    for (const auto& p : stock.getProducts()) {
        if (p.product_id == product_id) {
            found = true;

            if (p.quantity < quantity) {
                cout << "Not enough stock available.\n";
                return;
            }

            // ?? ????
            Product updated = p;
            updated.quantity -= quantity;
            stock.updateProduct(product_id, updated);

            // ?? ?? ???
            auto now = chrono::system_clock::now();
            time_t now_time = chrono::system_clock::to_time_t(now);
            tm* timeinfo = localtime(&now_time);
            char time_buf[20];
            strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M", timeinfo);

            // ?? ?? ??
            // ?? ?? ?? (??: user_email, product_id, product_name, quantity, store, datetime)
            ofstream history("purchase_history.txt", ios::app);
            history << user_email << ","
                << p.product_id << ","
                << p.name << ","
                << quantity << ","
                << p.store << ","
                << time_buf << endl;


            cout << "Purchase successful!\n";
            break;
        }
    }

    if (!found) {
        cout << "Product ID not found.\n";
    }

    stock.saveToFile("products.txt");
}
