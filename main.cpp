#include <iostream>
#include "admin/stockmanagement.h"
using namespace std;

int main() {
    StockManagement stock;
    stock.loadFromFile("products.txt");
    cout << "\n[ All Products in Inventory ]" << endl;
    stock.viewAllProducts();


    Product new_product = {"P002", "Earrings", "Jewelry", 15, "2025-06-05", "Wellington"};

    stock.addProduct(new_product);
    stock.saveToFile("products.txt");


    // stock.deleteProduct("P001");
    // stock.saveToFile("products.txt");

    Product updated_product = {"P002", "Earrings", "Accessories", 4, "2025-06-10", "Wellington"};
    stock.updateProduct("P002", updated_product);
    stock.saveToFile("products.txt");


    stock.viewLowStockItems();


    return 0;
}
