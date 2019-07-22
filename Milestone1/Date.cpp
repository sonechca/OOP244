/***********************************************************
 // OOP244 Milestone 1: The Date Module
 // File: Date.cpp
 // Date: July 11, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 1
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/



#include <iomanip>
#include "Date.h"

namespace aid {
    
    Date::Date() { //constructor(no-arguement)
        a_year = 0;
        a_month = 0;
        a_day = 0;
        errCode(NO_ERROR);
        a_comparator = 0;
    }
    
    Date::Date(int year, int month, int day) { //constructor(three-arguement)
        int validDay = mdays(year, month);
        int tmpComp = year * 372 + month * 31 + day;
        
        //error check.
        if (year < min_year || year > max_year)
            errCode(YEAR_ERROR);
        
        else if (month < 1 || month > 12)
            errCode(MON_ERROR);
        
        else if (day < 1 || day > validDay)
            errCode(DAY_ERROR);
        
        else if (tmpComp < min_date)
            errCode(PAST_ERROR);
        
        else
            errCode(NO_ERROR);
        
        //No error, Member get value from arguements.
        if (!bad()) {
            a_year = year;
            a_month = month;
            a_day = day;
            errCode(NO_ERROR);
            a_comparator = tmpComp;
        }
        // error.
        else {
            a_year = 0;
            a_month = 0;
            a_day = 0;
            a_comparator = 0;
        }
        
        
    }
    //get error code from arguement.
    void Date::errCode(int errorcode) {
        a_error = errorcode;
    }
    //return error code.
    int Date::errCode() const {
        return a_error;
    }
    //check the error if no error, return true. otherwise return false.
    bool Date::bad() const {
        return errCode() != 0;
    }
    
    int Date::mdays(int year, int mon) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    //check the equal
    bool Date::operator==(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator == rhs.a_comparator;
        }
        else {
            return false;
        }
    }
    //check the not equal
    bool Date::operator!=(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator != rhs.a_comparator;
        }
        else {
            return false;
        }
    }
    //check the less operator.
    bool Date::operator<(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator < rhs.a_comparator;
            
        }
        else {
            return false;
        }
    }
    //check the greater
    bool Date::operator>(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator > rhs.a_comparator;
        }
        else {
            return false;
        }
    }
    //check the less or equal
    bool Date::operator<=(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator <= rhs.a_comparator;
        }
        else {
            return false;
        }
    }
    //check the greater or equal
    bool Date::operator>=(const Date& rhs) const {
        if (a_comparator != 0 && rhs.a_comparator != 0) {
            return a_comparator >= rhs.a_comparator;
        }
        else {
            return false;
        }
    }
    //istream function, input from device
    std::istream& Date::read(std::istream& istr) {
        char randomchar; // check the random character when I put the date data.
        istr >> a_year >> randomchar >> a_month >> randomchar >> a_day;
        if (istr.fail()) {
            *this = Date();
            errCode(CIN_FAILED);
        }
        else if (a_year < min_year || a_year > max_year) {
            *this = Date();
            errCode(YEAR_ERROR);
        }
        else if (a_month > 12 || a_month < 1) {
            *this = Date();
            errCode(MON_ERROR);
        }
        else if (a_day > mdays(a_year, a_month) || a_day < 1) {
            *this = Date();
            errCode(DAY_ERROR);
        }
        else if (a_year * 372 + a_month * 31 + a_day < min_date) {
            *this = Date();
            errCode(PAST_ERROR);
        }
        a_comparator = a_year * 372 + a_month * 31 + a_day; // if code had no error, comparator need to get value.
        return istr;
    }
    //ostream function, output to device
    std::ostream& Date::write(std::ostream& ostr) const {
        ostr << a_year << "/" << std::setw(2) << std::setfill('0') << a_month << "/" << std::setw(2) << std::setfill('0') << a_day;
        return ostr;
    }
    //output operator, call write function and return ostream reference
    std::ostream& operator << (std::ostream& ostr, Date& d) {
        d.write(ostr);
        return ostr;
    }
    //input operator, call read function and return istream reference
    std::istream& operator >> (std::istream& istr, Date& d) {
        d.read(istr);
        return istr;
    }
}
