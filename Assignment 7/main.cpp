#include "InventoryItem.h"
#include "Stock.h"
#include <iostream>

int main() {
	
	int index = 0;

	Stock stk;
	InventoryItem apples((char*)"Apples", 2.25, 20);
	stk.list[index++] = apples;
	InventoryItem oranges((char*)"Oranges", 1.5, 15);
	stk.list[index++] = oranges;
	InventoryItem mangoes((char*)"Mangoes", 5.00, 5);
	stk.list[index++] = mangoes;
	stk.items += index;	

	int choice = 1;
	int item_number = 0;
	int amount_bought = 0;

	while (choice == 1) {
		std::cout << "Items in stock:\n ";
		std::cout << stk;

		std::cout << "Type 1 to Buy or 0 to Exit: ";
		std::cin >> choice;

		if (choice == 1) {
			std::cout << "\nEnter Item Number to Buy: ";
			std::cin >> item_number;

			if (item_number < 0 || item_number > index) {
				std::cout << "Please enter a valid item number\n";
				continue;
			}
			std::cout << "\nEnter Amount to Buy: ";
			std::cin >> amount_bought;

			if (stk.list[item_number - 1].getUnits() <= 0) {
				std::cout << "We have run out of " << stk.list[item_number - 1].getDescription() << "\n";
				continue;
			}
			else if (stk.list[item_number - 1].getUnits() < amount_bought) {
				std::cout << "We do not have the required amount you are attempting to buy\n";
				continue;
			}

			if (amount_bought > 0) {
				stk.list[item_number - 1].setUnits(stk.list[item_number - 1].getUnits() - amount_bought);
				InventoryItem::number_articles += amount_bought;
			}
			else
				std::cout << "Please enter a positive integer for quantitity (greater than 0)\n";
		}
		std::cout << "Total number of articles sold: " << InventoryItem::getNumberArticles() << "\n";
	}

	return 0;
}
