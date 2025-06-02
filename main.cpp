#include <iostream>
#include "admin/stockmanagement.h"
using namespace std;

int main() {
    StockManagement manager;
    manager.loadFromFile("products.txt");

    /*
    * adding
    *Product new_product = {"P1005", "Green Tea", 15, "2025-06-01", "Auckland"};
    *manager.addProduct(new_product);
    */

    /*
     *deleting
     * manager.deleteProduct("P003");
    *
	*/


    manager.viewAllProducts();



    return 0;
}
