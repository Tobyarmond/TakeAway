//
// Created by armon on 15/11/2023.
//

#include <iostream>
#include "UserInterface.h"

using namespace std;

void UserInterface::Introduction()
{
	cout << "#####################################################\n"
			"#            TakeAway Ordering System               #\n"
			"# Toby Armond (27050587) University of Lincoln 2023 #\n"
			"#                                                   #\n"
			"#####################################################\n"
			"Welcome to the TakeAway ordering system!" << endl;
			Help();
}

void UserInterface::Help()
{
 	cout << "To use the application simply enter the command then press enter, some commands require an amount.\n"
			 "For more information on a command enter a ? after the command\n"
			 "Possible commands:\n"
			 "menu\n"
			 "add\n"
			 "remove\n"
			 "checkout\n"
			 "help\n"
			 "exit" << endl;
}

// Could try using a switch with enum if possible but not till much later
void UserInterface::Help(const std::string& param)
{
	if(param == "menu"){
		cout << "Displays the menu available\n"
				"No other inputs are required\n"
				"menu <>"<< endl;
	}
	else if (param == "add"){
		cout << "Add items to the order\n"
				"Requires menu items corresponding menu number available from the menu\n"
				"add <menu number> e.g add 2\n"
				"To add multiple items add the number required after the selection\n"
				"add <menu number> <quantity> e.g add 2 3" << endl;
	}
	else if (param == "remove"){
		cout << "Removes items from the order\n"
				"Requires corresponding menu number available from the menu\n"
				"remove <menu number> e.g remove 4\n" << endl;
	}
	else if (param == "checkout"){
		cout << "Shows items in the current order and totals\n"
				"A prompt of whether you would like to confirm is given\n"
				"enter n to leave the checkout or y to print your receipt and exit the program" << endl;
	}
	else if (param == "help"){
		cout << "Shows help instructions for commands or general help\n"
				"help <> : general help \n"
				"help <command> : command specific help" << endl;
	}
	else if (param == "exit"){
		cout << "Exits the program \n"
				"exit <>" << endl;
	}
	else{
		cout << "Command not recognised try typing help to see a list of possible commands" << endl;
	}
}
