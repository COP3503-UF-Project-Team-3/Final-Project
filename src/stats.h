#ifndef STATS_H
#define STATS_H
/*
 * Stats menu
 * Made by: Allison
 * Edited by: Adam
 */

#include "menu.h"
#include "player.h"

class StatsMenu: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};

#endif