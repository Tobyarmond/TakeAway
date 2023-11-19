//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ORDER_H
#define TAKEAWAY_ORDER_H
#include "ItemList.h"
#include <map>

class Order : ItemList
{
public:
	// TODO consider having another thing that deals with all printing.
	// Function that prints the receipt to a text file
	void AddItem(Item*, int);
	void RemoveItem(Item*);
	string ToString();
	void SetTax(float);
	void SetTip(float);
	void CompleteCheckout();

private:
	map<Item*, int> quantities;
	float total;
	float tip;
	float tax;
	void PrintReceipt();
	void CalculateTotal();
	void CountItems();

};


#endif //TAKEAWAY_ORDER_H
