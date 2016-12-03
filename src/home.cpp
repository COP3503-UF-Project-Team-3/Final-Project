#include "home.h"
#include "title.h"
#include <string>

using namespace std;

void Home::play(Player &p) {
	clearConsole();
	printMenu();
	printStatus(p);

	// Choice loop
	char c;
	bool once = false;
	do {
		if (once) {
			string msg = "`" + string(1,c) + "` " + " is an invalid choice.";
			updateStatus(p, msg);
		}
		once = true;
		c = getKey();
	} while (c != '1' && c != '2' && c != '3');

	if (c == '1') {
		p.hours = 18;
		++p.day;
		string msg = "Hours replensished, ";
		if (p.save()) {
			msg += "game saved. ";
		} else {
			msg += "unable to save game. ";
		}
		msg += " Hit any key to continue...";
		updateStatus(p, msg);
		getKey();
		play(p);
	} else if (c == '2') {
		// Leave house, so do nothing
	} else if (c == '3') {
		main(); // Essentially restart the program
	}
}

void Home::printMenu() {
	cout << "Home" << endl;
	cout << "\t" << "1. Sleep (save & replenish hours)" << endl;
	cout << "\t" << "2. Leave house" << endl;
	cout << "\t" << "3. Exit (without saving)" << endl;
	cout << "Make a choice." << endl;
}