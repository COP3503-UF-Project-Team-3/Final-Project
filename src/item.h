#ifndef ITEM_H
#define ITEM_H
/*
 * Item struct
 */
#include <string>

struct Item {
	std::string name;
	int quantity;
	int price; //Do we want to deal with doubles?
};
#endif //ITEM_H
