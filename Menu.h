//
// Created by armon on 10/11/2023.
//

#ifndef TAKEAWAY_MENU_H
#define TAKEAWAY_MENU_H
#include <iostream>
#include "ItemList.h"

using namespace std;


class Menu : public ItemList
{
public:
	// TODO Not sure about this explicit Clang made me do it
	explicit Menu(string filePath);

	string ToString();


private:
	vector<string> Split (string str, char separator);
};


#endif //TAKEAWAY_MENU_H
