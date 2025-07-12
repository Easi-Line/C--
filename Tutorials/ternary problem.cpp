#include <iostream>
using namespace std;
/*1. Prompts the user to enter a 4-digit pin
2. check:
    if the input is empty shoe "Enter your PIN."
    if the input is not 4 characters show "pin must be 4-digits
    if it contains any non-digit characters show 'pin must contain only digits
    if it matches predefined correct pin show 'access granted"
    if the pin is wrong show 'incorrect pin'*/
int main() {
    const string correctPin = "1234";
    string pin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter your 4-digit PIN: ";
        getline(cin, pin);

        bool isAllDigits = true;
        for (char c : pin) {
            if (!isdigit(c)) {
                isAllDigits = false;
                break;
            }
        }

        (pin.empty()) ? cout << "Enter your PIN. \n"
                        : (pin.length() != 4) ? cout <<"PIN must be 4-digits.\n"
                        : (isAllDigits == false) ? cout << "PIN must contain only digits.\n"
                        : (pin == correctPin) ? cout << "Access granted.\n"
                        : cout << "Incorrect PIN \n";
        if (pin == correctPin) break;
    attempts++;
    attempts < 3 ? cout << "You have " << (3 - attempts) << " attempts left.\n" : cout << "Too many attempts. Access denied.\n";
    }


    return 0;
}