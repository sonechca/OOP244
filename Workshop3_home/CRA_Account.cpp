/***********************************************************
 // OOP244 Workshop 3: Classes and Privacy
 // File: CRA_Account.cpp
 // Date: Jun 3, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 3 Home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include<iostream>
#include<cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* fName, const char* gName, int sNum) {

		c_familyName[0] = '\0'; //make empty string
		c_givenName[0] = '\0';
		c_sin = 0;

		int cNum;
		int num = sNum;
		int lNum;
		//Validate SIN Logic.
		if (sNum > min_sin && sNum < max_sin && fName[0] != '\0' && gName[0] != '\0') {
			int sum = 0;
			lNum = num % 10; // Last digit in SIN
			num = num - lNum; // Subtract last digit

			for (int i = 0; i < 5; i++) 
			{
				int tmp = num % 100;
				int evenDigit = tmp / 10;
				int oddDigit = tmp % 10;
				sum = sum + (evenDigit * 2) / 10 + (evenDigit * 2) % 10 + oddDigit;
				num = num / 100;
			}
			cNum = ((sum / 10) + 1) * 10; //Change Next higest integer muliple of 10 to defference

			if (lNum == cNum - sum)
			{
				strncpy(c_familyName, fName, max_name_length + 1);
				strncpy(c_givenName, gName, max_name_length + 1);
				c_sin = sNum;
			}

			c_nyear = 0; //Initialize year
		}


	}
	void CRA_Account::set(int year, double balance) {
		if (!isEmpty() && c_nyear < max_yrs) {
			c_year[c_nyear] = year;
			c_balance[c_nyear] = balance;
			c_nyear++;
		}
	}
	bool CRA_Account::isEmpty() const {
		if (c_sin == 0)
			return 1;

		else
			return 0;
	}

	void CRA_Account::display() const {
		if (isEmpty())
		{
			cout << "Account object is empty!" << endl;
		}
		else
		{
			cout << "Family Name: " << c_familyName << endl;
			cout << "Given Name : " << c_givenName << endl;
			cout << "CRA Account: " << c_sin << endl;
			for (int i = 0; i < c_nyear; i++)
			{
				cout.setf(ios::fixed);
				cout.precision(2);
				if (c_balance[i] > 2.00)
					cout << "Year (" << c_year[i] << ") balance owing: " << c_balance[i] << endl;
				else if (c_balance[i] * (-1) > 2.00)
					cout << "Year (" << c_year[i] << ") refund due: " << c_balance[i] * (-1) << endl;
				else
					cout << "Year (" << c_year[i] << ") No balance owing or refund due!" << endl;
				cout.precision(6);
			}
		}
	}

	

}
