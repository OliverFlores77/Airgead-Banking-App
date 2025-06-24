/*
* Oliver Flores - Put your name here
* Project Two Banking
* This program will get the following
* Month: The number of months based on user input in the “Number of Years” field
* Opening Amount: The initial investment amount as well as the opening balance each
* month, which includes interest
* Deposited Amount: The dollar amount the user plans to deposit each month. This value
* will be the same every month for the duration of the investment.
* Total: The sum of the opening and deposited amounts
* Interest: Money earned based on the “annual interest” rate input by the user.
* Program will then display the results in an organized manner
*/


#include <iostream>
#include "banking.h"
using namespace std;

// Function prototypes
int getInteger(int);
int getInteger(int, string);
double getDouble(int, string);

int main() {
	// Create an object of Banking class to use its functions
	Banking airgead;

	// Local variables to hold user input
	int numYears = 0;
	double
		initialInvestment = 0.0,
		monthlyDeposit = 0.0,
		interestRate = 0.0,
		beginningBalance = 0.0,
		interest = 0.0,
		closingBalance = 0.0;

	// Ask user for input values and store in the object using setters
	initialInvestment = getDouble(0, "What is the initial investment? ");
	airgead.setInitialInvestment(initialInvestment);

	monthlyDeposit = getDouble(0, "What is the monthly deposit? ");
	airgead.setMonthlyDeposit(monthlyDeposit);

	interestRate = getDouble(1, "What is interest rate? ");
	airgead.setInterestRate(interestRate);

	numYears = getInteger(1, "How many years should the investment grow? ");
	airgead.setNumYears(numYears);

	// Show the final balance and interest reports
	airgead.displayBalances();

	return 0;
}

// Asks user to enter an integer above a minimum
int getInteger(int lowest)
{
	int number = 0;
	bool needData = true;

	do {
		cout << "Enter a number greater than or equal to " << lowest << " ";
		cin >> number;
		needData = (number < lowest); // true if input is too low
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}
	} while (needData);

	return number;
}

// Same as above, but with a custom message
int getInteger(int lowest, string prompt)
{
	int number = 0;
	bool needData = true;

	do {
		cout << prompt << lowest << " ";
		cin >> number;
		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}
	} while (needData);

	return number;
}

// Get a decimal number above a minimum
double getDouble(int lowest, string prompt)
{
	double number = 0;
	bool needData = true;

	do {
		cout << prompt << " Must be greater than " << lowest << " ";
		cin >> number;
		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}
	} while (needData);

	return number;
}