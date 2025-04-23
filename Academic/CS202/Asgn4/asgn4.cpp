/**
 * Alec Him, 2001543593, CS 202 1004, Assignment 4
 * Description: Museum Entry Management System with Visitor and Staff Tracking
 * Input: Visitor/Staff names, ages, votes, admin credentials
 * Output: Entry/exit logs, room popularity statistics
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include "entrylog.hpp"
#include "visitor.hpp"
#include "staff.hpp"
#include "person.hpp"

using namespace std;

int main()
{
    // Variables
    bool exit = false;
    int choice = 0;
    entrylog entry;
    MenuPrint menu;

    // Prompt Menu
    do
    {
        menu.printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        if(cin.fail() || (choice < 1 && choice > 5))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Wrong Option! Please choose it again...!" << endl;
            continue;
        }

        switch(choice)
        {
            case 1:
                entry.visitorIn();
                break;
            case 2:
                entry.visitorOut();
                break;
            case 3:
                entry.staffIn();
                break;
            case 4:
                entry.staffOut();
                break;
            case 5:
                exit = entry.exitMain();
                break;
        }
    } while(!exit);
    
    // Logic to output winCount based on voting from visitors during visitor_out
    if(entry.winCount.artRoom > 0)
        cout << "Art Room Reviews: " << entry.winCount.artRoom << endl;
    if(entry.winCount.scienceRoom > 0)
        cout << "Science Room Reviews: " << entry.winCount.scienceRoom << endl;
    if(entry.winCount.historicObject > 0)
        cout << "Historic Object Room Reviews: " << entry.winCount.historicObject << endl;
    
    // Display Message based on bubbleSort
    if(entry.winCount.artRoom == entry.winCount.scienceRoom && entry.winCount.scienceRoom == entry.winCount.historicObject)
        cout << "All of our rooms in the museum are popular!" << endl;
    else
    {
        int winArray[3] = {entry.winCount.artRoom, entry.winCount.scienceRoom, entry.winCount.historicObject};

        // Create a bubble sort to find out which room was voted most popular
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3 - i; j++)
                if(winArray[j] < winArray[j + 1])
                    swap(winArray[j], winArray[j + 1]);

        // Display Popular Room
        cout << "The most popular room in the museum is ";
        if(winArray[3] == entry.winCount.artRoom)
            cout << "the Art Room!" << endl;
        else if(winArray[3] == entry.winCount.artRoom)
            cout << "the Science Room!" << endl;
        else
            cout << "the Historic Object Room!" << endl;
    }

    // Exit Message
    cout << "\nExiting the software... Bye! Bye!\n" << endl;

    return 0;
}