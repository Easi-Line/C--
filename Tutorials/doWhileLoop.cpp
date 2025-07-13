#include <iostream>
using namespace std;

int main() {
    system("cls");
    
    //Guessing Game using do-while loop.
    float const correctNumber = 6;
    float userNumber;

    do{
        cout << "Enter a number (1 - 10): ";
        cin >> userNumber;
    } while (correctNumber != userNumber);

    cout << "\nYou Guessed Right!! \n";


    //Password validation using do-while loop.
    string password;
    const string correctPassword = "hello123";
    do {
        cout << "\nEnter your password: ";
        cin >> password;
    } while (password != correctPassword);

    cout << "\nPassword Accepted!\n";


    //menu using do-while loop.
    int attempts = 0;

        int choice;
        do {
            cout << "\n************ MENU ************\n"
                << "1. Option 1\n"
                << "2. Option 2\n"
                << "3. Exit\n"
                << "Please enter your choice: ";
                cin >> choice;

                (choice == 1) ? cout << "You selected Option 1.\n" : (choice == 2) ? cout << "You selected Option 2.\n" : (choice == 3) ? cout << "Exiting the menu.\n" : cout << "Invalid choice. Please try again.\n";
        } while (choice != 3);


        int sum = 0, number = 0;

        do {
            cout << "\nEnter a Positive number: ";
            cin >> number;

            if (number > 0) {
            sum += number;
            }

        } while (!(number <= 0));
        cout << "Sum of the numbers is: " << sum << "\n";

    return 0;
}