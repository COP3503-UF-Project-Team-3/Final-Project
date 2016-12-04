//School menu

#include <iostream>
#include "menu.h"
#include "school.h"

using namespace std;

//Prints out schooling options for user to select from. Each option has the possibility of awarding more intelligence than others, however they will respectively take more hours to accomplish.
void School::printMenu() {
    cout << "Hello, Student! Here you will increase intelligence. Every key you hit will cost you at least an hour. Select one of the following: \n" <<
    "1. Lecture (+3) (1-3 hours) \n" <<
    "2. Lab (+1) (1-3 hours) \n" <<
    "3. Project (+10) (1-3 hours) \n" <<
    "Q. Leave \n";
}

//Play function for school
void School::play(Player &p) {
    
    char i;
    do {
        clearConsole();
        printMenu();
        printStatus(p);
        
        i = getKey();
        
        clearConsole();
        
        if (p.hours - 3 < 0 && i != 'q'){
            cout << "You don't have enough hours, go home." << endl;
        }
        
        if (p.hours - 3 >= 0){
            int scenario = (rand() % 7) + 1; //Generates a random number 1-7 for our possible 7 scenarios of what can occur at school
            
            if (scenario == 1){ //Series of if-statements correlating to each scenario
                if (i == '1'){ //User chose "Lecture" option
                    cout << "You showed up to your COP3503 class and payed attention the whole time. Good job! (+3)" << endl;
                    p.intelligence += 3;
                    p.hours = p.hours - 2; //Decrease 2 hrs if lecture is chosen.
                }
                else if (i == '2'){ //User chose "Lab" option
                    cout << "You showed up to your COP3503 lab and payed attention the whole time. Good job! (+1)" << endl;
                    p.intelligence += 1;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){ //User chose "Project" option
                    cout << "You were given two weeks to complete PA3 and you finished in a few hours! (+10)" << endl;
                    p.intelligence += 10;
                    p.hours = p.hours - 3;  //Decrease 3 hrs if project is chosen
                    
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            
            else if (scenario == 2){
                if (i == '1'){
                    cout << "Twenty minutes into the lecture your professor notices no one did the reading they were supposed to. She is angry and spends rest of class complaining. (+1)" << endl;
                    p.intelligence += 1;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "Your lab TA notices you are working at a quick pace and can tell you studied your manual prior to lab. He decides to give you extra credit! (+3)" << endl;
                    p.intelligence += 3;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){
                    cout << "You finished your project in time but forgot to include your header file in the submission. Your TA docks off some points. (+8)" << endl;
                    p.intelligence += 8;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            else if (scenario == 3){
                if (i == '1'){
                    cout << "The lecture you attended was Good Life. It was so boring that you fell asleep and didn't learn anything :(" << endl;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "Oh no! You walked all the way to class just to find out lab was canceled :(" << endl;
                }
                else if (i == '3'){
                    cout << "You sat down to start your project but fell into Harry Potter movie marathon... You watched all 8 movies in one sitting and missed the deadline :(" << endl;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            else if (scenario == 4){
                if (i == '1'){
                    cout << "Today's lecture was Physics. Going to class ended up being worth it when your professor accidentally injured himself when performing a demo. Don't worry, hes okay. (+3)" << endl;
                    p.intelligence += 3;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "In the middle of Chem lab you look over and your partner's pants are on fire. You failed the lab but at least you learned the content! (+1)" << endl;
                    p.intelligence += 1;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){
                    cout << "You finally got through your rough project. You're proud of yourself but probably never want to look at a computer screen again. (+10)" << endl;
                    p.intelligence += 10;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            else if (scenario == 5){
                if (i == '1'){
                    cout << "Your professor said they were probably going to let everyone leave early today and ended up going 5 minutes overtime. :/ At least you learned something! (+3)" << endl;
                    p.intelligence += 3;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "You forgot to study your lab manual before coming to class and were going to have to use this as your drop. Turns out your partner was a pro and carried you. (+1)" << endl;
                    p.intelligence += 1;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){
                    cout << "The professor was feeling lenient and assigned an easy project. (+10)" << endl;
                    p.intelligence += 10;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            else if (scenario == 6){
                if (i == '1'){
                    cout << "It seemed like class was never going to end today but you made it out alive. (+3)" << endl;
                    p.intelligence += 3;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "A bunch of students touring the school got in your way and you were 5 minutes late. Luckily your TA was understanding and let it slide. (+1)" << endl;
                    p.intelligence += 1;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){
                    cout << "You sat down and got the job done. (+10)" << endl;
                    p.intelligence += 10;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
            else if (scenario == 7){
                if (i == '1'){
                    cout << "You got really hungry and zoned out for what ended up being the entire class. Oops." << endl;
                    p.hours = p.hours - 2;
                }
                else if (i == '2'){
                    cout << "The partner you were assigned today didn't show up and you were clueless the whole time. Guess this is your drop?" << endl;
                    p.hours = p.hours - 1;
                }
                else if (i == '3'){
                    cout << "You completely underestimated how long it would take to finish your project and didn't turn it in on time." << endl;
                    p.hours = p.hours - 3;
                }
                else if (i != 'q') {
                    cout << "Invalid input" << endl;
                }
            }
        }
        if (i != 'q'){
            cout << endl << "Hit any key to continue" << endl;
            getKey();
        }
        
        
    } while (i != 'q');
    //Exits play function
}
