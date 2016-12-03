#include <cstddef>
#include "htp.h"
#include <iostream>
#include <stdexcept>
#include "title.h"

using namespace std;

int main() {
	
	return 0;
}

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
	
	if (c == '1') {
		cout << "New Game!" << endl;
		// Send them to the `How To Play` screen without a character
		HTPMenu m;
		m.play();
	} else if (c == '2') {
		// Initialize a `Player` object from a JSON file
		Player *ptr = NULL;
		try {
			Player old(true);
			ptr = &old;
		} catch (exception &e) {
			cout << "Unable to retrieve the saved character." << endl;
			cout << endl;
		}
		if (ptr == NULL) {
			cout << "Starting a new game..." << endl;
			HTPMenu m;
			m.play();
		} else {
			cout << "Continuing the story of " << ptr->name << "..." << endl;
			cout << endl;
			// Map m;
			// m.play(*ptr);
		}
	} else {
		// User tapped '3'
		cout << "Quit!" << endl;
		// Do nothing so the program exits
	}
}

void TitleMenu::printMenu() {
	cout << "Stick RPG" << endl;
	cout << endl;
	cout << "\t" << "1. New Game" << endl;
	cout << "\t" << "2. Continue" << endl;
	cout << "\t" << "3. Quit" << endl;
	cout << endl;
}

