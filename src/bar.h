#ifndef BAR_H
#define BAR_H
/*
 * Bar menu
 * Made by: John
 * Edited by: Adam
 */

#include "player.h"
#include "menu.h"
#include <string>

class Bar: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
	int menu(Player &p);
	void leave();
	std::string randomNight(int rank);
	int drunkeness;
	int hype;
};
#endif
