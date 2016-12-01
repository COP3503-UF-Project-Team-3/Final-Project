#ifndef INVENTORY_H
#define INVENTORY_H
/*
 * Inventory menu
 * Made by: Allison
 * Edited by: Adam
 */

#include "menu.h"
#include "player.h"

class InventoryMenu: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};

#endif