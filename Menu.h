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
	Menu(string filePath);


private:
	vector<string> Split (string str, char seperator);
};


#endif //TAKEAWAY_MENU_H
