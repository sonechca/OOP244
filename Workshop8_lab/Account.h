/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: Account.h
 // Date: July 18, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {
	class Account : public iAccount {
		double a_balance;
	protected:
		double balance() const;
	public:
		Account(double bal = 0.0);
		bool credit(double);
		bool debit(double);
	};
}
#endif /* Account_hpp */
