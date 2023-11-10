//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_BEVERAGE_H
#define TAKEAWAY_BEVERAGE_H

#include "Item.h"

class Beverage : public Item
{
public:
	float abv;
	int volume;

	Beverage(string n, float p, int c, int v, float a);
};


#endif //TAKEAWAY_BEVERAGE_H
