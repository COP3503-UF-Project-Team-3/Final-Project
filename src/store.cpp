#include "menu.h"
#include "item.h"
#include "player.h"
#include "menu.h"
#include "store.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime> //For srand

/*
 *	The store will allow the player to purchase items and sell them back
 *	at changing prices. The store will attempt to simulate an actual market
 *	where prices of items vary on a daily bases.
 */
using namespace std;

int StoreMenu::LAST_DATE = 0; //The last day the player entered the store

StoreMenu::StoreMenu() {
	lastItem = -1;
	lastAmount = 0;
}

//My play function for the store
void StoreMenu::play(Player &p) {
	createItems(p); //Make sure the items are there
	bool selling = false;
	//Stimulate the market according the days that have passed
	for ( ; LAST_DATE < p.day; LAST_DATE++) {
		simulateMarket(p.inventory);
	}
	//Print the menu
	printMenu(p, selling);
	//Game loop
	char choice;
	do {
		//Wait for choice
		choice = getKey();
		if (choice == 'q') {
			//Do nothing?
		} else if (choice == 's') {
			selling = (selling) ? false : true; //Toggle selling
			printMenu(p, selling);
			/*
			} else if (choice == 'd') { //Debug
			p.day++;
			play(p);
			return;
			*/
		} else if ((choice - '1') >= 0 
				&& (choice - '1') < (int)p.inventory.size()) {
			//An item has been selected
			int item = choice - '1';
			if (selling) {
				sell(p, item);
			} else {
				purchase(p, item);
			}
		} else {
			//Invalid?
			const string INVALID = "Invalid choice: ";
			updateStatus(p, INVALID + choice);
		}
	} while (choice != 'q');
}

//Prints the menu (Won't actually, I need the player object)
void StoreMenu::printMenu() {
	//This funtion should never be called
	cout << "Error in store menu!" << endl;
}
//Prints the menu with the item prices
void StoreMenu::printMenu(const Player &p, bool selling) {
	//Player is needed so this is the function that will be called
	clearConsole();
	cout << "\t*************************" << endl;
	cout << "\t* Welcome to the store! *" << endl;
	cout << "\t*************************" << endl;
	cout << endl << endl;
	string mode = (selling) ? "SELLING" : "BUYING";
	cout << "You are currently " << mode << endl << endl;
	//Print items and prices
	for (unsigned int i=0; i<p.inventory.size(); i++) {
		Item item = p.inventory[i];
		string stock = (item.marketQuantity > 0) ? "" : "Out of Stock";
		cout << "\t" << i+1 << ". " << 
			item.name << " \t$" << item.price <<
			"\t(" << item.quantity << ")" << " " << stock << endl;
	}
	cout << endl;
	//Finished printing items
	cout << "s. To toggle selling/buying modes" << endl;
	cout << "q. To exit" << endl << endl;
	cout << "\tSelect an option" << endl << endl;
	printStatus(p);
}

//Change the prices of the items randomly d amount of times
void StoreMenu::simulateMarket(std::vector<Item> &v) {
	srand(time(NULL)); //Blow on the dice
	for (unsigned int i=0; i<v.size(); i++) {
		Item& item = v[i];
		int change = (rand()%item.MARKET_RANGE) + item.MARKET_MIN;
		item.price += change;
		if (item.price > item.MAX_PRICE) {
			item.price = item.MAX_PRICE;
		} else if (item.price < item.MIN_PRICE) {
			item.price = item.MIN_PRICE;
		}
		//Restock
		change = rand()%item.MAX_RESTOCK;
		item.marketQuantity += change;
	}
}

//Will create the items and store them into the player
void StoreMenu::createItems(Player &p) {
	if (p.inventory.empty() == false)
		return;
	//This function should only run once completely
	Item item;
	item.name = "Apple";
	item.quantity = 0;
	item.marketQuantity = 50;
	item.MAX_RESTOCK = 3;
	item.MAX_PRICE = 8;
	item.MIN_PRICE = 1;
	item.MARKET_RANGE = 4;
	item.MARKET_MIN = -2;
	item.price = 2;
	p.inventory.push_back(item);

	item.name = "Cheese";
	item.quantity = 0;
	item.marketQuantity = 30;
	item.MAX_RESTOCK = 1;
	item.MAX_PRICE = 30;
	item.MIN_PRICE = 4;
	item.MARKET_RANGE = 8;
	item.MARKET_MIN = -3;
	item.price = 8;
	p.inventory.push_back(item);

	item.name = "Wine";
	item.quantity = 0;
	item.marketQuantity = 20;
	item.MAX_RESTOCK = 1;
	item.MAX_PRICE = 100;
	item.MIN_PRICE = 8;
	item.MARKET_RANGE = 15;
	item.MARKET_MIN = -8;
	item.price = 18;
	p.inventory.push_back(item);
	//NOTE: Modify values above according to game wide values
}

//Purchase the item at the given index
void StoreMenu::purchase(Player &p, int item) {
	const string l = "Purchased ";
	//Increment counter for concecutive purchases
	if (item == lastItem) {
		lastAmount++;
	} else {
		lastAmount = 1;
		lastItem = item;
	}
	Item& i = p.inventory[item];
	//Check for errors
	if ((p.dollars - i.price) < 0) {
		updateStatus(p, "Insufficient funds!");
	} else if (i.marketQuantity < 1) {
		updateStatus(p, "Out of Stock!");
	} else {
		//All good?
		p.dollars -= i.price;
		i.marketQuantity--;
		i.quantity++;
		printMenu(p, false);
		//NOTE: C++11 needed for to_string!
		updateStatus(p, l + to_string(lastAmount) + ' ' + i.name); //Mix all the types!
		//updateStatus(p);
	}
}
//Sell the item at the given index
void StoreMenu::sell(Player &p, int item) {
	const string l = "Sold ";
	//Increment counter for concecutive sales
	if (item == lastItem) {
		lastAmount++;
	} else {
		lastAmount = 1;
		lastItem = item;
	}

	Item& i = p.inventory[item];
	//Check for errors
	if (i.quantity < 1) {
		updateStatus(p, "Non Available!");
	} else {
		//All good?
		p.dollars += i.price;
		i.marketQuantity++;
		i.quantity--;
		printMenu(p, true);
		//NOTE: C++11 needed for to_string!
		updateStatus(p, l + to_string(lastAmount) + ' ' + i.name); //Mix all the types!
		//updateStatus(p);
	}
}


