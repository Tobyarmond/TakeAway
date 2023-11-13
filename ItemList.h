//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_ITEMLIST_H
#define TAKEAWAY_ITEMLIST_H
#include <vector>
#include <iostream>
#include <memory>
#include <list>
#include "item.h"

using namespace std;


class ItemList
{
	// TODO Consider changing some things to private
public:
	//std::vector<std::unique_ptr<Item>> items;
	// I think this needs to be an array of pointers to make this work otherwise they narrow down to become Items
	//vector<Item> items;
	list<Item*> items;

	virtual string ToString();


};


#endif //TAKEAWAY_ITEMLIST_H
