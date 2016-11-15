#include "htp.h"
#include <iostream>
#include "title.h"

using namespace std;

#define FILE_PATH "../player.json"

void TitleMenu::play(Player &p) {
	clearConsole();
	
	// Wait for choice
	char c;
	bool chose = false;
	do {
		if (chose) {
			cout << "`" << c << "` is an invalid choice." << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		printMenu();
		cout << "Tap the key of your choice to begin!" << endl;
		cout << endl;
		c = getKey();
		chose = true;
	} while(c != '1' && c != '2' and c != '3');

	// User made a valid choice
	cout << "You chose `";
	if (c == '1') {
		cout << "New Game";
		// Send them to the `How To Play` screen without a character
		Player newP("");
		HTPMenu m;
		m.play(newP);
	} else if (c == '2') {
		cout << "Continue";
		// Initialize a `Player` object from a JSON file
		Player oldP(FILE_PATH);
		HTPMenu m;
		m.play(oldP);
	} else {
		// User tapped '3'
		cout << "Quit";
		// Do nothing so the program exits
	}
	cout << "`" << endl;
}

void TitleMenu::printMenu() {
	cout << "Stick RPG" << endl;
	cout << endl;
	cout << "\t" << "1. New Game" << endl;
	cout << "\t" << "2. Continue" << endl;
	cout << "\t" << "3. Quit" << endl;
	cout << endl;
}

