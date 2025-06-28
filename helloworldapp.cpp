#include <iostream>
#include <string>
using namespace std;

// this program is to swap two elemennts in a variable
int main() {

/*
    int num1, num2, tempNum=0;

    //taking input from the user
    cout << "Enter First number and Second number: ";
    cin >> num1 >> num2;

    // Swapping the values of num1 and num2 using a temporary variable
    tempNum = num1;
    num1 = num2;
    num2 = tempNum;
    cout << "num1 = " << num1 <<"\n";
    cout << "num2 = " << num2 << endl <<"\n";
*/


/*
    //string input and output
    string name;
    cout << "Enter your name: ";
    // cin >> name; // reads a single word (reads until a space is encountered)
    getline(cin, name); // reads a line of text including spaces
    cout << "Hello, " << name << "! Welcome to the C++ world!" << "\n";
*/

/*
    //switch statement
    int day;
    cout << "Enter a number between 1 and 7 to get the corresponding day of the week: ";
    cin >> day;

    switch(day) {
        case 1:
            cout << "Sunday";
            break;
        case 2:
            cout << "Monday";
            break;
        case 3:
            cout << "Tuesday";
            break;
        case 4:
            cout << "Wednesday";
            break;
        case 5:
            cout << "Thursday";
            break;
        case 6:
            cout << "Friday";
            break;
        case 7:
            cout << "Saturday";
            break;
        default: // default case is used to keep the code running when non of the cases match
            cout << "Invalid day";
    }

    cout << "\n"; // spacing the code
*/

/*
//while loop to calculate even numbers less than or equal to 10
    int num = 2;
    while (num <= 10) {
        cout << "Current number: " << num << endl;
        num += 2;
    }
*/


int x = 10, y = 15;
int z = min(x, y);
cout << z;
    return 0; // Return 0 to indicate successful execution
}