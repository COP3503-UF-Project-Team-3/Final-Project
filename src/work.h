#ifndef WORK_H
#define WORK_H
/*
 * Work menu
 * Made by: Arnold
 * Edited by: Adam
 */

#include "menu.h"
#include "player.h"

class Work: Menu {
public:
    void play(Player &p);
private:
    void printMenu();
};

#endif
