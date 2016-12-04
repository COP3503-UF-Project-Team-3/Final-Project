#include <iostream>
#include "stats.h"
#include <string>

using namespace std;

void StatsMenu::play(Player &p) {
	clearConsole();
	cout << endl;
	cout << "Stats" << endl;
	cout << endl;
	cout << "Name: " << p.name << endl;
	cout << "Intelligence: " << p.intelligence << endl;
	cout << "Strength: " << p.strength << endl;
	cout << endl;
	cout << "Press any key to continue." << endl;
	getKey();
}

void StatsMenu::printMenu() {
}
