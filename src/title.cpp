#include <iostream>
#include "title.h"

using namespace std;

void TitleMenu::play(Player &p) {
	cout << "PLAY!!!" << endl;
}

void TitleMenu::printMenu() {
	cout << "\t\t\t" << "Stick RPG" << endl;
	cout << endl;
	cout << "\t" << "1. New Game" << endl;
	cout << "\t" << "2. Continue" << endl;
	cout << "\t" << "3. Quit" << endl;
}

