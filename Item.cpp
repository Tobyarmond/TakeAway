//
// Created by armon on 10/11/2023.
//

#include "Item.h"
#include <sstream>
#include <iomanip>

using namespace std;

//
Item::Item(const string &n, float p, int c){
	name = n;
	price = p;
	calories = c;
	id = 0;
}

string Item::ToString()
{
	// Open a stringstream to reduce the number of decimal places to 2
	stringstream stream;
	stream << fixed << setprecision(2) << price;
	string s = stream.str();
	// x9C is hex character for £
	// FIXME This doesn't output to text files correctly.
	return name + ":\t" + "\x9C" + s +  ",\t" + to_string(calories) + "cal";
}

string Item::getName()
{
	return name;
}
int Item::getCalories()
{
	return calories;
}
float Item::getPrice()
{
	return price;
}

int Item::getID()
{
	return id;
}

bool Item::getTwoForOne()
{
	return false;
}
