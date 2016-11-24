#ifndef STORE_H
#define STORE_H
#include "menu.h"

/*
 *	The store menu
 *	This menu will allow the player to purchase or sell items at varied
 *	prices. The prices will vary slightly everyday.
 *	Created by Jazy
 */

class StoreMenu:Menu {
public:
	//My play function for the store
	void play(Player &p);

private:
	static int lastDate; //The last day the player entered the store

	//Prints the menu (Won't actually, I need the player object)
	void printMenu();
	//Prints the menu with the item prices
	void printMenu(const Player &p);

	//Change the prices of the items randomly d amount of times
	void modifyPrices(std::vector<Item> &v);
	//Will create the items and store them into the player
	void createItems(Player &p);

}

#endif
