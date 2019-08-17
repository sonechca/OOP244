/***********************************************************
 // OOP244 Workshop 8: virtual Functions and Abstract Base Classes
 // File: ChequingAccount.cpp
 // Date: July 22, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 8 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include "ChequingAccount.h"

namespace sict {
    ChequingAccount::ChequingAccount(double bal, double trans, double fee):Account::Account(bal){
        if(trans > 0)
            c_trans = trans;
        else
            c_trans = 0.0;
        if(fee > 0)
            c_monthEndFee = fee;
        else
            c_monthEndFee = 0.0;
    }
    bool ChequingAccount::credit(double amount){
        if(Account::credit(amount)){
            Account::debit(c_trans);
            return true;
        }
        else{
            return false;
            }
            

    }
    bool ChequingAccount::debit(double amount){
        if(Account::debit(amount)){
            Account::debit(c_trans);
            return true;
        }
        else{
            return false;
        }
    }
    void ChequingAccount::monthEnd(){
        Account::debit(c_monthEndFee);
    }
    void ChequingAccount::display(std::ostream & os) const{
        os << "Account type: Chequing" << std::endl;
        os.setf(os.fixed, os.floatfield);
        os.precision(2);
        os << "Balance: $" << Account::balance() << std::endl;
        os << "Per Transaction Fee: " << c_trans << std::endl;
        os << "Monthly Fee: " << c_monthEndFee <<std::endl;
    }
}
