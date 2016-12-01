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
    static void clearConsole();
    static void clearLine();
    
private:

    void printMenu();
    void printStatus(Player const &p) const;
    void printStatus(Player const &p, std::string const &msg) const;
    void updateStatus(Player const &p) const;
    void updateStatus(Player const &p, std::string const &msg) const;
    
};


#endif /* school_h */
