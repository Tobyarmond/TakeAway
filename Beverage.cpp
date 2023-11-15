//
// Created by armon on 10/11/2023.
//

#include "Beverage.h"
#include <sstream>
#include <iomanip>

Beverage::Beverage(string n, float p, int c, int v, float a) : Item(n,p,c)
{
	abv = a;
	volume = v;
	id = 3;
}

string Beverage::ToString()
{
	stringstream stream;
	stream << fixed << setprecision(1) << abv;
	string s = stream.str();
	string additions = "\t(" + to_string(volume) + "ml";
	if (abv > 0){
		additions += ",\t" + s + "%";
	}
	additions += ")";

	return Item::ToString() + additions;
}
