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
#define MQ				"marketQuantity"
#define MR				"MAX_RESTOCK"
#define MP				"MAX_PRICE"
#define MIP				"MIN_PRICE"
#define MAR				"MARKET_RANGE"
#define MAM				"MARKET_MIN"

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
		vector<Item> inv;
		JSON arr = obj[INV_KEY];
		for (JSON::iterator it = arr.begin(); it != arr.end(); ++it) {
	  		JSON j = *it;
	  		Item i;
	  		i.name = j[NAME_KEY].get<string>();
	  		i.quantity = j[QTY_KEY].get<int>();
	  		i.price = j[PRICE_KEY].get<int>();
				//Extras by Jazy
	  		i.marketQuantity = j[MQ].get<int>();
	  		i.MAX_RESTOCK = j[MR].get<int>();
	  		i.MAX_PRICE = j[MP].get<int>();
	  		i.MIN_PRICE = j[MIP].get<int>();
	  		i.MARKET_RANGE = j[MAR].get<int>();
	  		i.MARKET_MIN = j[MAM].get<int>();
	  		inv.push_back(i);
		}
		inventory = inv;
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
		//Extras by Jazy
		j[MQ] = i.marketQuantity;
		j[MR] = i.MAX_RESTOCK;
		j[MP] = i.MAX_PRICE;
		j[MIP] = i.MIN_PRICE;
		j[MAR] = i.MARKET_RANGE;
		j[MAM] = i.MARKET_MIN;
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
	cout << "Items: " << endl;
	for (unsigned int j = 0; j < inventory.size(); ++j) {
		Item i = inventory.at(j);
		cout << "\t" << "{name: " << i.name << ", qty: " << i.quantity << ", price: " << i.price << "}" << endl;
	}
	cout << endl;
}
