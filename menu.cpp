#include "menu.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include "conio.h" //getch
#include <string>
#include "player.h" //Player class

//class Menu
//protected:
	//Print menu should print out the appropriate menu. The function
	//must be individually implemented to your specifications.
	//virtual void printMenu() = 0;

	//Prints 1 line containing the neccessary player information
	//NOTE: This function should be run within the play function, immediately
	//after printMenu (For consistency)
	void Menu::printStatus(Player const &p) const {
		std::cout << "Hours: " << std::setw(4) << std::left <<
			p.time << "$" << std::setw(6) << std::left <<
			p.money << "Day: " << std::setw(4) << std::left <<
			p.day;
	}
	
	//Similar to the above function, but will append msg to the end of the 
	//status info.
	//NOTE: Keep msg short to avoid overflowing into the next line!
	void Menu::printStatus(Player const &p, std::string const &msg) const {
			printStatus(p);
			std::cout << "(" << msg << ")";
	}

	//Update status is similar to print status, difference is that
	//updateStatus will remove the last printed line in the console
	//and print the status on it. Basically this function will update just
	//the status line of the console, instead of having to reprint the
	//whole menu.
	void Menu::updateStatus(Player const &p) const {
		clearLine();
		printStatus(p);
	}
	void Menu::updateStatus(Player const &p, std::string const &msg) const {
		clearLine();
		printStatus(p, msg);
	}

	//Intercepts and returns the next key the user enter. 
	//NOTE: Function will hold until the user presses a key
	char Menu::getKey() const {
		return (char)getch();
	}

//public:
	//This function will hold all the logic pertaining to your store/building
	//You will use the printMenu and printStatus functions within this play
	//function.
	//virtual void play(Player &p) = 0;

	//Clear console (Utility function) Probably shouldn't put this in here
	//but what ever. Everyone will be inheriting from this class anyways
	void Menu::clearConsole() {
		std::string nuke = std::string(120, '\n'); //May a little excessive
		std::cout << nuke;
	}

	//Clear the last line that was outputted
	void Menu::clearLine() {
		std::cout << char(13); //Carriage return
		std::cout << std::string(80, ' ') << char(13); //Clear
	}


