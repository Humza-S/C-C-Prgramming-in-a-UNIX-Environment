#include "InventoryItem.h"
#include <string.h>

int InventoryItem::number_articles = 0;
//Constructors
InventoryItem::InventoryItem() {
	description = (char*)"";
	cost = 0;
	units = 0;
}

InventoryItem::InventoryItem(char* desc, double cost, int units) {
	description = new char[strlen(desc) + 1];
	//strcpy_s(description, strlen(desc) + 1, desc);
	strcpy(description, desc);
	this->cost = cost;
	this->units = units;
}

//Destructor
InventoryItem::~InventoryItem() {
	delete[]description;
	cost = 0;
	units = 0;
}

const char* InventoryItem::getDescription() const {
	return description;
}

void InventoryItem::setDescription(const char* desc)
{
	description = new char[strlen(desc) + 1];
	strcpy(description, desc);
	//strcpy_s(description, strlen(desc) + 1, desc);
}

double InventoryItem::getCost() const {
	return cost;
}

void InventoryItem::setCost(double c)
{
	cost = c;
}

int InventoryItem::getUnits() const {
	return units;
}

void InventoryItem::setUnits(int u) {
	this->units = u;
}

int InventoryItem::getNumberArticles() {
	return number_articles;
}
