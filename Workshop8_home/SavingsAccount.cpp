/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: SavingsAccount.cpp
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
    SavingsAccount::SavingsAccount(double bal, double rate):Account::Account(bal){
        if(rate > 0)
            s_rate = rate;
        else
            s_rate = 0.0;
    }
    void SavingsAccount::monthEnd(){
        credit(Account::balance()*s_rate);
    }
    void SavingsAccount::display(std::ostream &os) const{
        os << "Account type: Savings" << std::endl;
        os.setf(os.fixed, os.floatfield);
        os.precision(2);
        os << "Balance: $" << Account::balance() << std::endl;
        os << "Interest Rate (%): " << s_rate * 100 << std::endl;
    }
}
