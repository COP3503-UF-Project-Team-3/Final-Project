#ifndef TITLE_H
#define TITLE_H
/*
 * Title menu
 * Made by: Adam
 */
#include "menu.h"
#include "player.h"

int main();

class TitleMenu: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};

#endif

