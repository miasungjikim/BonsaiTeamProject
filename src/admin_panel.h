//
// Created by MiaKim on 09/06/2025.
//

#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

void adminPanel();

// 1. Inventory
void adminViewInventory();     // 전체 보기
void filterByStore();     // 1-0
void viewLowStock();      // 1-1

// 2. Product
void addProduct();        // 2-1
void editProduct();       // 2-2
void deleteProduct();     // 2-3

// 3. purchase
void viewPurchaseOrders();  // 3
void markAsReady();         // 3-1

// 4. staff scheduling


#endif


