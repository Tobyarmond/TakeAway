//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_APPETISER_H
#define TAKEAWAY_APPETISER_H

#include "Item.h"

class Appetiser : public Item
{
public:
	bool shareable;
	bool twoForOne;

	Appetiser(string n, float p, int c, bool share, bool twoFor);
};


#endif //TAKEAWAY_APPETISER_H
