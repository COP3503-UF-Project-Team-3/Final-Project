#ifndef BAR_H
#define BAR_H
/*
 * Bar menu
 * Made by: Arnold
 * Edited by: Adam
 */

#include "player.h"
#include "menu.h"

class Bar: Menu {
public:
	void play(Player &p);
	Bar();
private:
	void printMenu();
	int menu();
	void leave();
	string randomNight(int rank);
	int drunkeness;
	int hype;
};