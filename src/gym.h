#ifndef gym_h
#define gym_h

/*
 * Gym menu
 * Created by Paula
 *
 */

#include "menu.h"
#include "player.h"

class Gym:Menu {
    
public:
    
    void play(Player &p);
    
private:
    
    void printMenu();
    
};




#endif /* gym_h */
