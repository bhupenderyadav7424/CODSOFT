#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do
    {
        cout << "Enter your Guess : ";
        cin >> guess;

        attempts++;

        if (guess < secretNumber)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > secretNumber)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
        }

    }
    while (guess != secretNumber);

    return 0;
}
