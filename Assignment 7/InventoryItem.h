#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

class InventoryItem
{
public:
	//Constructors
	InventoryItem();
	InventoryItem(char* desc, double cost, int units);
	//Destructor
	~InventoryItem();
	const char* getDescription() const;
	void setDescription(const char* desc);
	double getCost() const;
	void setCost(double c);
	int getUnits() const;
	void setUnits(int u);
	static int getNumberArticles();
	static int number_articles;

private:
	char* description; // The item description
	double cost;	// The item cost
	int units;	// Number of units on hand
};

#endif
