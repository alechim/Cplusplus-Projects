/**
 * Alec Him, 2001543593, CS135 1009, Lab 9
 * Description: Fibonacci Numbers
 * Input: ./a.out <x> <y>
 * - x: the position of the Fibonacci sequence
 * - y: the maximum value up to which you want to print
 * Output: Sequence of Fibonacci Numbers
 */
#include <iostream>

using namespace std;

// Function Prototypes
int fibonacci(int);
void print_fib(int);

int main(int argc, const char* argv[])
{
    if(argc != 3)
    {
        cout << "Error: invalid command line arguments.\n";
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    cout << "The " << x << "th number in the Fibonacci sequence is: " << fibonacci(x) << endl;

    cout << "The Fibonacci sequence up to " << y << " is:\n";
    print_fib(y);

    return 0;
}

// Function Definitions
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int fib[500];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    return fib[n];
}

void print_fib(int n)
{
    int fib[500];
    fib[0] = 0;
    fib[1] = 1;

    cout << fib[0] << " " << fib[1] << " ";
    for(int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] >= n)
            break;
        cout << fib[i] << " ";
    }
    cout << endl;
}