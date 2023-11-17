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
#include "UserInterface.h"

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
	// Assignment driver code
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	// Create a UserInterface object
	UserInterface userInterface = UserInterface();

	// Show introduction screen
	userInterface.Introduction();


	while (userCommand != "exit")
	{
		string command = "";
		// I think this is hogging cin. Try using user command to get input if needed
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
			command = parameters[0];
		}


		if (!parameters.empty()){
			if (parameters[1] == "?"){
				userInterface.Help(parameters[0]);
			}
			else{
				if (command.compare("menu") == 0) {
					cout << menu.ToString();
					parameters.clear();
				}
				else if (command.compare("add") == 0)
				{

					// FIXME typing add during qty prompt adds one more
					// FIXME typing add with no argument causes a crash
					if(parameters.size() > 1 ){
						// FIXME this could not be able to be turned into an integer
						int menuNumber = stoi(parameters[1]) - 1;
						// If the number selected is not greater than the size of the menu or less than 1
						if (menuNumber < menu.GetSize() && menuNumber > 0){
							Item* choice = menu.GetItem(menuNumber);
							if (parameters.size() == 3){
								order.AddItem(choice, stoi(parameters[2]));
							}
							 // you need to instantiate this using the menu object!
							else{
								order.AddItem(choice,1);
							}
						}
						else{
							cout << "Please choose a number within the menu" << endl;
						}

					}
					else{
						cout << "Please enter a number corresponding to an item. For help enter ? after command" << endl;
						// TODO check this is needed

					}
					parameters.clear();
					// You may also wish to implement the ability to add multiple items at once!
					// e.g. add 1 5 9
				}
				else if (command.compare("remove") == 0)
				{
					// This is reused maybe make this common to add and remove somehow
					Item* choice = menu.GetItem(stoi(parameters[1])-1);
					order.RemoveItem(choice);
				}
				else if (command.compare("checkout") == 0)
				{
					cout << order.ToString();
				}
				else if (command.compare("help") == 0)
				{
					userInterface.Help();
				}
				else
				{
					cout << "Command not recognised. Type help for list of commands" << endl;
				}
			}
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

	// TODO all memory needs to be released
	return 0;
}