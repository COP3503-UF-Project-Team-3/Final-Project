#ifndef PLAYER_H
#define PLAYER_H
/*
 *	Basic Player struct made for testing purposes
 *	Made by: Jazy
 */
#include "item.h"
#include <string>
#include <vector>
//Player struct
struct Player {
	std::string name;
	int intel;
	int str;
	int money;
	int time; //Hours in day remaining
	int day;
	std::vector<Item> inventory;
	//Constructors
	//Player(std::string filename);
};

#endif //PLAYER_H
