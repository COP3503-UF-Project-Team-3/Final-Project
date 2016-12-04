#include "char-creator.h"
#include "htp.h"
#include <iostream>
#include "map.h"

using namespace std;

// User asked for help while playing
void HTPMenu::play(Player &p) {
	showRules();
}
// User is starting a new game
void HTPMenu::play() {
	showRules();
	// Go to character creation
	Player p = newChar();
	Map m;
	m.play(p);
}

void HTPMenu::showRules() {
	clearConsole();
	printMenu();
	cout << "Hit any key to continue!" << endl;
	getKey();
}

void HTPMenu::printMenu() {
	cout << endl;
	cout << "How To Play" << endl;
	// Write tutorial here
	cout << "Welcome to Stick RPG!" << endl; 
	cout << "Here you will be able to craft your own character that will live in his own little world." << endl; 
	cout << "They are free to do whatever they choose - as long as there are enough hours left in the day." << endl;
	cout << "You can go to work, the gym, the store, the bar and school." << endl;
	cout << "In each location you will find an adventure that awaits you." << endl; 
	cout << "You can work out, buy CHEESE, and even have a drink with your friends." << endl;
	cout << "In order to navigate the game, simply type into the console." << endl; 
	cout << "Good luck!" << endl;
}
