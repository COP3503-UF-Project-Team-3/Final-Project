#include <iostream>
#include "map.h"

using namespace std;

void Map::play(Player &p) {
	clearConsole();
	printMenu();
	printStatus(p);


	cout << "\nWhere would you like to go? (1-6)" << endl;
	char c;
	bool valid = false;
	int errorCount = 0; // Counts the number of times an error message is displayed
	while (!valid) {

		c = getKey();

		valid = true;
		if (c == '1') {
			Home h;
			h.play(p);
		} else if (c == '2') {
			Work w;
			w.play(p);
		} else if(c == '3') {
			Gym g;
			g.play(p);
		} else if(c == '4') {
			Bar b;
			b.play(p);
		} else if(c == '5') {
			Store s;
			s.play(p);
		} else if(c == '6') {
			School sc;
			sc.play(p);
		} else if (c == 'i') {
			InventoryMenu i;
			i.play(p);
		} else if (c == 's') {
			StatsMenu s;
			s.play(p); 
		} else if (c == 'h') {
			HTPMenu h;
			h.play(p);
		} else {
			valid = false;
			errorCount++;

			if(errorCount > 1) // Don't want to clear the first message
				clearLine(); // Now let's clear it and write in a new one

			// A list of different error messages so the user knows they are entering invalid input
			if(errorCount % 3 == 0)
				cout << "Error: That input is invalid! Please select an integer between 1 and 5.";
			else if(errorCount % 3 == 1)
				cout << "Error: Input invalid! Valid inputs include integers ranging from 1 to 5.";
			else
				cout << "Error: Invalid input! Please enter an integer between 1 and 5.";
		}
	}
}

// The Map!
void Map::printMenu() {
	cout <<
" _______________________________________________________\n" <<
"|       |  |                             |  |          |\n" <<
"|Home(1)|  |                             |  |          |\n" <<
"|_______|  |_____________________________|  |          |\n" <<
"|_______    ______________________________  |  Work(2) |\n" <<
"|       |  |                             |  |          |\n" <<
"|       |  |                             |  |          |\n" <<
"|       |  |            Gym(3)           |  |__________|\n" <<
"|       |  |                             |  |          |\n" <<
"|       |  |                             |  |          |\n" <<
"|_______|  \\_____________________________/  |          |\n" <<
"|       \\___________________________________/          |\n" <<
"|              |                       |               |\n" <<
"|    Bar(4)    |        Store(5)       |    School(6)  |\n" <<
"|              |                       |               |\n" <<
"|______________|_______________________|_______________|\n";
cout << endl;
cout << "(i) - inventory" << endl;
cout << "(s) - stats" << endl;
cout << "(h) - how to play" << endl;
}
