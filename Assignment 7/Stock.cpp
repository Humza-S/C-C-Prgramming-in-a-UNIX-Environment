#include "Stock.h"
#include "InventoryItem.h"

// Constructor

Stock::Stock()
{
  max_items = 10;
	list = new InventoryItem[max_items];
	items = 0;
}

InventoryItem& Stock::operator[](const int i) {
	return list[i];
}

std::ostream& operator << (std::ostream& out, const Stock& stk) {
	std::cout << "Item #\t\tInventory Item\t\tCost\tUnits On Hand\n";
	std::cout << "--------------------------------------------------------------------\n";
	for (int i = 0; i < stk.items; i++) {
		std::cout << " " << i + 1 << "\t\t";
		std::cout << stk.list[i].getDescription() << "\t\t\t";
		std::cout << stk.list[i].getCost() << "\t";
		std::cout << stk.list[i].getUnits() << "\n";
	}

	return out;
}
