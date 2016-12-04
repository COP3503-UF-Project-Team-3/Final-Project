#ifndef ITEM_H
#define ITEM_H
/*
 * Item struct
 */
#include <string>

struct Item {
	std::string name;
	int quantity;
	int marketQuantity; //Amount available for purchase
	int price; //Do we want to deal with doubles? Na
	int MAX_RESTOCK; //Max amount to restock by
	int MAX_PRICE; //Prevent price from exceeding this limit
	int MIN_PRICE; 
	int MARKET_RANGE; //Variation in market price
	int MARKET_MIN; //Min change in market price (Can be negative)
};
#endif //ITEM_H
