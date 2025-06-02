// Created by MiaKim on 01/06/2025.


#ifndef STOCKMANAGEMENT_H
#define STOCKMANAGEMENT_H

#include <vector>
#include <string>
#include "product.h"
using namespace std;

class StockManagement{
private:
    vector<Product> products;
public:

    void loadFromFile(const string& filename); //product Information
    void saveToFile(const string& filename) const;
    void addProduct(const Product& new_product); //userstory4
    void updateProduct(const string& product_id, const Product& updated_product); //userstory5
    void deleteProduct(const string& product_id); //userstory6
    void viewLowStockItems() const; //userstory2
    void updateStockAfterPurchase(const string& product_id, int quantity_purchased); //userstory7
    void viewAllProducts() const; //userstory3

};


#endif
