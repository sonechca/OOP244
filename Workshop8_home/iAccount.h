/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: iAccount.h
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_iACCOUNT_H
#define SICT_iACCOUNT_H
#include <iostream>

namespace sict {
    class iAccount{
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;
	virtual ~iAccount(){};

    };
    iAccount* CreateAccount(const char*, double);
}

#endif /* iAccount_h */
