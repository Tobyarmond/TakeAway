//
// Created by armon on 10/11/2023.
//

#include "Beverage.h"

Beverage::Beverage(string n, float p, int c, int v, float a)
{
	name = n;
	price = p;
	calories = c;
	abv = a;
	volume = v;
}

string Beverage::ToString()
{
	string additions = "\t(" + to_string(volume) + "ml";
	if (abv > 0){
		additions += ",\t" + to_string(abv) + "%";
	}
	additions += ")";

	return Item::ToString() + additions;
}
