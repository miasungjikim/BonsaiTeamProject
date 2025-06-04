// Created by MiaKim on 01/06/2025.

#include "stockmanagement.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

void StockManagement::loadFromFile(const string& filename) {
    products.clear();

    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream product_stream(line);

        string product_id, name, category, release_date, store;
        int quantity;

        string quantity_str;

        getline(product_stream, product_id, ',');
        getline(product_stream, name, ',');
        getline(product_stream, category, ','); // 🆕 카테고리 추가
        getline(product_stream, quantity_str, ',');
        quantity = stoi(quantity_str);
        getline(product_stream, release_date, ',');
        getline(product_stream, store, ',');

        Product product = {product_id, name, category, quantity, release_date, store};
        products.push_back(product);
    }

    infile.close();
}

void StockManagement::viewAllProducts() const {
    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }

    cout << "All Products:\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(15) << "Category"
         << setw(8)  << "Qty"
         << setw(15) << "Release Date"
         << setw(15) << "Store" << endl;
    cout << "--------------------------------------------------------------------------------\n";

    for (const auto& product : products) {
        cout << left << setw(10) << product.product_id
             << setw(15) << product.name
             << setw(15) << product.category
             << setw(8)  << product.quantity
             << setw(15) << product.release_date
             << setw(15) << product.store << endl;
    }
}

void StockManagement::addProduct(const Product& new_product) {
    for (const auto& product : products) {
        if (product.product_id == new_product.product_id) {
            cout << "Product ID already exists. Cannot add duplicate product.\n";
            return;
        }
    }

    products.push_back(new_product);
    cout << "Product added successfully.\n";
}

void StockManagement::deleteProduct(const string& product_id) {
    bool found = false;

    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->product_id == product_id) {
            products.erase(it);
            cout << "Product with ID '" << product_id << "' has been deleted." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product with ID '" << product_id << "' not found." << endl;
    }
}

void StockManagement::updateProduct(const string& product_id, const Product& updated_product) {
    bool found = false;

    for (auto& product : products) {
        if (product.product_id == product_id) {
            product.name = updated_product.name;
            product.quantity = updated_product.quantity;
            product.release_date = updated_product.release_date;
            product.store = updated_product.store;
            product.category = updated_product.category;
            found = true;
            cout << "Product with ID '" << product_id << "' has been updated." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Product with ID '" << product_id << "' not found." << endl;
    }
}

void StockManagement::saveToFile(const string& filename) const {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        return;
    }

    for (const auto& product : products) {
        outfile << product.product_id << ","
                << product.name << ","
                << product.category << ","
                << product.quantity << ","
                << product.release_date << ","
                << product.store << endl;
    }

    outfile.close();
}

void StockManagement::viewLowStockItems() const {
    bool has_low_stock = false;

    cout << "\n[ Low Stock Items (5 or less) ]\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(15) << "Category"
         << setw(8)  << "Qty"
         << setw(15) << "Release Date"
         << setw(15) << "Store" << endl;
    cout << "--------------------------------------------------------------------------------\n";

    for (const auto& product : products) {
        if (product.quantity <= 5) {
            has_low_stock = true;
            cout << left << setw(10) << product.product_id
                 << setw(15) << product.name
                 << setw(15) << product.category
                 << setw(8)  << product.quantity
                 << setw(15) << product.release_date
                 << setw(15) << product.store << endl;
        }
    }

    if (!has_low_stock) {
        cout << "No items with low stock.\n";
    }
}

void StockManagement::updateStockAfterPurchase(const string& product_id, int quantity_purchased) {
    for (auto& product : products) {
        if (product.product_id == product_id) {
            if (product.quantity >= quantity_purchased) {
                product.quantity -= quantity_purchased;
                cout << "Purchase successful. Remaining stock: " << product.quantity << endl;
            } else {
                cout << "Not enough stock for product '" << product_id << "'.\n";
            }
            return;
        }
    }
    cout << "Product ID '" << product_id << "' not found.\n";
}

