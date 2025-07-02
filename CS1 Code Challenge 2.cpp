#include <iostream>
#include <string>
#include <iomanip> // for std::setprecision and std::fixed
using namespace std;

int main () {
    double accountBalance = 1000.00, withdrawalAmount, charges;
    const double freeLimit = 300, maxWithdrawal = 500; //free limit of transactions and maximum withdrawal per day.
    double availableBalance = accountBalance - withdrawalAmount - charges;
    const string pinCode = "1234"; //pin stored in the system.
    string userPIN;

    cout << "----------Welcome To Certified Developer's Bank----------\n";

    cout << "Enter your four-digit PIN to continue.: ";
    while(!(cin >> userPIN) || !(pinCode == userPIN)) {
        cout << "Incorrect PIN. Try again: ";
        cin.clear();
    }

    //Options menu
    cout << "1. Check Account Balance. \n"
        << "2. Withdraw Funds. \n"
        << "3. Pay Bill.\n"
        << "4. Transaction History. \n"
        << "Select an option (1-4) to proceed. ";
    int option;
    cin >>  option;

    switch (option) {
        case 1:
            cout << "----------Certified Developer's Bank----------\n";
            cout << "Account Balance:                   $" << accountBalance;
            break;
        case 2:
            //taking amount to withdraw from the user.
            cout << "Enter the amount you want to withdraw: $";
            cin >> withdrawalAmount;

            //getting a vlid minimum withdrawal amount 
            while (withdrawalAmount <= 0) {
                cout << "The minimum amount you can withdraw is $1.00 \n" "Enter a valid amount: $";
                cin >> withdrawalAmount;
            }
                //getting a vlid maximum withdrawal amount 
                while (withdrawalAmount > 500) {
                    cout << "You can withdraw a maximum of $500.00 per day. \n" "Enter a Valid amount: $";
                    cin >> withdrawalAmount;
            }

            //when withdrawal exceed $300.00
            if (withdrawalAmount > 300 && withdrawalAmount <= accountBalance) {
                cout << "You will be charged $" << (withdrawalAmount - freeLimit) * 0.04 << " on $" << (withdrawalAmount - freeLimit) << "\n";
                cout << "Press 1 to confirm the transaction. Press 2 to Terminate the transaction.: ";
                int choice;
                cin >> choice;
                //calculating service charges.
                charges = (withdrawalAmount - freeLimit) * 0.04;
                double availableBalance = accountBalance - withdrawalAmount - charges;

                //display receipt
                switch(choice) {
                    case 1:
                        cout << fixed << setprecision(2);
                        cout << "----------Certified Developer's Bank----------\n"
                            << "Amount Withdrawn                   $" << withdrawalAmount << "\n"
                            << "Charges                            $" << charges << "\n"
                            << "Available Balance                  $" << availableBalance << "\n"
                            << "--------THANK YOU FOR USING OUR SERVICES--------\n";
                        break;
                    case 2:
                        cout << "----------Certified Developer's Bank----------\n"
                            << "                Transaction Terminated! \n"
                            "THANK YOU FOR USING OUR SERVICES, CHERISHED CUSTOMER.\n"
                            "-----------------HAVE A NICE DAY-----------------------";
                        break;
                    default:
                        cout << "Invalid input. Please try again";
                        break;
                }
            }
            //when withdrawal amount is greater than account balance
            else if (withdrawalAmount > accountBalance) {
                withdrawalAmount = accountBalance;
                charges = 25;
                availableBalance = accountBalance - charges; //showing the user their account balance.
                cout << "You don't have enough funds to complete this transaction \n"
                    "Your available balance is " << availableBalance << "\n"
                    "Select from the options below to proceed. \n"
                    "1. Withdraw your available balance for a fee of $25.00 \n"
                    "2. Terminate the process.   ";
                int choice;
                cin >> choice;

                switch(choice) {
                    case 1:
                        availableBalance = accountBalance - withdrawalAmount;
                        cout << fixed << setprecision(2);
                        cout << "----------Certified Developer's Bank----------\n"
                            << "Amount Withdrawn                   $" << withdrawalAmount - charges << "\n"
                            << "Charges                            $" << charges << "\n"
                            << "Available Balance                  $" << availableBalance << "\n"
                            << "--------THANK YOU FOR USING OUR SERVICES--------\n";
                        break;
                    case 2:
                        cout << "----------Certified Developer's Bank-----------\n"
                            << "                Transaction Terminated! \n"
                            "THANK YOU FOR USING OUR SERVICES, CHERISHED CUSTOMER.\n"
                            "-----------------HAVE A NICE DAY---------------------";
                        break;
                    default:
                        cout << "Invalid input. Please try again";
                        break;
                }
            }
            else if(withdrawalAmount <= accountBalance) {
                charges = 0; // no charges on amounts less than or equal to $300.00
                availableBalance = accountBalance - withdrawalAmount;
                cout << fixed << setprecision(2);
                cout << "----------Certified Developer's Bank-----------\n"
                    << "Amount Withdrawn                   $" << accountBalance << "\n"
                    << "Charges                            $" << charges << "\n"
                    << "Available Balance                  $" << availableBalance << "\n"
                    << "--------THANK YOU FOR USING OUR SERVICES--------\n";
            }
            else {
                cout << "Invalid input";
            }
            break;
        case 3:
            cout << "UNDER CONSTRUCTION!! \n"
                "THIS MENU WILL BE AVAILABLE SOON";
            break;
        case 4:
            cout << "UNDER CONSTRUCTION!! \n"
                "THIS MENU WILL BE AVAILABLE SOON";
        default:
            cout << "Invalid Input. Please try again.";

    }
    
    return 0;
}