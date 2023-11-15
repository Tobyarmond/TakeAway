//
// Created by armon on 10/11/2023.
//

#include "Appetiser.h"

Appetiser::Appetiser(string n, float p, int c, bool share, bool twoFor) : Item(n,p, c)
{
	shareable = share;
	twoForOne = twoFor;
	id = 1;
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

bool Appetiser::getTwoForOne()
{
	return twoForOne;
}





