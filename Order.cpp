//
// Created by armon on 10/11/2023.
//

#include "Order.h"
#include <algorithm>

void Order::CalculateTotal()
{

}

void Order::PrintReceipt()
{

}

void Order::AddItem(Item* item, int qty = 1)
{
	items.push_back(item);
	SortItemsByID();
}

void Order::RemoveItem(Item* item)
{
	auto index = find(items.begin(),items.end(),item);
	if (index != items.end()){
		int pos = distance(items.begin(),index);
		//items.erase(pos);
		cout << "Item should be at" << pos << "but not removed yet as not implemented" << endl;
	}
	else{
		cout << "Item was not within the order, no item removed" << endl;
	}
}


