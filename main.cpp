/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "ItemList.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
#include <iomanip>

using namespace std;

// TODO
// Fix decimal places with price float
// Change access levels for member variables within classes.
// Fix rounding error with string to float conversion
// Fix ToString of child objects not being called.
// Fix deal with objects created but not destroyed.
// Create destructors
// This is because the things stored in the vector become Item rather than the course they were instantiated as.
// List has been used instead but this will cause problems when selecting the option from the menu instead items will have to be an array


int main()
{
	cout << setprecision(4);
	Menu menu = Menu("menu.csv");
	Appetiser a = Appetiser("aardvark", 32.0, 255, true, true);
	MainCourse mc = MainCourse("Quavers", 16.5, 500);
	Beverage b = Beverage("Beer", 5.2, 200, 568, 4.0);

	//cout << a.ToString() << endl;
	//cout << mc.ToString() << endl;
	//cout << b.ToString() << endl;

	cout << menu.ToString() << setprecision(4);

	//cout << typeid(menu.items).name() << endl;
	//for (auto i : menu.items){
		//cout << typeid(*i).name() << endl;

		//cout << i->ToString() << endl;
	//}


	// Assignment driver code
	/*
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			Item* choice; // you need to instantiate this using the menu object!
			order.add(choice);

			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 
		}
		else if (command.compare("remove") == 0)
		{

		}
		else if (command.compare("checkout") == 0)
		{

		}
		else if (command.compare("help") == 0)
		{

		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();
	 */

	return 0;
}