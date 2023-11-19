//
// Created by armon on 10/11/2023.
//

#include "Order.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>

void Order::CalculateTotal()
{
	// TODO might need to have both 241 items in the offer.
	// TODO consider adding tax calculation to this.
	// Clear total before recalculating
	total = 0;
	for(pair<Item*,int> qty : quantities){
		// if item is two for one and greater than 1
		if(qty.first->getTwoForOne() && qty.second > 1){
			total += qty.first->getPrice() * (qty.second / 2 + (qty.second % 2));
		}
		else{
			total += qty.first->getPrice() * qty.second;
		}
	}
}

void Order::PrintReceipt()
{
	// TODO need to add a const for the location of the receipt output
	ofstream outputStream("receipt.txt",std::ios::out|std::ios::binary);
	if(outputStream){
		outputStream << this->ToString();
	}
	else{
		cout << "The receipt could not be printed!" << endl;
	}
	outputStream.close();
}

void Order::AddItem(Item* item,int qty = 1)
{
	for (int i = 0; i < qty; i++){
		items.push_back(item);
	}
	SortItemsByID();
	cout << to_string(qty) + " " + item->getName() + " added to order" << endl;
}

void Order::RemoveItem(Item* item)
{
	auto index = find(items.begin(),items.end(),item);
	if (index != items.end()){
		int pos = distance(items.begin(),index);
		items.erase(index);
		cout << item->getName() + " removed from order" << endl;
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
		tax = 0.2;
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
		response += "Total (inc. VAT @"+ to_string(tax*100) + "%) \x9C" + to_string(total) + "\n";
		response += line;
		float tipTotal = total * tip;
		response += "Total tip\t\x9C" + to_string(tipTotal) + " @" + to_string(tip * 100) + "\n";
		response += "Total inc. tip\t" + to_string(total + tipTotal) + "\n";
	}
	else
	{
		response = "No Items in order \n";
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

// TODO need to add a const for the location of the receipt output
void Order::CompleteCheckout()
{
	if (!items.empty()){
		string response;
		bool getInput = true;
		while (getInput){
			cout << "Are you happy with your order? y/n" << endl;
			cin >> response;
			if (response == "y"){
				PrintReceipt();
				cout << "Copy of receipt output to receipt.txt" << endl;
				getInput = false;
			}
			else if (response == "n"){
				getInput = false;
			}
			else{
				cout << "Please enter either y or n" << endl;
			}
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




