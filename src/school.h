#ifndef school_h
#define school_h

/*
 * School menu
 * Created by Paula
 *
 */

#include "menu.h"
#include "player.h"

class School:Menu {

public:
    
    void play(Player &p);
    
private:

    void printMenu();
 
};


#endif /* school_h */
