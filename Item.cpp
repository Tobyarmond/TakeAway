//
// Created by armon on 10/11/2023.
//

#include "Item.h"
using namespace std;



string Item::ToString()
{
	return name + ":\t" + "£" + to_string(price) +  ",\t" + to_string(calories) + "cal";
}
