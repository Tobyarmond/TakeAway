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

	}
	else if (param == "add"){

	}
	else if (param == "remove"){

	}
	else if (param == "checkout"){

	}
	else if (param == "help"){

	}
	else if (param == "exit"){

	}
	else{
		cout << "Command not recognised try typing help to see a list of possible commands" << endl;
	}
}
