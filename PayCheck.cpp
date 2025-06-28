#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    double base_salary, monthly_sales, bonus, additional_bonus, paycheck;   // consolidated variables (declaring multiple variables at once to improve readability)
    int years_of_service;
    const float bonus_rate = 0.03, additional_bonus_rate = 0.06; // constants for bonus rates
    string employerName, date,  years;

    //taking salesperson's details
    cout << "Enter your name: ";
    getline (cin, employerName);
    cout << "Enter date: dd-mm-yyyy ";
    cin >> date;
    cout <<"Enter base salary: $";
    cin >> base_salary;
    cout <<"Enter total sales for the month: $";
    cin >> monthly_sales;
    cout <<"Enter number of years of service: ";
    cin >>years_of_service;

    if (years_of_service <= 1) {
        years = "year";
    }
    else {
        years = "years";
    }

    //calculating bonus
    if (years_of_service <=5) {
        bonus = 10 * years_of_service; }
    else
    {
        bonus = 20 * years_of_service;
    }

    //Calculating the additional bonus
    if (monthly_sales < 5000)
    {
        additional_bonus = 0;
    }
    else if (monthly_sales >= 5000)
    {
        additional_bonus =  bonus_rate * monthly_sales;
    }
    else
    {
        additional_bonus = additional_bonus_rate * monthly_sales;
    }

    // Calculating the paycheck
    paycheck = base_salary + bonus + additional_bonus; 
    cout << "\n";

    //Display the paycheck
    cout << "-------------------------------------------------------------------------------------\n"
        << "                          Payroll Check Stub \n"
        << "-------------------------------------------------------------------------------------\n"
        << "Certified Business                                  " << date << "\n"
        << "KNUST, Kumasi                                       " << employerName <<"\n"
        << "-------------------------------------------------------------------------------------\n"
        << "Monthly Sales                                       $" << monthly_sales <<"\n"
        << "Salary                                              $" << base_salary   <<"\n"
        << "Years Of Service                                    " << years_of_service << " " << years <<"\n"
        << "Bonus On Years Of Service                           $" << bonus << "\n"
        << "Bonus On Monthly Sales                              $" << additional_bonus << "\n"
        << "-------------------------------------------------------------------------------------\n"
        << "Take Home                                           $" << paycheck << "\n"
        << "-------------------------------------------------------------------------------------\n";

    return 0;
}
