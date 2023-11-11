//
// Created by armon on 10/11/2023.
//

#include "Appetiser.h"

Appetiser::Appetiser(string n, float p, int c, bool share, bool twoFor)
{
	name = n;
	price = p;
	calories = c;
	shareable = share;
	twoForOne = twoFor;
}

// TODO test this with no shareable and no 2-4-1
string Appetiser::ToString()
{
	string additions;
	if (shareable){
		additions += "\t (Shareable)";
	}
	if (twoForOne){
		additions += "\t (2-4-1)";
	}
	return Item::ToString() + additions;
}





