#ifndef MAP_H
#define MAP_H
/*
 * Map menu
 * Made by: Jared
 * Edited by: Adam
 */

#include "menu.h"
#include "player.h"

class Map: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};

#endif