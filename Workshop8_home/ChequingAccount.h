/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: ChequingAccount.h
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {
    
    class ChequingAccount : public Account{
        double c_trans;
        double c_monthEndFee;
    public:
        ChequingAccount(double bal, double trans, double fee);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}

#endif /* ChequingAccount_hpp */
