#include <iostream>
#include <string>
#include <iomanip> // for std::setprecision and std::fixed
using namespace std;

int main () {
    double accountBalance =400.00, withdrawalAmount, charges;
    const double freeLimit = 300, maxWithdrawal = 500; //free limit of transactions and maximum withdrawal per day.
    double availableBalance = accountBalance - withdrawalAmount - charges, credit;
    const string pinCode = "1234"; //pin stored in the system.
    string userPIN;

    cout << "----------Welcome To Certified Developer's Bank----------\n";

    //while stament to check if the user has entered the correct PIN.
    int attempts = 0; // counter for the number of attempts to enter the correct PIN
    while(attempts < 3) {
        cout << "Enter your four-digit PIN to continue: ";
        cin >> userPIN;

        if (userPIN == pinCode) {
            cout << "PIN accepted. Proceeding to options menu...\n";

            //Options menu
    cout << "1. Check Account Balance. \n"
        << "2. Deposit \n"
        << "3. Withdraw Funds. \n"
        << "4. Pay Bill.\n"
        << "5. Transaction History. \n"
        << "Select an option (1-5) to proceed. ";
    int option;
    cin >>  option;

    switch (option) {
        case 1:
            cout << "----------Certified Developer's Bank----------\n";
            cout << "Account Balance:                   $" << accountBalance;
            break;
        case 2:
            double depositAmount;
            cout << "Enter the amount you want to deposit: $";
            cin >> depositAmount;

            //getting a valid minimum deposit amount
            while (depositAmount <= 0) {
                cout << "The minimum amount you can deposit is $1.00 \n" "Enter a valid amount: $";
                cin >> depositAmount;
            }

            //updating account balance after deposit
            accountBalance += depositAmount;
            cout << fixed << setprecision(2);
            cout << "----------Certified Developer's Bank----------\n"
                << "Amount Deposited                   $" << depositAmount << "\n"
                << "New Account Balance                $" << accountBalance << "\n"
                << "--------THANK YOU FOR USING OUR SERVICES--------\n";
            break;
        case 3:
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
                    cout << "You can withdraw a maximum of $500.00 per day. \n" "Enter an amount: $";
                    cin >> withdrawalAmount;
            }

            //when withdrawal exceed $300.00
            if (withdrawalAmount > freeLimit && withdrawalAmount <= accountBalance) {
                cout << "You will be charged $" << (withdrawalAmount) * 0.04 << " on $" << withdrawalAmount << "\n";
                cout << "Press 1 to confirm the transaction. Press 2 to Terminate the transaction.: ";
                int choice;
                cin >> choice;
                //calculating service charges.
                charges = withdrawalAmount  * 0.04;
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
                charges = 25;
                cout << "You don't have enough funds to complete this transaction. \n"
                    << "Your account balance is " << accountBalance << "\n"
                    // "Your available balance is " << accountBalance - charges << "\n"
                    "Select from the options below to proceed. \n"
                    "1. Withdraw the funds for a fee of $25.00 \n"
                    "2. Terminate the process.   ";

                    availableBalance = accountBalance - withdrawalAmount - charges;
                    if(availableBalance < 0) {
                        credit = availableBalance; // negative balance indicates credit.
                        availableBalance = 0; // reset available balance to zero.
                    }

                int choice;
                cin >> choice;

                switch(choice) {
                    case 1:
                        cout << fixed << setprecision(2);
                        cout << "----------Certified Developer's Bank----------\n"
                            << "Amount Withdrawn                   $" << withdrawalAmount << "\n"
                            << "Charges                            $" << charges << "\n"
                            << "Available Balance                  $" << availableBalance << "\n"
                            << "Amount On  Credit                  $" << credit << "\n"
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
                    << "Amount On  Credit                  $" << credit << "\n"
                    << "--------THANK YOU FOR USING OUR SERVICES--------\n";
            }
            else {
                cout << "Invalid input";
            }
            break;
        case 4:
            cout << "UNDER CONSTRUCTION!! \n"
                "THIS MENU WILL BE AVAILABLE SOON";
            break;
        case 5:
            cout << "UNDER CONSTRUCTION!! \n"
                "THIS MENU WILL BE AVAILABLE SOON";
        default:
            cout << "Invalid Input. Please try again.";

    }

            break; // exit the loop if the PIN is correct
        } else {
            attempts++;
            cout << "Incorrect PIN. You have " << (3 - attempts) << " attempts left.\n";
        }
        if (attempts == 3) {
            cout << "----------Certified Developer's Bank-----------\n"
                << "Too many incorrect attempts. Exiting the program.\n"
                << "Please contact customer support for assistance.\n"
                << "0257485575 or as.cyril3@gmail.com\n"
                << "Thank you for using Certified Developer's Bank.\n"
                << "--------------HAVE A NICE DAY--------------------";;
            return 1; // exit the program after 3 failed attempts
        }
    }
    
    return 0;
}