#include <iostream>
#include <iomanip> // For formatting output
#include <string>
using namespace std;

int main() {
    double base_salary, monthly_sales, bonus, additional_bonus, paycheck;
    int years_of_service;
    const float bonus_rate = 0.03, additional_bonus_rate = 0.06; // Constants for bonus rates
    string employerName, date, years;

    // Taking salesperson's details with input validation
    cout << "Enter your name: ";
    getline(cin, employerName);

    cout << "Enter date (dd-mm-yyyy): ";
    cin >> date;

    cout << "Enter base salary: $";
    while (!(cin >> base_salary) || base_salary < 0) {
        cout << "Invalid input. Enter a non-negative base salary: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter total sales for the month: $";
    while (!(cin >> monthly_sales) || monthly_sales < 0) {
        cout << "Invalid input. Enter a non-negative sales amount: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter number of years of service: ";
    while (!(cin >> years_of_service) || years_of_service < 0) {
        cout << "Invalid input. Enter a non-negative number of years: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Set singular/plural for "year"
    years = (years_of_service <= 1) ? "year" : "years";

    // Calculating bonus based on years of service
    if (years_of_service <= 5) {
        bonus = 10 * years_of_service;
    } else {
        bonus = 20 * years_of_service;
    }

    // Calculating the additional bonus based on monthly sales
    if (monthly_sales < 5000) {
        additional_bonus = 0;
    } else if (monthly_sales >= 5000 && monthly_sales < 10000) {
        additional_bonus = bonus_rate * monthly_sales;
    } else {
        additional_bonus = additional_bonus_rate * monthly_sales;
    }

    // Calculating the paycheck
    paycheck = base_salary + bonus + additional_bonus;

    // Display the paycheck with formatted output
    cout << fixed << setprecision(2); // Ensure two decimal places for dollar amounts
    cout << "\n";
    cout << "-------------------------------------------------------------------------------------\n"
        << "                          Payroll Check Stub \n"
        << "-------------------------------------------------------------------------------------\n"
        << "Certified Business                                 " << date << "\n"
        << "KNUST, Kumasi                                      " << employerName << "\n"
        << "-------------------------------------------------------------------------------------\n"
        << "Monthly Sales                                      $" << monthly_sales << "\n"
        << "Salary                                             $" << base_salary << "\n"
        << "Years Of Service                                   " << years_of_service << " " << years << "\n"
        << "Bonus On Years Of Service                          $" << bonus << "\n"
        << "Bonus On Monthly Sales                             $" << additional_bonus << "\n"
        << "-------------------------------------------------------------------------------------\n"
        << "Take Home                                          $" << paycheck << "\n"
        << "-------------------------------------------------------------------------------------\n";

    return 0;
}