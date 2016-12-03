//Gym menu

#include <iostream>
#include "menu.h"
#include "gym.h"

using namespace std;

//Prints out work out options for user to select from. The options that have the possibility of
//awarding more strength will take more hours to accomplish.
void Gym::printMenu() {
    cout << "Welcome to the gym! Working out increases your strength. Choose a workout: \n" <<
    "1. Cardio (+1) \n" <<
    "2. Upper body (+3) \n" <<
    "3. Lower body (+3) \n" <<
    "Q. Leave \n";
}

//Play function for gym
void Gym::play(Player &p) {
    clearConsole();
    printMenu();
    printStatus(p);
    char i;
    do {
        i = getKey();
        p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1; //Decrease hour for hitting key
        if (p.hours == 0) {
            p.day++;
            p.hours = 18;
        }
        
        int scenario = (rand() % 7) + 1; //Generates a random number 1-7 for our possible 7 scenarios of what can occur at the gym
        
        if (scenario == 1){ //Series of if-statements correlating to each scenario
            if (i == '1'){ //User chose "Cardio" option
                cout << "You just killed it on the elliptical, good job! (+1)" << endl;
               
                p.strength += 1;
               
            }
            else if (i == '2'){ //User chose "Upper-body" option
                cout << "You set yourself a new record for pull-ups, good job! (+3)" << endl;
                p.strength += 3;
               
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1; //Decrease 1 more hour if lifting
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){ //User chose "Lower-body" option
                cout << "You did your heaviest leg press to date, good job! (+3)" << endl;
                p.strength += 3;
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1; //Decrease 1 more hour if lifting
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }
        
        else if (scenario == 2){
            if (i == '1'){
                cout << "Five minutes in and you face-plant the treadmill. It was so embarassing that you ended up leaving early." << endl;
                
            }
            else if (i == '2'){
                cout << "Your arms gave out mid chest press. It wasn't a pretty sight." << endl;
                
            }
            else if (i == '3'){
                cout << "You were in the middle of squatting when your pants ripped. You ran out of the weight room but there was no hiding this." << endl;

            }
        }
        
        else if (scenario == 3){
            if (i == '1'){
                cout << "You ran 3 miles in record timing! (+1)" << endl;
                p.strength += 1;
            }
            else if (i == '2'){
                cout << "You may never be able to raise your arms again after that. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){
                cout << "You never want to hear the word lunge again after that. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }
        
        else if (scenario == 4){
            if (i == '1'){
                cout << "You took a spin class and got so pumped that you almost fell off the bike. (+1)" << endl;
                p.strength += 1;
            }
            else if (i == '2'){
                cout << "It was shoulder day and you killed it. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){
                cout << "You were trying to show off and didn't hurt yourself. Good job! (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }
        
        else if (scenario == 5){
            if (i == '1'){
                cout << "You played a game of basketball and scored the winning shot! (+1)" << endl;
                p.strength += 1;
            }
            else if (i == '2'){
                cout << "Your arms feel like you were carrying around a baby elephant for an hour. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){
                cout << "You were doing calf raises and your leg cramped up. It was brutal but you recovered quickly. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }
        
        else if (scenario == 6){
            if (i == '1'){
                cout << "You ran the treadmill and didn't fall this time. (+1)" << endl;
                p.strength += 1;
            }
            else if (i == '2'){
                cout << "You had too much preworkout and lifted heavier than you should have. This is gonna hurt tomorrow. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){
                cout << "You didn't drink enough water and almost passed out but recovered. (+3)" << endl;
                p.strength += 3;
                
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }
        
        else if (scenario == 7){
            if (i == '1'){
                cout << "You were playing basketball and.. let's just say there was a lot of bleeding involved." << endl;
            }
            else if (i == '2'){
                cout << "You had so much energy that mid curl you threw the weight at the huge guy behind you. Run!" << endl;
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
            else if (i == '3'){
                cout << "You were doing your last lunge when you heard a crack. That can't be good." << endl;
                p.hours = (p.hours - 1 < 0) ? 0 : p.hours - 1;
                if (p.hours == 0) {
                    p.day++;
                    p.hours = 18;
                }
            }
        }

        updateStatus(p);
        
    } while (i != 'q');
    //Exits play function
}
