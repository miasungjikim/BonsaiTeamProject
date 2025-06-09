#include "adminmenu.h"
#include "stockmanagement.h"
#include <iostream>
using namespace std;

void showAdminMenu() {
    cout << "\n===== Admin: Product Management =====" << endl;
    cout << "1. View All Products (and Low Stock)" << endl;
    cout << "2. Update Product Info" << endl;
    cout << "3. Add New Product" << endl;
    cout << "4. Delete Product" << endl;
    cout << "5. Back to Previous Menu" << endl;
    cout << "Select an option: ";
}

void runAdminPanel() {
    StockManagement stock;
    stock.loadFromFile("products.txt");

    int choice;
    do {
        showAdminMenu();
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                stock.viewAllProducts();
                stock.viewLowStockItems();
                break;
            case 2: {
                string id;
                cout << "Enter Product ID to update: ";
                getline(cin, id);

                Product updated;
                updated.product_id = id; // ID 고정
                cout << "Enter new name: ";
                getline(cin, updated.name);
                cout << "Enter new category: ";
                getline(cin, updated.category);
                cout << "Enter new quantity: ";
                cin >> updated.quantity;
                cin.ignore();
                cout << "Enter new release date(e.g. DD-MM-YYYY): ";
                getline(cin, updated.release_date);
                cout << "Enter new store location(AUCKLAND or WELLINGTON CBD or CHRISTCHURCH): ";
                getline(cin, updated.store);

                stock.updateProduct(id, updated);
                stock.saveToFile("products.txt");
                break;
            }
            case 3: {
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
                cout << "Enter release date(e.g. DD-MM-YYYY): ";
                getline(cin, newProduct.release_date);
                cout << "Enter store location(AUCKLAND or WELLINGTON CBD or CHRISTCHURCH): ";
                getline(cin, newProduct.store);

                stock.addProduct(newProduct);
                stock.saveToFile("products.txt");
                break;
            }
            case 4: {
                string id;
                cout << "Enter product ID to delete: ";
                getline(cin, id);
                stock.deleteProduct(id);
                stock.saveToFile("products.txt");
                break;
            }
            case 5:
                cout << "Returning to previous menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 5);
}
