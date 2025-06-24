#include <iostream>
#include <iomanip>
#include "banking.h"
#include <string>
using namespace std;

// Set the initial investment and beginning balance
void Banking::setInitialInvestment(double initialInvestment)
{
	this->InitialInvestment = initialInvestment;
	this->BeginningBalance = initialInvestment;
}

// Set the monthly deposit amount
void Banking::setMonthlyDeposit(double monthlyDeposit)
{
	this->MonthlyDeposit = monthlyDeposit;
}

// Convert interest from percent to decimal and store
void Banking::setInterestRate(double interestRate)
{
	this->InterestRate = interestRate * 0.01; // 5 becomes 0.05
}

// Set how many years the investment will grow
void Banking::setNumYears(int numYears)
{
	this->NumYears = numYears;
}

// Get the number of years (used for output or checks)
int Banking::getNumYears() const
{
	return NumYears;
}

// Get initial investment amount
double Banking::getInitialInvestment() const
{
	return InitialInvestment;
}

// Get monthly deposit amount
double Banking::getMonthlyDeposit() const
{
	return MonthlyDeposit;
}

// Get interest rate
double Banking::getInterestRate() const
{
	return InterestRate;
}

// Centers text on screen by adding space or characters to left and right
string Banking::centerText(string text, int length, char fill)
{
	int textLength = text.length(); // How long is the message?
	string centeredText = "";

	// If text is already long, return it as-is
	if (textLength >= length) {
		return text;
	}
	else {
		// Calculate how much space is needed to center it
		int charsNeeded = (length - textLength);
		int paddingNeeded = (charsNeeded / 2);
		string leftPadding = string(paddingNeeded, fill);
		string rightPadding = leftPadding;

		centeredText = (leftPadding + text + rightPadding);

		// If uneven space needed, add one more on left
		if (charsNeeded % 2 != 0) {
			centeredText.insert(0, 1, fill);
		}
		return centeredText;
	}
}

// Prints a line of characters (like = or -)
void Banking::printChar(int times, char charToPrint)
{
	string str(times, charToPrint);
	cout << str << endl;
}

// This function prints the balance and interest for each year
void Banking::displayBalances()
{
	// First report: No monthly deposits
	printChar(50, '=');
	cout << centerText("Balance and Interest Without Additional Monthly Deposits", 50) << endl;
	printChar(50, '-');
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	printChar(50, '-');

	// Start from initial investment
	ClosingBalance = InitialInvestment;

	// Loop through each year
	for (int year = 1; year <= NumYears; ++year)
	{
		// Interest is calculated yearly
		Interest = ClosingBalance * InterestRate;
		ClosingBalance += Interest; // Add interest to balance

		// Show the result for the year
		cout << year << "\t$" << fixed << setprecision(2) << ClosingBalance << "\t\t\t$" << Interest << endl;
	}

	cout << endl;

	// Second report: With monthly deposits
	printChar(50, '=');
	cout << centerText("Balance and Interest With Additional Monthly Deposits", 50) << endl;
	printChar(50, '-');
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	printChar(50, '-');

	ClosingBalance = InitialInvestment;

	// Loop through each year again
	for (int year = 1; year <= NumYears; ++year)
	{
		Interest = 0.0; // Reset interest each year

		// Each year has 12 months
		for (int month = 1; month <= 12; ++month)
		{
			// Add monthly deposit to balance
			ClosingBalance += MonthlyDeposit;

			// Calculate interest for that month
			double monthlyInterest = ClosingBalance * (InterestRate / 12);
			Interest += monthlyInterest; // Add to year's interest
			ClosingBalance += monthlyInterest; // Add to balance
		}

		// Show the result for the year
		cout << year << "\t$" << fixed << setprecision(2) << ClosingBalance << "\t\t\t$" << Interest << endl;
	}
}
