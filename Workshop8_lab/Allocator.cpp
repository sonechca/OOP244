/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: Allocator.cpp
 // Date: July 18, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#include "SavingsAccount.h"

namespace sict {
	const double a_rate = 0.05;

	iAccount* CreateAccount(const char* type, double bal) {
		iAccount* tmp = nullptr;
		if (type[0] == 'S')
			tmp = new SavingsAccount(bal, a_rate);

		return tmp;
	}
}
