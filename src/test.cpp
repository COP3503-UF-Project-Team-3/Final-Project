/*
 *	This file is intended for menu testing. Simply include your Menu class at the top and
 *	create an instance of it in the main function below. You can also look at/modify the
 *	sample MyMenu class I made below and instantiate that.
 *
 *	To build the project simply run `make` in cmd/terminal
 *	A finalproject.out will be created which you can run to test the game
 *
 *	When ever you want to rebuild completely it is best to first run `make clean` then run `make`
 *	This ensures that any stray object files are rebuilt. Useful for when switch branches/changed header files/or just clearing
 *	up the workspace.
 */

#include <iostream>
#include "menu.h"
#include "title.h" //PLACE YOUR HEADER FILE HERE

using namespace std;

//My own menu declaration, inheriting from the Menu class
class MyMenu:Menu {
	//My print menu (Can be omitted to do nothing)
	void printMenu() {
		cout << "Hello World \n" <<
		"This is my menu!\n" <<
		"Every key you hit will cost you an hour\n\n" <<
		"Hit q to quit\n";
	}
	//NOTE: Play must be public
public:
	//The play function that contains MyMenu's game logic (loop)
	void play(Player &p) {
		clearConsole(); //Clear the console first
		printMenu();
		printStatus(p); //Should always be right after you print your menu
		char i;
		do {
			i = getKey();
			p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1; //Decrease hour
			if (p.hours == 0) {
				p.day++;
				p.hours = 18;
			}
			updateStatus(p); //If you only need to change the status then
			//use this function. That way you dont have to be constantly
			//clearing the console and printing the whole menu
			
			string str = "You hit ";
			str += i;
			updateStatus(p, str); //You can even append a message
		} while (i != 'q');
		//Simply exit out of the function and return to whomever
		//called this play function
	}
};

/*
 *	The main function. Instantiate your menu class here and run play on it to test it
 *	A sample player object is created for testing purposes here as well
 */

// int main() {
// 	TitleMenu m; //Replace this variable type with the name of your class to test it
// 	//Create player for testing
// 	Player p(false);
// 	p.name = "Bobby";
// 	p.intelligence = 5;
// 	p.strength = 5;
// 	p.dollars = 200;
// 	p.hours = 5;
// 	p.day = 0;

// 	// For testing
// 	// p.save();
	
// 	cout << "Initializing game..." << endl;
// 	//Call play function
// 	m.play(p);
// 	cout << endl << "Done playing" << endl;
// 	return 0;
// }
