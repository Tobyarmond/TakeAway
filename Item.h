//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ITEM_H
#define TAKEAWAY_ITEM_H
#include <iostream>
using namespace std;

class Item
{
public:
	int calories{};
	string name;
	float price{};

	Item(string n, float p, int c);

	virtual string ToString();
};


#endif //TAKEAWAY_ITEM_H
