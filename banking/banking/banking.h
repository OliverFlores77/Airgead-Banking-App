#pragma once
#ifndef banking_h
#define banking_h

#include <string>
using namespace std;

// This is the Banking class that holds all the data and functions
class Banking
{
private:
	// These are private variables. PascalCase is used to show they are private class members.
	int NumYears = 0;
	double
		InitialInvestment = 0.0, // Starting money invested
		MonthlyDeposit = 0.0,    // Amount added every month
		InterestRate = 0.0,      // Yearly interest rate (as decimal)
		BeginningBalance = 0.0,  // Balance at start of year
		Interest = 0.0,          // Interest earned in a year
		ClosingBalance = 0.0;    // End-of-year balance

	// Private helper methods (not used yet, but declared for future use)
	void CalcBalance();
	void UpdateBalances();

public:
	// Default constructor
	Banking() = default;

	// Setter methods to store values into the class
	void setInitialInvestment(double);
	void setNumYears(int);
	void setMonthlyDeposit(double);
	void setInterestRate(double);

	// Getter methods to retrieve values from the class
	int getNumYears() const;
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getInterestRate() const;

	// Method to show all balance and interest data
	void displayBalances();

	// Utility functions for formatting output
	string centerText(string, int, char = ' ');
	void printChar(int, char = ' ');
};

#endif
