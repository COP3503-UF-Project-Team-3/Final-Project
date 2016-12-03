#include <iostream>
#include <cstdlib>
#include <string>
#include "work.h"

using namespace std;

void Work::printMenu() { //This will present the player's options at the workplace.
    
    cout<<"Let's get to work! The job won't get done on its own. Pick a task from the list below.\n\n";
    cout<<"1. Company meeting \n";
    cout<<"2. Field task \n";
    cout<<"3. Computer work \n";
    cout<<"4. Paper work \n";
    cout<<"5. Leave\n\n";
    char choice;
    cout<<"Choice: ";
    choice=getKey();
    cin>>choice;

}

void Work::play(Player &p) {
    
    clearConsole();
    printMenu():
    printStatus(p);
    char choice;
    cout<<"Choice: ";
    choice=getKey();
    cin>>choice;
    
    int event = rand()%7+1; //This will randomly select a workplace event depending on the player's choice of activity.
    
    do {
    
        if (choice==1) {

            if (event==1) {

                cout<<"Everyone gets a pay raise because of recent impressive gains.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==2) {

                cout<<"You have been tapped as project manager for the next major project.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

            else if (event==3) {

                cout<<"Everyone loses a portion of their salary for a recent faulty project.";
                p.dollars-=5;
                p.hours-=1;

            }

            else if (event==4) {

                cout<<"You are responsible for bringing food to the meeting.";
                p.dollars-=5;
                p.hours-=1;

            }

            else if (event==5) {

                cout<<"You must pitch ideas for an open-ended project proposed by a client.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==6) {

                cout<<"You are asked to go on an out-of-state business project next month.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else {

                cout<<"You are sent home early for completing work quicker than anticipated.";
                p.dollars+=0;
                p.hours+=1;

            }

        }

        else if (choice==2) {

            if (event==1) {

                cout<<"The owner of a locally-owned restaurant needs a program that handles income and inventory.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==2) {

                cout<<"The city government enlists your help with a utility department's computer program.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==3) {

                cout<<"A local insurance company needs assistance with removing software bugs from its security infrastructure.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==4) {

                cout<<"The app for the city transit system is in need of updates to enhance real-time features.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==5) {

                cout<<"The local school district's online information database is in need of enhanced security measures.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==6) {

                cout<<"The local arena is in search of assistance with graphics for entertainment during events.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

            else {

                cout<<"You must lead a team of workers in installing completely new software at a local TV affiliate.";
                p.dollars+=(20+p.intelligence);
                p.hours-=4;

            }

        }

        else if (choice==3) {

            if (event==1) {

                cout<<"You must revamp a program that was written five years ago.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

            else if (event==2) {

                cout<<"You must start implementing a new programming language for a new project.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==3) {

                cout<<"You are in charge of the personal computer repair operations for the day.";
                p.dollars+=(25+p.intelligence);
                p.hours-=5;

            }

            else if (event==4) {

                cout<<"You are in charge of website design/interface services for clients today.";
                p.dollars+=(25+p.intelligence);
                p.hours-=5;

            }

            else if (event==5 or event==6) {

                cout<<"You must tackle writing an assigned fragment of a program.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

            else {

                cout<<"You are in charge of operating system upgrade services for the day.";
                p.dollars+=(20+p.intelligence);
                p.hours-=4;

            }

        }

        else if (choice==4) {

            if (event==1) {

                cout<<"You must assist the company manager in organizing the employee payroll.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==2) {

                cout<<"You must write up payment contracts for recent clients.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

            else if (event==3) {

                cout<<"You must draft write-ups for a program requested by a local fast-food restaurant.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==4) {

                cout<<"You must shred old plans that are no longer relevant to current projects.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else if (event==5) {

                cout<<"You must write a quarterly/monthly report about the company's recent operations.";
                p.dollars+=(15+p.intelligence/2);
                p.hours-=3;

            }

            else if (event==6) {

                cout<<"You must assist in framing a public advertisement for the company.";
                p.dollars+=(5+p.intelligence/4);
                p.hours-=1;

            }

            else {

                cout<<"You must mail proposal packets to affiliate companies.";
                p.dollars+=(10+p.intelligence/2);
                p.hours-=2;

            }

        }

        else {

            cout<<"Have a great evening. We will see you when you get back!";

        }
    
    }
    
    while (p.hours>0);
    
    if (p.hours<=0) {
        
        cout<<"Please go home and sleep. You have had a long day, and you need some rest.\n\n";
        printMenu();
        
    }
    
}
