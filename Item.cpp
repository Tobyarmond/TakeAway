//
// Created by armon on 10/11/2023.
//

#include "Item.h"

using namespace std;

Item::Item(string n, float p, int c){
	name = n;
	price = p;
	calories = c;
}

string Item::ToString()
{
	// x9C is hex character for £
	return name + ":\t" + "\x9C" + to_string(price) +  ",\t" + to_string(calories) + "cal";
}
