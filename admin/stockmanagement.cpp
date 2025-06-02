// Created by MiaKim on 01/06/2025.

#include "stockmanagement.h"
#include <fstream>
#include <sstream>
#include <iostream>

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

        string product_id, name, release_date, store;
        int quantity;

        getline(product_stream, product_id, ',');
        getline(product_stream, name, ',');
        string quantity_str;
        getline(product_stream, quantity_str, ',');
        quantity = stoi(quantity_str);
        getline(product_stream, release_date, ',');
        getline(product_stream, store, ',');

        Product product = {product_id, name, quantity, release_date, store};
        products.push_back(product);
    }

    infile.close();
}

void StockManagement::viewAllProducts() const {
    for (const auto& product : products) {
        cout << "Product ID: " << product.product_id << endl;
        cout << "Name: " << product.name << endl;
        cout << "Quantity: " << product.quantity << endl;
        cout << "Release Date: " << product.release_date << endl;
        cout << "Store: " << product.store << endl;
        cout << "--------------------------" << endl;
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
