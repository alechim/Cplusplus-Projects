/** 
 * CS 202 - FALL 2020
 * This skeleton code was developed by James Piotrowski - UNLV Computer Science
 */ 
#include <iostream>
#include <string>
#include <fstream>
#include "WeaponClass.h"

using namespace std;

/***********************************************************************************/
/*                              Super Class                                        */
/***********************************************************************************/

class PlayerClass
{
    public:
        PlayerClass();                          // Constructors
        PlayerClass(char, string, int, int);
        ~PlayerClass();                         // Destructor
        void EquipWeapon(string);               // Will alter the Weapon in the WeaponSlot.
        void DoDamage(PlayerClass&);            // Will do damage to another player.
        void TakeDamage(int);                   // A function to subtract from HealthPoints.

        char GetPlayerType();           // Returns the PlayerType
        string GetPlayerName();         // Returns the PlayerName
        static int GetPlayerCount();    // Returns the PlayerCount -- This is Static

    /* Protected Members. Derived class instances will be able to inheret and access
     * these members. Protected is not accesible to anything but the Base Class and
     * Derived Classes. 
     */

    protected:
        string PlayerName;          // PlayerName --> {PlayerType Color} + {PlayerCount} --> i.e. "Red1", "Blue2", "Blue3", "Green4", etc..
        char PlayerType;            // Either 'r', 'b', 'g'
        int Strength;               // Strength Level
        int Skill;                  // Skill Level
        int HealthPoints;           // Health Points --> 25 by default
        WeaponClass WeaponSlot;     // Choice of Weapon
        static int PlayerCount;     // Keeps track of the number of Players. Should be incremented in Constructors -- Notice it is Static
        ofstream out;               // For the Player Log
};

// Initializes PlayerCount to 0
int PlayerClass::PlayerCount = 0;

// Constructs PlayerClass
PlayerClass::PlayerClass()
{
    PlayerName = "";        // Player Name to Empty String
    PlayerType = '\0';      // Player Type to NULL
    Strength = 0;           // Sets Strength to 0
    Skill = 0;              // Sets Skill to 0
    HealthPoints = 25;      // Sets Health to 25
    PlayerCount++;          // Increments Player Count
}

// PlayerClass Constructor with Parameters
PlayerClass::PlayerClass(char type, string name, int str, int sk)
{
    // Store parameters into class protected variables
    PlayerType = type;
    PlayerName = name;
    Strength = str;
    Skill = sk;
    
    // Variables
    HealthPoints = 25;  
    string file = name + ".txt";  // Creates filenames (i.e: Red1.txt)

    // Opens Created File Name and Inputs PlayerName to Log File
    out.open(file);
    out << name << " has been spawned." << endl;
}

// PlayerClass Deconstructor
PlayerClass::~PlayerClass()
{
    if(out.is_open())
    {
        out << PlayerName << " has been despawned." << endl;
        out.close();
    }
}

// Displays and Sets in Log File the amount of damage a player takes and "despawns" players when Health <= 0
void PlayerClass::TakeDamage(int damage)
{
    cout << PlayerName << " has taken " << damage << " damage!" << endl;    // Prints message onto screen
    out << PlayerName << " took " << damage << " damage." << endl;          // Writes this in the out file (Player Log)

    HealthPoints = HealthPoints - damage;

    if(HealthPoints <= 0)
    {
        HealthPoints = 0;
        cout << PlayerName << " has reached 0 health! They can no longer battle..." << endl;
        out << PlayerName << " has reached 0 health." << endl;
        this->~PlayerClass();
    }
}

// Placement function to calculate damage dealt to other players; overridden by other Player Type DoDamage Functions
void PlayerClass::DoDamage(PlayerClass& pClass)
{
    int damage = WeaponSlot.CalculateDamage(Strength, Skill);
    char enemyType = pClass.GetPlayerType();
    switch(enemyType)
    {
        case 'r':
        case 'b':
        case 'g':
            pClass.TakeDamage(damage);
            break;
    }
}

