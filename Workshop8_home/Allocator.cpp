/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: Allocator.cpp
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#include "SavingsAccount.h"
#include "ChequingAccount.h"
namespace sict {
    const double a_rate = 0.05;
    const double a_transFee = 0.50;
    const double a_monthFee = 2.00;
    
    iAccount* CreateAccount (const char* type, double bal){
        iAccount* tmp = nullptr;
        if(type[0] == 'S' || type[0] == 's')
            tmp = new SavingsAccount(bal,a_rate);
        else if(type[0] == 'C' || type[0] == 'c')
            tmp = new ChequingAccount(bal,a_transFee,a_monthFee);
        return tmp;
    }
}
