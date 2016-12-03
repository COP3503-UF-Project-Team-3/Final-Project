#include "char-creator.h"
#include "htp.h"
#include <iostream>

using namespace std;

// User asked for help while playing
void HTPMenu::play(Player &p) {
	showRules();
	p.print();
	// FIXME: show map
	// Map m;
	// m.play(&p);
}
// User is starting a new game
void HTPMenu::play() {
	showRules();
	// Go to character creation
	Player p = newChar();
	p.print();
	// FIXME: show map
	// Map m;
	// m.play(&p);
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
