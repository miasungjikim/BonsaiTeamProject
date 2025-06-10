//
// Created by MiaKim on 03/06/2025.
//

#include "../admin/stockmanagement.h"
#include <iostream>
#include <string>
using namespace std;

void adminAddProduct(StockManagement& stock) {
    Product newProduct;
    cout << "Enter product ID: ";
    getline(cin, newProduct.product_id);
    cout << "Enter name: ";
    getline(cin, newProduct.name);
    cout << "Enter category: ";
    getline(cin, newProduct.category);
    cout << "Enter quantity: ";
    cin >> newProduct.quantity;
    cin.ignore();
    cout << "Enter release date (e.g. DD-MM-YYYY): ";
    getline(cin, newProduct.release_date);
    cout << "Enter store location: ";
    getline(cin, newProduct.store);

    stock.addProduct(newProduct);
}

void adminEditProduct(StockManagement& stock) {
    string id;
    cout << "Enter Product ID to update: ";
    getline(cin, id);

    Product updated;
    updated.product_id = id;
    cout << "Enter new name: ";
    getline(cin, updated.name);
    cout << "Enter new category: ";
    getline(cin, updated.category);
    cout << "Enter new quantity: ";
    cin >> updated.quantity;
    cin.ignore();
    cout << "Enter new release date: ";
    getline(cin, updated.release_date);
    cout << "Enter new store location: ";
    getline(cin, updated.store);

    stock.updateProduct(id, updated);
}

void adminDeleteProduct(StockManagement& stock) {
    string id;
    cout << "Enter Product ID to delete: ";
    getline(cin, id);
    stock.deleteProduct(id);
}

void adminViewInventory(StockManagement& stock) {
    stock.viewAllProducts();
    stock.viewLowStockItems();
}


