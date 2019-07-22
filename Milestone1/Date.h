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

#ifndef AID_DATE_H
#define AID_DATE_H
#include <iostream>
namespace aid {
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int DAY_ERROR = 2;
    const int MON_ERROR = 3;
    const int YEAR_ERROR = 4;
    const int PAST_ERROR = 5;
    class Date{
        int a_year;
        int a_month;
        int a_day;
        int a_comparator;
        int a_error;
        void errCode(int errorcode);
        int mdays(int year, int month) const;
        
    public:
        Date();
        Date(int year, int month, int day);
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        int errCode() const;
        bool bad() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };
    std::ostream& operator << (std::ostream& ostr, Date& d);
    std::istream& operator >> (std::istream& istr, Date& d);
}

#endif /* Date_h */
