#include <iostream>
#include "player.h"

using namespace std;

#define FILE_PATH "player.json"

#define NAME_KEY 	"name"
#define INT_KEY 	"intelligence"
#define STR_KEY 	"strength"
#define DOL_KEY 	"dollars"
#define HOURS_KEY	"hours"
#define DAY_KEY		"day"
#define INV_KEY		"inventory"
#define QTY_KEY		"quantity"
#define PRICE_KEY	"price"

Player::Player(bool fromFile) {
	if (fromFile) {
		JSON obj = jsonFromFile(FILE_PATH);
		
		name = obj[NAME_KEY].get<string>();
		intelligence = obj[INT_KEY].get<int>();
		strength = obj[STR_KEY].get<int>();
		dollars = obj[DOL_KEY].get<int>();
		hours = obj[HOURS_KEY].get<int>();
		day = obj[DAY_KEY].get<int>();

		// Deserialize items
		// See: https://github.com/nlohmann/json
		inventory = {};
		JSON arr = obj[INV_KEY];
		for (JSON::iterator it = arr.begin(); it != arr.end(); ++it) {
	  		JSON j = *it;
	  		Item i;
	  		i.name = j[NAME_KEY].get<string>();
	  		i.quantity = j[QTY_KEY].get<int>();
	  		i.price = j[PRICE_KEY].get<int>();
	  		inventory.push_back(i);
		}
	}
}

bool Player::save() {
	JSON obj;
	obj[NAME_KEY] = name;
	obj[INT_KEY] = intelligence;
	obj[STR_KEY] = strength;
	obj[DOL_KEY] = dollars;
	obj[HOURS_KEY] = hours;
	obj[DAY_KEY] = day;

	// Serialize items
	JSON inv;
	for (vector<Item>::iterator it = inventory.begin() ; it != inventory.end(); ++it) {
		Item i = *it;
		JSON j;
		j[NAME_KEY] = i.name;
		j[QTY_KEY] = i.quantity;
		j[PRICE_KEY] = i.price;
		inv.push_back(j);
	}
	obj[INV_KEY] = inv;

	return writeJSON(obj, FILE_PATH);
}

void Player::print() {
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Intelligence: " << intelligence << endl;
	cout << "Strength: " << strength << endl;
	cout << "Cash: $" << dollars << endl;
	cout << "Hours left: " << hours << endl;
	cout << "Day: " << day << endl;
	cout << endl;
}