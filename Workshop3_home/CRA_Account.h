/***********************************************************
 // OOP244 Workshop 3: Classes and Privacy
 // File: CRA_Account.h
 // Date: Jun 3, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 3 Home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char c_familyName[max_name_length + 1];
		char c_givenName[max_name_length + 1];
		int c_sin;
		int c_year[max_yrs];
		double c_balance[max_yrs];
		int c_nyear;
	public:
		void set(const char* fName, const char* gName, int sNum);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
		
	};
}

#endif /* CRA_Account_h */
