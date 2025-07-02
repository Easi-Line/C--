#include <iostream>
#include <string>
#include <iomanip> // for std::setprecision and std::fixed
using namespace std;

int main() {
    double accountBalance = 100.00;
    double availableBalance, withdrawalAmount, serviceCharge = (withdrawalAmount - 300) * 0.04;
    const string pinCode = "1234"; //pin stored in the system.
    string userPIN; // collects and stores user pin

    //taking amount to withdraw from the user.
    cout << "Enter the amount you want to withdraw: $";
    cin >> withdrawalAmount;

    //checkinh withdrawal requirement
    if (withdrawalAmount <= 0) {
        cout << "The minimum amount you can withdraw is $1.00";
    }
    else if (withdrawalAmount > 500) {
        cout << "You withdraw a maximum of $500.00 per day. \n"
        "              Thank You.";
    }
    else if (withdrawalAmount > 300) {
        cout << "You will be charged $" << (withdrawalAmount - 300) * 0.04 << " on $" << (withdrawalAmount - 300) << "\n";
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;

        //PIN verification
        if (pinCode == userPIN) {
            int choice; //chosing to aprove or forfeit the transaction.
            cout << "Press 1 to confirm your transaction or 2 to forfiet. ";
            cin >> choice;

            //Confirm transaction after PIN verification
            switch (choice)
            {
            case 1:
                cout << setprecision(2) << fixed; // Set precision for currency output
                cout << "-------------------------ATM-------------------------------------\n"
                << "Amount Withdrawn:                           $" << withdrawalAmount << "\n"
                << "Service Charge:                             $" << (withdrawalAmount - 300) * 0.04 << "\n"
                << "Account Balance:                            $" << accountBalance - withdrawalAmount << "\n"
                << "----------------------------------------------------------------------\n"
                << "----------------------------------------------------------------------\n"
                << "                Thank You For Using Our Services \n"
                << "             Looking To Forward To Seeing You Next Time";
                break;
            case 2:
                cout << "Transaction cancelled!";
            default:
                break;
            }
        }
        else {
            cout << "Incorrect PIN please try again.";
        }
    }
    else if (withdrawalAmount > accountBalance) {
        int choice;     //holding switch value for withdrawing for credit
        cout << "Insufficient balance in your account. Press 1 to withdraw the money for a charge of $25.00 or 2 to withdraw the amount in  your account. ";
        cin >> choice;

        //confirming credit for a charge of $25.00
        switch (choice)
        {
        case 1:
            cout << "Enter your PIN to continue: ";
            cin >> userPIN;

            if (pinCode == userPIN) {
                int choice; //chosing to aprove or forfeit the transaction.
                cout << "Press 1 to confirm your transaction or 2 to forfiet. ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << setprecision(2) << fixed; // Set precision for currency output
                    cout << "-------------------------ATM-------------------------------------\n"
                    << "Amount Withdrawn:                       $" << withdrawalAmount << "\n"
                    << "Service Charge:                         $" << 25.00 << "\n"
                    << "Account Balance:                        $" << accountBalance - withdrawalAmount << "\n"
                    << "Amount On Credit:                       $" << accountBalance - withdrawalAmount << "\n"
                        << "------------------------------------------------------------------\n"
                        << "------------------------------------------------------------------\n"
                        << "             Thank You For Using Our Services \n"
                        <<"          Looking To Forward To Seeing You Next Time";
                    break;
                case 2:
                    cout << "Transaction cancelled";
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            cout << "Enter your PIN to continue: ";
            cin >> userPIN;

            if (pinCode == userPIN) {
                int choice; //chosing to aprove or forfeit the transaction.
                cout << "Press 1 to confirm your transaction or 2 to forfiet. ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        withdrawalAmount = accountBalance;
                        cout << setprecision(2) << fixed; // Set precision for currency output
                        cout << "-------------------------ATM-------------------------------------\n"
                            << "Amount Withdrawn:               $" << withdrawalAmount << "\n"
                            << "Account Balance:                $" << accountBalance - withdrawalAmount << "\n"
                            << "Amount On Credit:               $" << accountBalance - withdrawalAmount << "\n"
                            << "------------------------------------------------------------------\n"
                            << "------------------------------------------------------------------\n"
                            << "              Thank You For Using Our Services \n"
                            <<"           Looking To Forward To Seeing You Next Time";
                        break;
                    case 2:
                        cout << "Transaction cancelled";
                        break;
                    default:
                        break;
                }
            }
            break;
        default:
            break;
        }
    }
    else {
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;
        if (pinCode == userPIN) {
                int choice; //chosing to aprove or forfeit the transaction.
                cout << "Press 1 to confirm your transaction or 2 to forfiet. ";
                cin >> choice;

            switch(choice) {
                case 1:
                cout << setprecision(2) << fixed; // Set precision for currency output
                    cout << "-------------------------ATM-------------------------------------\n"
                        << "Amount Withdrawn:               $" << withdrawalAmount << "\n"
                        << "Service Charge:                 $" << "0.00" "\n"
                        << "Account Balance:                $" << accountBalance - withdrawalAmount << "\n"
                        << "Amount On Credit:               $" << accountBalance - withdrawalAmount << "\n"
                        << "--------------------------------------------------------------------\n"
                        << "--------------------------------------------------------------------\n"
                        << "             Thank You For Using Our Services \n"
                        <<"          Looking To Forward To Seeing You Next Time";
                case 2:
                    cout << "Transaction cancelled";
                        break;
                default:
                    break;
            }
        }
    }

    return 0;
}