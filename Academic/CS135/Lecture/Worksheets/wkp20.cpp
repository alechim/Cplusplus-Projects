#include <iostream>

using namespace std;

// Function Prototypes
void reverseNames(string pet[], string owner[], int size);

int main()
{
    // Variables
    string pet[5] = {"Hobbs", "Snoopy", "Odie", "Garfield", "Pluto"};
    string owner[5] = {"Calvin", "Charlie", "Jon", "Jon", "Mickey"};

    cout << "Initial array values" << endl;

    for(int i = 0; i < 5; i++)
        cout << pet[i] << " " << owner[i] << endl;

    reverseNames(pet, owner, 5);

    cout << endl << "After reverse" << endl;

    for(int i = 0; i < 5; i++)
        cout << pet[i] << " " << owner[i] << endl;
    
    return 0;
}

// Function Definitions
void reverseNames(string pet[], string owner[], int size)
{
    string petReverse[5];
    string ownerReverse[5];
    size = 4;

    for(int i = 0; i < 5; i++)
    {
        petReverse[i] = pet[size];
        ownerReverse[i] = owner[size];
        size--;

        if(size == -1)
        {
            for (int i = 0; i < 5; i++)
            {
                pet[i] = petReverse[i];
                owner[i] = ownerReverse[i];
            }
        }
    }
}