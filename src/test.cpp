#include <iostream>
#include "menu.h"
#include "title.h"
#include "store.h"

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

int main() {
	StoreMenu m;
	//Create player for testing
	Player p(false);
	p.name = "Bobby";
	p.intelligence = 10;
	p.strength = 5;
	p.dollars = 200;
	p.hours = 5;
	p.day = 0;

	// For testing
	// p.save();

	//Call my play function
	m.play(p);
	
	cout << endl << "Done playing" << endl;
	return 0;
}
