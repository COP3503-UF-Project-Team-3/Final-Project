#include "inventory.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void InventoryMenu::play(Player &p) {
	cout << endl;
	cout << "Inventory" << endl;
	cout << endl;

	vector<Item> inventory = p.inventory;
	if (inventory.empty()) {
		cout << "Your inventory is empty." << endl;
	} else {
		for (int i = 0; i < inventory.size(); ++i) {
			Item item = inventory.at(i);
	    	cout << (i + 1) << ". " << item.name << endl;
    	}
	}

  	cout << endl;
  	cout << "Press any key to continue." << endl;
  	getKey();
}

void InventoryMenu::printMenu() {
}

