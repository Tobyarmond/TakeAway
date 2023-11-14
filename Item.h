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
	string getName();
	int getCalories();
	float getPrice();
	virtual string ToString();
protected:
	int calories{};
	string name;
	float price{};

	Item(const string &n, float p, int c);


};


#endif //TAKEAWAY_ITEM_H
