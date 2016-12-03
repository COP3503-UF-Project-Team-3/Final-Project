#include "menu.h"
#include "player.h"
#include "home.h"
#include "work.h"
#include "gym.h"
#include "bar.h"
#include "store.h"

class Map: Menu {
public:
	void play(Player &p);
private:
	void printMenu();
};
