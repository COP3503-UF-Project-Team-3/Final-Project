#include "menu.h"
#include "player.h"

class Map: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};