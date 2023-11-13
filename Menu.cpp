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
		// TODO not sure if this is required
		if (!line.empty()){
			course = line[0];
		}
		float price =  stof(line[2]);
		int calories = stoi(line[3]);
		// TODO could possibly change this to a pointer as information is already a string
		string name = line[1];

		// If the course is an appetiser
		if (course == "a"){
			bool shareable = false;
			bool twoForOne = false;
			if (line[3] == "y"){
				shareable = true;
			}
			if (line[4] == "y"){
				twoForOne = true;
			}
			items.push_back(Appetiser(name,price,calories,shareable,twoForOne));
		}
		// If the course is a main
		else if (course == "m"){
			items.push_back(MainCourse(name,price,calories));
		}
		// If the course is a beverage
		else if (course == "b"){
			int volume = stoi(line[6]);
			float abv = stof(line[7]);
			items.push_back(Beverage(name,price,calories,volume,abv));
		}
	}
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





