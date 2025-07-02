#include <iostream>
#include <string>
#include <iomanip> // For formatting output
using namespace std;

int main() {
    double accountBalance = 100.00;
    double availableBalance, withdrawalAmount, serviceCharge = (withdrawalAmount - 300) * 0.04;
    const string pinCode = "1234"; //pin stored in the system.
    string userPIN; // collects and stores user pin

    

    //taking amount to withdraw from the user.
    cout << "Enter the amount you want to withdraw: $";
    while(withdrawalAmount <= 0) {
        cin >> withdrawalAmount;
        if (withdrawalAmount <= 0) {
            cout << "The minimum amount you can withdraw is $1.00. Please enter a valid amount: $";
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the invalid input
        }
    }

    while(withdrawalAmount > 500) {
        cout << "You can withdraw a maximum of $500.00 per day. Please enter a valid amount: $";
        cin >> withdrawalAmount;
        if (withdrawalAmount > 500) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the invalid input
        }
    }

    if(withdrawalAmount > 300) {
        serviceCharge = (withdrawalAmount - 300) * 0.04;
        cout << "You will be charged $" << serviceCharge << " on $" << (withdrawalAmount - 300) << "\n";
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;

        //PIN verification
        if (pinCode == userPIN) {
            int choice; //chosing to approve or forfeit the transaction.
            cout << "Press 1 to confirm your transaction or 2 to forfeit: ";
            cin >> choice;

            //Confirm transaction after PIN verification
            switch (choice) {
                case 1:
                    cout << "---------------------------------------ATM-----------------------------------------------------------------------------\n"
                        << "Amount Withdrawn:                                                       $" << withdrawalAmount << "\n"
                        << "Service Charge:                                                         $" << serviceCharge << "\n"
                        << "Account Balance:                                                        $" << accountBalance - withdrawalAmount - serviceCharge << "\n"
                        << "------------------------------------------------------------------------------------------------------------------------\n"
                        << "------------------------------------------------------------------------------------------------------------------------\n"
                        << "                        Thank You For Using Our Services \n"
                        << "                     Looking Forward To Seeing You Next Time";
                    break;
                case 2:
                    cout << "Transaction cancelled!";
                    break;
                default:
                    cout << "Invalid choice. Transaction cancelled.";
                    break;
            }
        }
    }
}
