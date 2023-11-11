//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ITEMLIST_H
#define TAKEAWAY_ITEMLIST_H
#include <vector>
#include <iostream>
#include "item.h"

using namespace std;


class ItemList
{
	// TODO Consider changing some things to private
public:
	vector<Item> items;

	virtual string ToString();


};


#endif //TAKEAWAY_ITEMLIST_H
