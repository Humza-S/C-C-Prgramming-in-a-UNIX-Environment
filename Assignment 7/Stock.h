#ifndef STOCK_H
#define STOCK_H

#include "InventoryItem.h"
#include <iostream>

class Stock
{
public:
	Stock();
	InventoryItem *list; // The list of items in stock
	int items;
	InventoryItem& operator [] (const int i);
	friend std::ostream& operator << (std::ostream& out, const Stock& stk);
	int max_items;
};

#endif
