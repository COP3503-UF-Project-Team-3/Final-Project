#ifndef STORE_H
#define STORE_H
#include "menu.h"
#include "item.h"

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
	//Change the prices of the items randomly d amount of times
	static void simulateMarket(std::vector<Item> &v);

private:
	static int LAST_DATE; //The last day the player entered the store

	//Prints the menu (Won't actually, I need the player object)
	void printMenu();
	//Prints the menu with the item prices (Mode is buy/sell)
	void printMenu(const Player &p, bool mode);

	//Will create the items and store them into the player
	void createItems(Player &p);

	//Purchase the item at the given index
	void purchase(Player &p, int item);
	//Sell the item at the given index
	void sell(Player &p, int item);
};

#endif
