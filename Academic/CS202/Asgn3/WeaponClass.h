/** 
 * CS 202 - FALL 2020
 * This skeleton code was developed by James Piotrowski - UNLV Computer Science
 */ 
#include <iostream>
#include <string>

using namespace std;

/***********************************************************************************/
/*                              Weapon Class                                       */
/***********************************************************************************/

class WeaponClass
{
    public:
        WeaponClass();                  // Constructor
        string GetName();               // GetName returns the WeaponName
        void SetWeapon(string);         // Changes the Weapon Name
        int CalculateDamage(int, int);  // Determines damage dealt by weapon
    private:
        string name;            // The Weapon Name - "Sword", "Bow", "Staff", or "Bare Hands"
        const int Damage = 3;   // Base Damage for all Weapons except Bare Hands
};

// Constructor Function
WeaponClass::WeaponClass()
{
    name = "Bare Hands";  // Sets weapon name to bare hands
}

// Reads and returns the name of the weapon
string WeaponClass::GetName() { return name; }

// Sets the name of the weapon to the string
void WeaponClass::SetWeapon(string weapon)
{
    // Tests whether the weapon name matches, "Sword", "Bow", or "Staff"
    if(weapon != "Sword" && weapon != "Bow" && weapon != "Staff")
    {
        weapon = "Bare Hands";
        cout << "ERROR: Unknown Weapon" << endl;
    } else 
        name = weapon;
}

// Calculates damage based on weapon type
int WeaponClass::CalculateDamage(int Strength, int Skill)
{
    int Calculation = 0;    // Used to store the calculations of damage based on each weapon
    int temp = 0;           // Used as a place holder to store and test the absolute value of Strength - Skill

    // Tests whether the weapon name is Sword and Calculates Damage based on Weapon Type
    if(name == "Sword")
    {
        Calculation = Strength * Damage;    
        cout << "**CLANG**" << endl;        
    // Tests whether the weapon name is Staff and Calculates Damage based on Weapon Type
    } else if(name == "Staff")
    {
        Calculation = Skill * Damage;       
        cout << "**POW**" << endl;          
    // Tests whether the weapon name is Bow and Calculates Damage based on Weapon Type
    } else if(name == "Bow")
    {
        // Placement to get absolute value of strength - skill
        temp = Strength - Skill;

        // Change negative value to positive value
        if(temp < 0)
            temp = temp * -1;

        Calculation = (Damage - temp) * Damage;     
        cout << "**FWOOSH**" << endl;               
    // Tests whether the weapon name is none of the above and sets Damage to 1
    } else
    {
        Calculation = 1;                
        cout << "**pfft**" << endl;     
    }

    return Calculation;
}
