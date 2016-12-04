#include "bar.h"
#include "gym.h"
#include "home.h"
#include "htp.h"
#include "inventory.h"
#include "map.h"
#include "school.h"
#include "stats.h"
#include "store.h"
#include "work.h"
#include <iostream>

using namespace std;

void Map::play(Player &p) {
	char c;
	int errorCount = 0; // Counts the number of times an error message is displayed
	while (true) {
		clearConsole();
		printMenu();
		printStatus(p);

		c = getKey();

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
			errorCount++;

			// A list of different error messages so the user knows they are entering invalid input
			if(errorCount % 3 == 0)
				updateStatus(p, "Error: That input is invalid!");
			else if(errorCount % 3 == 1)
				updateStatus(p, "Error: Input invalid!");
			else
				updateStatus(p, "Error: Invalid input!");
		}
	}
}

// The Map!
void Map::printMenu() {

	cout << "\nWhere would you like to go?" << endl;
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
