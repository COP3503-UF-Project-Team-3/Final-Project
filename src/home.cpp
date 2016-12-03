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
    do {
        c = getKey();

	    if (c == '1') {
			p.hours = 18;
			++p.day;
			string msg = "Hours replensished, ";
			if (p.save()) {
				msg += "game saved. ";
			} else {
				msg += "unable to save game. ";
			}
			msg += " Make another choice.";
			updateStatus(p, msg);
		} else if (c == '2') {
			// Do nothing
		} else if (c == '3') {
			// Do nothing
		} else {
            // Choice is not '1'-'3'
            string err = "`" + string(1, c) + "` is not a valid choice.";
            updateStatus(p, err);
        }

    } while (c != '2' && c != '3');

	if (c == '3') {
		main(); // Essentially restart the game
	}
	
}

void Home::printMenu() {
	cout << "Home" << endl;
	cout << "\t" << "1. Sleep (save & replenish hours)" << endl;
	cout << "\t" << "2. Leave house" << endl;
	cout << "\t" << "3. Exit to title screen (without saving)" << endl;
	cout << "Make a choice." << endl;
}