/***********************************************************
 // OOP244 Workshop 3: Classes and Privacy
 // File: CRA_Account.cpp
 // Date: May 30, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 3 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;

namespace sict {
	void CRA_Account::set(const char* fName, const char* gName, int sNum){
		if (sNum > min_sin && sNum < max_sin) {
			strncpy(c_familyName, fName, max_name_length+1);
			strncpy(c_givenName, gName, max_name_length + 1);
			c_sin = sNum;
		}
		else
		{
			c_familyName[0] = '\0';
			c_givenName[0] = '\0';
			c_sin = 0;
		}
	}
	bool CRA_Account::isEmpty() const {
		if (c_sin == 0)
			return 1;
		else
			return 0;
	}
	void CRA_Account::display() const {
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << c_familyName << endl;
			cout << "Given Name : " << c_givenName << endl;
			cout << "CRA Account: " << c_sin << endl;
		}
	}
}


