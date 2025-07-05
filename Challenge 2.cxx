#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    float accountBalance = 200.00, freeLimit = 300, charges, credit, availableBalance;
    float totalWithdrawal = 0, withdrawal = 0;
    int option;
    const string pinCode = "1234";
    string userPIN, accountNumber;

    cout << "----------Welcome To Certified Developer's Bank----------\n";
    int attempts = 0; // counter for the number of attempts to enter the correct PIN
    while(attempts < 3) {
        cout << "Enter your four-digit PIN to continue: ";
        cin >> userPIN;

        if (userPIN == pinCode) {
            cout << "PIN accepted. Proceeding to options menu...\n";
                

            while(true) {
                cout << "\n           MAIN MENU                \n"
                    << "1. Check Account Balance. \n"
                    << "2. Transfer Money. \n"
                    << "3. Withdraw. \n"
                    << "4. Deposit.\n"
                    << "5. Exit. \n"
                    << "Select an option (1-5) to proceed. ";
                    int option;
                    cin >>  option;
                
                switch (option) {
                    case 1: // checking account balance.
                        //settling debt
                        if (accountBalance > 0 && !(credit > 0)) {
                            accountBalance += credit;
                            credit -= credit;
                        }
                    cout << fixed << setprecision(2);
                        cout << "\n----------Certified Developer's Bank----------\n";
                        cout << "Account Balance:                   $" << accountBalance << "\n";
                        cout << "Outstanding Balance:               $" << credit;
                        cout << "\n";
                        break;
                    case 2: //Money transfer menu
                        double amount;
                        cout << "\nEnter the amount you want to send: $";
                        cin >> amount;
                        cout << "\nEnter recipient account number: ";
                        cin >> accountNumber;

                        //getting a valid minimum transfer amount
                        while (amount <= 0) {
                            cout << "\nThe minimum amount you can send is $1.00 \n" "Enter an amount: $";
                            cin >> amount;
                        }
                        //getting a valid maximum transfer amount
                        while (amount > 500) {
                            cout << "\nThe maximum amount you can send is $500.00 \n" "Enter an amount: $";
                            cin >> amount;
                        }
                        if (amount > accountBalance){
                            cout << "\nYou don't sufficient balance to perform this transaction.\n"
                                << "Please top up your account and try again.";
                        }
                        else if (amount > 0) {
                        cout << "\nTransaction sucessfully done.\n";
                            //updating account balance after transfer
                        accountBalance -= amount;
                        cout << fixed << setprecision(2);
                        cout << "----------Certified Developer's Bank----------\n"
                            << "Amount Sent                        $" << amount << "\n"
                            << "Recepient Account Number           :" << accountNumber << "\n"
                            << "New Account Balance                $" << accountBalance << "\n"
                            << "\n--------THANK YOU FOR USING OUR SERVICES--------\n";
                        }
                        else {
                            cout << "\nInvalid input";
                        }
                        break;
                    case 3: //withdrawal menu
                        cout << "\nEnter the amount you want to withdraw: $";
                        cin >> amount;

                        //getting a valid minimum withdrawal amount 
                        while (amount <= 0) {
                            cout << "\nThe minimum amount you can withdraw is $1.00 \n"
                                << "Enter a valid amount: $";
                            cin >> amount;
                        }
                        //maximum withdrawal amount 
                        while (withdrawal > 500 && totalWithdrawal < 500) {
                            cout << "\nYou can withdraw a maximum of $500.00 per day. \n"
                                << "Enter an amount: $";
                            cin >> amount;
                        }
                        //when withdrawal exceed $300.00
                        if (amount > freeLimit && amount <= accountBalance) {
                            cout << "\nYou will be charged $" << (amount) * 0.04 << " on $" << amount << "\n";
                            cout << "Press 1 to confirm the transaction. Press 2 to Terminate the transaction.: ";
                            int choice;
                            cin >> choice;
                            charges = amount  * 0.04;  //calculating service charges.
                            availableBalance = accountBalance - amount - charges;
                            accountBalance = availableBalance;
                            withdrawal = amount; //store the withdrawal for further calculation
                            totalWithdrawal += withdrawal;

                            //checking maximum daily withdrawal
                            if (totalWithdrawal > 500){
                                cout << "\nYou have exceeded your daily withdrawal limit. Try again tommorow!\n"
                                << "Please try again tommorow or visit any of our nearby offices to withdraw.\n"
                                << "\n------------------THANK YOU FOR USING OUR SERVICES---------------------\n";
                            break;
                            }
                            //display receipt
                            switch(choice) {
                                case 1:
                                    cout << fixed << setprecision(2);
                                    cout << "\n----------Certified Developer's Bank----------\n"
                                        << "Amount Withdrawn                   $" << amount << "\n"
                                        << "Charges                            $" << charges << "\n"
                                        << "Available Balance                  $" << availableBalance << "\n"
                                        << "\n--------THANK YOU FOR USING OUR SERVICES--------";
                                    break;
                                case 2:
                                    cout << "\n----------Certified Developer's Bank----------\n"
                                        << "                Transaction Terminated! \n"
                                        "THANK YOU FOR USING OUR SERVICES, CHERISHED CUSTOMER.\n"
                                        "\n-----------------HAVE A NICE DAY-----------------------\n";
                                    break;
                                default:
                                    cout << "\nInvalid input. Please try again";
                                    break;
                            }
                        }
                            //when withdrawal amount is greater than account balance
                        else if (amount > accountBalance && accountBalance > 0 && totalWithdrawal < 500 ) {
                            charges = 25, availableBalance = accountBalance - amount - charges;
                            cout << "\nYou don't have enough funds to complete this transaction. \n"
                                << "Your account balance is " << accountBalance << "\n"
                                "Select from the options below to proceed. \n"
                                "1. Withdraw the funds for a fee of $25.00 \n"
                                "2. Terminate the process. ";

                                if(availableBalance < 0) {
                                    credit = availableBalance; // negative balance indicates credit.
                                    availableBalance = 0; // reset available balance to zero.
                                }

                                //withdrwawal limit
                                withdrawal = amount; //store the withdrawal for further calculation
                                totalWithdrawal += withdrawal;
                                //checking maximum daily withdrawal
                                if (totalWithdrawal > 500 ){
                                    cout << "\nYou have exceeded your daily withdrawal limit.\n" 
                                        << "Please try again tommorow or visit any of our nearby offices to withdraw.\n"
                                        << "\n------------------THANK YOU FOR USING OUR SERVICES---------------------\n";
                                break;
                                }

                                int choice;
                                cin >> choice;
                                switch(choice) {
                                    case 1:
                                        cout << fixed << setprecision(2);
                                        cout << "\n----------Certified Developer's Bank----------\n"
                                            << "Amount Withdrawn                   $" << amount << "\n"
                                            << "Charges                            $" << charges << "\n"
                                            << "Available Balance                  $" << availableBalance << "\n"
                                            << "Amount On  Credit                  $" << credit << "\n"
                                            << "\n--------THANK YOU FOR USING OUR SERVICES--------\n";
                                            accountBalance = availableBalance; // update account balance after withdrawal
                                            
                                        break;
                                    case 2:
                                        cout << "\n----------Certified Developer's Bank-----------\n"
                                            "                Transaction Terminated! \n"
                                            "\n THANK YOU FOR USING OUR SERVICES, CHERISHED CUSTOMER.\n"
                                            "\n-----------------HAVE A NICE DAY---------------------\n";
                                        break;
                                    default:
                                        cout << "\n Invalid input. Please try again";
                                    break;
                                }
                        }
                            else if (amount > accountBalance && !(accountBalance > 0) && totalWithdrawal < 500) {
                                cout << "\nYou don't qualify to withdraw money on credit at the moment.\n"
                                    "Settle your debt and try again later. \n"
                                    "\n-----------------HAVE A NICE DAY---------------------\n";
                            }
                            else if (amount <= accountBalance && amount < 300) {
                                charges = 0; // no charges on amounts less than or equal to $300.00
                                availableBalance = accountBalance - amount;

                                withdrawal = amount; //store the withdrawal for further calculation
                                totalWithdrawal += withdrawal;
                                //checking maximum daily withdrawal
                            if (totalWithdrawal > 500){
                                cout << "\nYou have exceeded your daily withdrawal limit. Try again tommorow!\n"
                                << "Please try aagain after 24 hours or visit any of our nearby offices to withdraw.\n"
                                << "\n------------------THANK YOU FOR USING OUR SERVICES---------------------\n";
                                //settling debt
                                // if (accountBalance > 0 && !(credit > 0)) {
                                //     accountBalance += credit;
                                //     cout << -credit << " has been deducted from your account  to settle your outstanding debts";
                                // }
                            break;
                            }

                                cout << fixed << setprecision(2);
                                cout << "\n----------Certified Developer's Bank-----------\n"
                                    << "Amount Withdrawn                   $" << amount << "\n"
                                    << "Charges                            $" << charges << "\n"
                                    << "Available Balance                  $" << availableBalance << "\n"
                                    << "Amount On  Credit                  $" << credit << "\n"
                                    << "\n--------THANK YOU FOR USING OUR SERVICES--------\n";
                                    accountBalance = availableBalance; // update account balance after withdrawal
                            }
                            else {
                                cout << "\nInvalid input";
                            }
                            break;
                        //calculating deposit
                    case 4:
                        cout << "\nEnter the amount you want to deposit: $";
                        cin >> amount;
                        accountBalance += amount;
                        if (accountBalance > 0 && !(credit > 0)) {
                                accountBalance += credit;
                                cout << -credit << " has been deducted from your account  to settle your outstanding debts. \n";
                            }
                            break;
                        cout << fixed << setprecision(2);
                        cout << "\n----------Certified Developer's Bank-----------\n"
                            << "Amount Withdrawn                   $" << amount << "\n"
                            << "Account Balance                    $" << accountBalance << "\n"
                            << "\n--------THANK YOU FOR USING OUR SERVICES--------\n";
                        break;
                    case 5:
                        cout << "\nGoodbye! Thank you for using Certified Developer's Bank.\n"
                        << "Have a nice day! \n";
                        return 0; // exit the program
                    default:
                        cout << "\nInvalid input. Plaese try again.";
                        break;
                }
            }
        }
        else {
            attempts++;
            cout << "\nIncorrect PIN. You have " << (3 - attempts) << " attempts left.\n";
        }
        if (attempts == 3) {
            cout << "\n----------Certified Developer's Bank-----------\n"
                << "Too many incorrect attempts.\n"
                << "Please contact customer support on \n"
                << "0257485575 or as.cyril3@gmail.com for assistance.\n"
                << "Thank you for using Certified Developer's Bank.\n"
                << "\n--------------HAVE A NICE DAY--------------------\n";;
            return 1; // exit the program after 3 failed attempts
        }
    }
    return 0;
}
