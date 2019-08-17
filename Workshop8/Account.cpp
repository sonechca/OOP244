/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: Account.cpp
 // Date: July 18, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include "Account.h"

namespace sict {
	Account::Account(double bal) {
		if (bal > 0)
			a_balance = bal;
		else
			a_balance = 0.0;
	}
	bool Account::credit(double amount) {
		if (amount > 0) {
			a_balance += amount;
			return true;
		}
		else {
			return false;
		}
	}
	bool Account::debit(double amount) {
		if (amount > 0) {
			a_balance -= amount;
			return true;
		}
		else {
			return false;
		}
	}
	double Account::balance() const {
		return a_balance;
	}
}
