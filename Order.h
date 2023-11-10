//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ORDER_H
#define TAKEAWAY_ORDER_H
#include "ItemList.h"

class Order : ItemList
{
public:
	float calculateTotal();

	// TODO consider having another thing that deals with all printing.
	void printReceipt();

};


#endif //TAKEAWAY_ORDER_H
