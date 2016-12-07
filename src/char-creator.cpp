#include "char-creator.h"
#include <iostream>

using namespace std;

Player newChar() {
	cout << endl;
	cout << "Character Creation" << endl;

	// Declare a new `Player` object
	Player p(false);

	// Build the object field-by-field
	string name;
	cout << "Enter a name: ";
	cin >> name;
	p.name = name;

	// Choosing stats
	const int NUM_POINTS = 10;
	cout << endl;
	cout << "Please choose how to allocate points into the following attributes: " << endl;
	cout << "\t" << "- Intelligence" << endl;
	cout << "\t" << "- Strength" << endl;
	cout << "Number of points available: " << NUM_POINTS << endl;
	cout << endl;
	int in;
	int str;
	bool valid = false;
	while (!valid) {
		cout << "How many points would you like to allocate into intelligence? ";
		cin >> in;
		cout << "How many points would you like to allocate into strength? ";
		cin >> str;
		if (!cin.good()) {
			//Error check
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		} else if (in < 0 || str < 0) {
			cout << "You must enter positive numbers." << endl;
		} else if (in + str != NUM_POINTS) {
			cout << "The numbers must add to the number of available points." << endl;
		} else {
			valid = true;
		}
		cout << endl;
	}
	p.intelligence = in;
	p.strength = str;

	// Default values
	p.dollars = 0;
	p.hours = 18;
	p.day = 1;

	return p;
}
