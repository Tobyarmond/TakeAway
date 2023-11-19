//
// Created by armon on 10/11/2023.
//
#include "Menu.h"
#include <fstream>
#include <vector>
#include "ItemList.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

Menu::Menu(string filePath)
{
	// Open the CSV file and read the lines into seperate strings and store within a vector
	vector<string> lines;
	ifstream reader(filePath);
	// If file does not exist return out of function with error message
	if (! reader){
		cout << "Menu object could not be created - File does not exist" << endl;
		return;
	}
	// Read all CSV lines into lines vector
	while (! reader.eof()){
		string line;
		getline(reader,line,'\n');
		// THIS WAS THE CAUSE OF THE BUG THE EMPTY LINE!!!!!!
		if (!empty(line)){
			lines.push_back(line);
		}
	}
	reader.close();

	//Loop over all lines in lines vector and create corresponding objects
	// foreach string s in lines

	for(string s: lines){
		// Split the line into separate strings for each variable
		vector<string> line = Split(s, ',');

		string course;
		//the char s[0] could also be used instead but for readability purposes line[0] is used instead.
		course = line[0];
		// Because the name is already a string it could simply be put into the constructor call but is not for readability
		string name = line[1];
		float price =  stof(line[2]);
		int calories = stoi(line[3]);

		// If the course is an appetiser
		if (course == "a"){
			bool shareable = false;
			bool twoForOne = false;
			if (line[4] == "y"){
				shareable = true;
			}
			if (line[5] == "y"){
				twoForOne = true;
			}
			Item* ap = new Appetiser(name,price,calories,shareable,twoForOne);
			items.push_back(ap);

		}
		// If the course is a main
		else if (course == "m"){
			Item* mp = new MainCourse(name,price,calories);
			items.push_back(mp);
		}
		// If the course is a beverage
		else if (course == "b"){
			int volume = stoi(line[6]);
			float abv = stof(line[7]);
			Item* bp = new Beverage(name,price,calories,volume,abv);
			items.push_back(bp);
		}
	}
	// Sorts the items to ensure that appetisers are listed before mains etc.
	// This aids in the menus by enuring that certain food types come first.
	SortItemsByID();
}

// TODO split this into a different class of tools or similar
vector<string> Menu::Split(string str, char separator)
{
	vector<string> storage;
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= str.size())
	{
		if (str[i] == separator || i == str.size())
		{
			endIndex = i;
			string subStr = "";
			subStr.append(str, startIndex, endIndex - startIndex);
			storage.push_back(subStr);
			currIndex += 1;
			startIndex = endIndex + 1;
		}
		i++;
	}
	return storage;
}

// TODO Should change this to create the sorting in the instantiation of menu now I have an id attribute
string Menu::ToString()
{
	int i = 1;
	int currentID = 0;
	const string separator = "----------";
	string response = "";

	// if menu is not empty
	if (!items.empty()){
		for (Item* it : items)
		{
			// Print the headers when new course is encountered
			if(it->getID() > currentID){
				currentID = it->getID();
				switch (currentID)
				{
				case 1:
					response += separator + "Appetisers" + separator + "\n";
					break;
				case 2:
					response += separator + "Main Dishes" + separator + "\n";
					break;
				case 3:
					response += separator + "Beverages" + separator + "\n";
					break;
				}
			}
			// Add items to the menu
			response += to_string(i) + "." + it->ToString() + "\n";
			i++;
		}
		response += "All prices include taxes\n";
	}
	else{
		response = "The menu was empty\n";
	}
	return response;
}





