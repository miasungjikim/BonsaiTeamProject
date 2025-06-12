//
// Created by MiaKim on 03/06/2025.
//

#ifndef ADMIN_FUNCTIONS_H
#define ADMIN_FUNCTIONS_H

#include "stockmanagement.h"
#include "staff_scheduler.h"

void adminAddProduct(StockManagement& stock);
void adminEditProduct(StockManagement& stock);
void adminDeleteProduct(StockManagement& stock);
void adminViewInventory(StockManagement& stock);

#endif
