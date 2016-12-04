#ifndef MENU_H
#define MENU_H
#include <string>
#include "player.h" //Player class

class Menu {
protected:
	//Print menu should print out the appropriate menu. The function
	//must be individually implemented to your specifications.
	//NOTE: There really is no point to this function other than to
	//assist in the subclass development. IE: You can declare this to do
	//nothing and print the menu how ever you want.
	virtual void printMenu() = 0;

	//Prints 1 line containing the neccessary player information
	//NOTE: This function should be run within the play function, immediately
	//after printMenu (For consistency)
	void printStatus(Player const &p) const;
	
	//Similar to the above function, but will append msg to the end of the 
	//status info.
	//NOTE: Keep msg short to avoid overflowing into the next line!
	void printStatus(Player const &p, std::string const &msg) const;

	//Update status is similar to print status, difference is that
	//updateStatus will remove the last printed line in the console
	//and print the status on it. Basically this function will update just
	//the status line of the console, instead of having to reprint the
	//whole menu.
	void updateStatus(Player const &p) const;
	void updateStatus(Player const &p, std::string const &msg) const;

public:
	//This function will hold all the logic pertaining to your store/building
	//You will use the printMenu and printStatus functions within this play
	//function.
	virtual void play(Player &p) = 0;

	//UTILITY FUNCTIONS (Poor design)
	//Can be called without menu object! Ex: Menu::clearConsole();
	
	//Clear console (Utility function) Probably shouldn't put this in here
	//but what ever. Everyone will be inheriting from this class anyways
	static void clearConsole();

	//Clear the last line that was outputted
	static void clearLine();

	//Intercepts and returns the next key the user enter. 
	static char getKey();
};


#endif //MENU_H
