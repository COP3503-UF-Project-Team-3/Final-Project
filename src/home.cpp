#include "home.h"
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
			string err = "`" + c + "` " + " is an invalid choice.";
			updateStatus(p, err);
		}
		once = true;
		c = getKey();
	} while (c != '1' && c != '2' && c != '3');

	if (c == '1') {
		
	} else if (c == '2') {

	} else if (c == '3') {

	}
}

void Home::printMenu() {
	cout << "Home" << endl;
	cout << "\t" << "1. Sleep (save & replenish hours)" << endl;
	cout << "\t" << "2. Leave house" << endl;
	cout << "\t" << "3. Exit (without saving)" << endl;
	cout << "Make a choice." << endl;
}