#ifndef HTP_H
#define HTP_H
/*
 * How to play
 * Made by: Adam
 */
#include "menu.h"
#include "player.h"

class HTPMenu: Menu {
public:
	void play(Player &p);
	void play();
private:
	void showRules();
	void printMenu();
};

#endif