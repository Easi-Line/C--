#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to validate PIN
bool verifyPIN(const string& correctPIN, const string& userPIN) {
    return correctPIN == userPIN;
}

// Function to confirm transaction
bool confirmTransaction() {
    int choice;
    cout << "Press 1 to confirm your transaction or 2 to cancel: ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Invalid input. Please enter 1 to confirm or 2 to cancel: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return choice == 1;
}

// Function to print receipt
void printReceipt(double withdrawalAmount, double serviceCharge, double accountBalance, double creditAmount = 0.0) {
    cout << fixed << setprecision(2); // Ensure 2 decimal places for currency
    cout << "---------------------------------------ATM---------------------------------------\n"
         << "Amount Withdrawn:      $" << withdrawalAmount << "\n"
         << "Service Charge:        $" << serviceCharge << "\n"
         << "Account Balance:       $" << accountBalance << "\n";
    if (creditAmount != 0.0) {
        cout << "Amount On Credit:      $" << creditAmount << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n"
         << "                Thank You For Using Our Services\n"
         << "             Looking Forward To Seeing You Next Time\n";
}

int main() {
    double accountBalance = 100.00;
    double withdrawalAmount;
    const string pinCode = "1234";
    string userPIN;

    // Input withdrawal amount with validation
    cout << "Enter the amount you want to withdraw: $";
    while (!(cin >> withdrawalAmount)) {
        cout << "Invalid input. Please enter a valid amount: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Check withdrawal requirements
    if (withdrawalAmount <= 0) {
        cout << "The minimum amount you can withdraw is $1.00\n";
        return 0;
    }
    if (withdrawalAmount > 500) {
        cout << "You can withdraw a maximum of $500.00 per day.\n"
             << "Thank You.\n";
        return 0;
    }

    // Handle withdrawal exceeding balance
    if (withdrawalAmount > accountBalance) {
        int choice;
        cout << "Insufficient balance in your account.\n"
             << "Press 1 to withdraw with a $25.00 charge or 2 to withdraw available balance: ";
        while (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (choice == 2) {
            withdrawalAmount = accountBalance; // Adjust to available balance
        }

        // PIN verification
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;
        if (!verifyPIN(pinCode, userPIN)) {
            cout << "Incorrect PIN. Please try again.\n";
            return 0;
        }

        // Confirm transaction
        if (!confirmTransaction()) {
            cout << "Transaction cancelled.\n";
            return 0;
        }

        // Process transaction
        double serviceCharge = (choice == 1) ? 25.00 : 0.00;
        double creditAmount = (choice == 1) ? (withdrawalAmount - accountBalance) : 0.0;
        accountBalance -= withdrawalAmount; // Update balance
        if (accountBalance < 0) {
            accountBalance -= serviceCharge; // Apply service charge for overdraft
        }
        printReceipt(withdrawalAmount, serviceCharge, accountBalance, creditAmount);
    }
    // Handle withdrawal exceeding $300
    else if (withdrawalAmount > 300) {
        double serviceCharge = (withdrawalAmount - 300) * 0.04;
        cout << fixed << setprecision(2);
        cout << "You will be charged $" << serviceCharge << " on $" << (withdrawalAmount - 300) << "\n";

        // PIN verification
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;
        if (!verifyPIN(pinCode, userPIN)) {
            cout << "Incorrect PIN. Please try again.\n";
            return 0;
        }

        // Confirm transaction
        if (!confirmTransaction()) {
            cout << "Transaction cancelled.\n";
            return 0;
        }

        // Process transaction
        accountBalance -= (withdrawalAmount + serviceCharge); // Update balance
        printReceipt(withdrawalAmount, serviceCharge, accountBalance);
    }
    // Handle normal withdrawal
    else {
        // PIN verification
        cout << "Enter your PIN to continue: ";
        cin >> userPIN;
        if (!verifyPIN(pinCode, userPIN)) {
            cout << "Incorrect PIN. Please try again.\n";
            return 0;
        }

        // Confirm transaction
        if (!confirmTransaction()) {
            cout << "Transaction cancelled.\n";
            return 0;
        }

        // Process transaction
        accountBalance -= withdrawalAmount; // Update balance
        printReceipt(withdrawalAmount, 0.00, accountBalance);
    }

    return 0;
}