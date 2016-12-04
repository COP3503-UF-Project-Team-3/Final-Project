#ifndef HOME_H
#define HOME_H
/*
 * Home menu
 * Made by: Adam
 */

#include "menu.h"
#include "player.h"

class Home: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};

#endif