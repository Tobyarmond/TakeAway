//
// Created by armon on 10/11/2023.
//

#include "Order.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

void Order::CalculateTotal()
{
	// FIXME total is wrong and is generally 1 too low.
	// TODO might need to have both 241 items in the offer.
	// TODO consider adding tax calculation to this.
	// Clear total before recalculating
	total = 0;
	for(pair<Item*,int> qty : quantities){
		if(qty.first->getTwoForOne() && qty.second > 1){
			total += qty.first->getPrice() * qty.second / 2 + qty.second % 2;
		}
		else{
			total += qty.first->getPrice() * qty.second;
		}
	}
}

void Order::PrintReceipt()
{
	cout << "Receipt printed" << endl;
}

void Order::AddItem(Item* item,int qty = 1)
{
	for (int i = 0; i < qty; i++){
		items.push_back(item);
	}
	SortItemsByID();
}

void Order::RemoveItem(Item* item)
{
	auto index = find(items.begin(),items.end(),item);
	if (index != items.end()){
		int pos = distance(items.begin(),index);
		items.erase(index);
		cout << "Item should be at " << pos << " but not removed yet as not implemented" << endl;
	}
	else{
		cout << "Item was not within the order, no item removed" << endl;
	}
}

// TODO possibly add a total for each line?
string Order::ToString()
{
	string response;
	if(!items.empty())
	{
		// TODO get rid of these assertions!
		tax = 0.1;
		tip = 0.1;
		const string line = "-----------------------------\n";
		response = line + "QTY\tNAME\tPRICE PER ITEM\n" + line;
		CountItems();
		CalculateTotal();
		for (pair<Item*, int> qty: quantities)
		{
			stringstream stream;
			stream << fixed << setprecision(2) << qty.first->getPrice();
			string s = stream.str();
			response += to_string(qty.second) + " " + qty.first->getName() + "\t\x9C" + s + "\n";
		}
		response += line;
		response += "Total (ex. VAT) \x9C" + to_string(total - (total * tax)) + "\n";
		response += "Total (inc. VAT) \x9C" + to_string(total) + "\n";
		response += line;
		float tipTotal = total * tip;
		response += "Total tip\t\x9C" + to_string(tipTotal) + " @" + to_string(tip * 100) + "\n";
		response += "Total inc. tip\t" + to_string(total + tipTotal);

	}
	else
	{
		response = "No Items in order";
	}
	return response;
}

void Order::CountItems()
{
	quantities.clear();
	if(!items.empty()){
		for(Item* it : items){
			quantities[it] += 1;
		}
	}
}

void Order::SetTax(float t)
{
	// TODO implement an input for this
	tax = t;
}

void Order::SetTip(float t)
{
	// TODO implement an input for this
	tip = t;
}


