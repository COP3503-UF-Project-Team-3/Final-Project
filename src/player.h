#ifndef PLAYER_H
#define PLAYER_H
/*
 *	`Player` struct
 *	Made by: Jazy
 *	Edited by: Adam
 */
#include "item.h"
#include "json-util.h"
#include <string>
#include <vector>

struct Player {
public:
	std::string name;
	int intelligence;
	int strength;
	int dollars;
	int hours; // Num left in day
	int day;
	std::vector<Item> inventory;
	
	Player(bool fromFile);

	/* 
	 *	Saves the `Player` object to the same path it was constructed from
	 *	Returns `true` on success
	 */
	bool save();
	void print();
private:
	const std::string path;
};

#endif