// Changes the current weapon players have equipped with the inputted one and displays the info in the log file
void PlayerClass::EquipWeapon(string weapon)
{
    // Replaces current weapon with inputted one
    WeaponSlot.SetWeapon(weapon);

    if(weapon != "Sword" && weapon != "Bow" && weapon != "Staff")
        weapon = "Bare Hands";

    // Enters that PlayerName has equipped a weapon in the log file
    out << PlayerName << " equipped a " << weapon << "." << endl;
}

/************************************************************************************/
/*                              Red Class                                           */
/************************************************************************************/

class RedClass: public PlayerClass
{
    public:
        RedClass();                     // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// Red Class Constructor
RedClass::RedClass() : PlayerClass('r', "Red" + to_string(PlayerCount), 3, 1)
{
    PlayerCount++;
}

// Red Class Damage Dealt
void RedClass::DoDamage(PlayerClass& red)
{
    // Variables
    string Enemy = red.GetPlayerName();  // Creates Enemy to store and test player type
    char EnemyType = red.GetPlayerType();

    // Displays message in terminal and stores in player log
    out << PlayerName << " is attacking " << Enemy << "." << endl;
    cout << PlayerName << " is attacking " << Enemy << "." << endl;

    // Calculates Damage based on Enemy Type
    int damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            damage = damage / 2;
            red.TakeDamage(damage);
            cout << "That was not very effective..." << endl;
            break;
        case 'b':
            red.TakeDamage(damage);
            break;
        case 'g':
            damage = damage * 2;
            red.TakeDamage(damage);
            cout << "That was super effective!" << endl;
    }
}

/************************************************************************************/
/*                              Blue Class                                          */
/************************************************************************************/

class BlueClass: public PlayerClass
{
    public:
        BlueClass();                    // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// Blue Class Constructor
BlueClass::BlueClass(): PlayerClass('b', "Blue" + to_string(PlayerCount), 1, 3)
{
    PlayerCount++;
}

// Blue Class Damage Dealt
void BlueClass::DoDamage(PlayerClass& blue)
{
    // Variables
    string Enemy = blue.GetPlayerName();    // Creates Enemy to store and test player type
    char EnemyType = blue.GetPlayerType();  

    // Displays message in terminal and stores in player log
    out << PlayerName << " is attacking " << Enemy << endl;
    cout << PlayerName << " is attacking " << Enemy << endl;

    // Calculates Damage based on Enemy Type
    int damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            damage = damage * 2;
            blue.TakeDamage(damage);
            cout << "That was super effective!" << endl;
            break;
        case 'b':
            damage = damage / 2;
            blue.TakeDamage(damage);
            cout << "That was not very effective..." << endl;
            break;
        case 'g':
            blue.TakeDamage(damage);
            break;
    }
}

/************************************************************************************/
/*                              Green Class                                         */
/************************************************************************************/

class GreenClass: public PlayerClass
{
    public:
        GreenClass();                   // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// Green Class Constructor
GreenClass::GreenClass(): PlayerClass('g', "Green" + to_string(PlayerCount), 2, 2)
{
    PlayerCount++;
}

// Green Class Damage Dealt
void GreenClass::DoDamage(PlayerClass& green)
{
    // Variables
    string Enemy = green.GetPlayerName();       // Creates Enemy to store and test player type
    char EnemyType = green.GetPlayerType();
  
    // Displays message in terminal and stores in player log
    out << PlayerName << " is attacking " << Enemy << endl;
    cout << PlayerName << " is attacking " << Enemy << endl;

    int damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            green.TakeDamage(damage);
            break;
        case 'b':
            damage = damage * 2;
            green.TakeDamage(damage);
            cout << "That was super effective!" << endl;
            break;
        case 'g':
            damage = damage / 2;
            green.TakeDamage(damage);
            cout << "That was not very effective..." << endl;
    }
}

// - Getter Functions
char PlayerClass::GetPlayerType() { return PlayerType; }
string PlayerClass::GetPlayerName() { return PlayerName; }
int PlayerClass::GetPlayerCount() { return PlayerCount; }