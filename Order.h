//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ORDER_H
#define TAKEAWAY_ORDER_H
#include "ItemList.h"

class Order : ItemList
{
public:
	// TODO consider having another thing that deals with all printing.
	// Function that prints the receipt to a text file
	void printReceipt();
private:
	float total;
	void calculateTotal();
};


#endif //TAKEAWAY_ORDER_H
