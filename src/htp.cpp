#include "htp.h"
#include <iostream>

using namespace std;

// User chose to continue or asked for help while playing
void HTPMenu::play(Player &p) {
	showRules();
	// FIXME: show map
	// Map m;
	// m.play(&p);
}
// User chose to start a new game
void HTPMenu::play() {
	showRules();
	// Go to character creation
}

void HTPMenu::showRules() {
	printMenu();
	cout << "Hit any key to continue!" << endl;
	getKey();
}

void HTPMenu::printMenu() {
	cout << endl;
	cout << "How To Play" << endl;
}
