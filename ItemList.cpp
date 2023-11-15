//
// Created by armon on 10/11/2023.
//

#include "ItemList.h"
#include <vector>
using namespace std;



string ItemList::ToString()
{
	string response;

	return response;
}

void ItemList::SortItemsByID()
{
	if (!items.empty())
	{
		vector<Item*> starters;
		vector<Item*> mains;
		vector<Item*> drinks;
		for (Item* it: items)
		{
			if (it->getID() == 1)
			{
				starters.push_back(it);
			}
			else if (it->getID() == 2)
			{
				mains.push_back(it);
			}
			else if (it->getID() == 3)
			{
				drinks.push_back(it);
			}
		}
		items.clear();
		items.insert(items.end(),starters.begin(),starters.end());
		items.insert(items.end(),mains.begin(),mains.end());
		items.insert(items.end(),drinks.begin(),drinks.end());
	}
}

Item* ItemList::GetItem(int index)
{
	Item* result;
	if(index < items.size()-1){
		result = items[index];
	}
	else{
		result = nullptr;
	}
	return result;
}


