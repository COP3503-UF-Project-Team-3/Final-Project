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
    void printStatus(Player const &p) const;
    void printStatus(Player const &p, std::string const &msg) const;
    void updateStatus(Player const &p) const;
    void updateStatus(Player const &p, std::string const &msg) const;
    
};




#endif /* gym_h */
