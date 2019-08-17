/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: SavingsAccount.h
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"

namespace sict {
    class SavingsAccount : public Account{
        double s_rate;
    public:
        SavingsAccount(double bal, double rate);
        void monthEnd();
        void display(std::ostream& os) const;
    };
}

#endif /* SavingsAccount_hpp */
