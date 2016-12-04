#include <cstddef>
#include "htp.h"
#include <iostream>
#include <stdexcept>
#include "title.h"
#include "map.h"

using namespace std;

void printMenu() {
	cout << "Stick RPG" << endl;
	cout << endl;
	cout << "\t" << "1. New Game" << endl;
	cout << "\t" << "2. Continue" << endl;
	cout << "\t" << "3. Quit" << endl;
	cout << endl;
}

int main() {
	// Wait for choice
	char c;
	bool chose = false;
	do {
		Menu::clearConsole();
		printMenu();
		cout << "Tap the key of your choice to begin!" << endl;
		if (chose) {
			cout << "`" << c << "` is an invalid choice." << endl;
		} else {
			cout << endl;
		}
		c = Menu::getKey();
		chose = true;
	} while(c != '1' && c != '2' and c != '3');

	// User made a valid choice
	Menu::clearConsole();
	
	if (c == '1') {
		//cout << "New Game!" << endl;
		// Send them to the `How To Play` screen without a character
		HTPMenu m;
		m.play();
	} else if (c == '2') {
		// Initialize a `Player` object from a JSON file
		Player *ptr = NULL;
		try {
			ptr = new Player(true);
		} catch (exception &e) {
			cout << "Unable to retrieve the saved character." << endl;
			cout << endl;
		}
		if (ptr == NULL) {
			cout << "Starting a new game..." << endl;
			cout << "\n\nPress any key to continue...";
			Menu::getKey();
			HTPMenu m;
			m.play();
		} else {
			cout << "Continuing the story of " << ptr->name << "..." << endl;
			cout << "\n\nPress any key to continue...";
			Menu::getKey();
			Map m;
			m.play(*ptr);
		}
	} else {
		// User tapped '3'
		cout << "Quit!" << endl;
		// Do nothing so the program exits
		exit(0);
	}

	return 0;
}

