#ifndef TITLE_H
#define TITLE_H
/*
 * Title menu
 * Made by: Adam
 */
#include "menu.h"
#include "player.h"

class TitleMenu: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
}

#endif