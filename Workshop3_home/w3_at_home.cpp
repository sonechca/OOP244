/***********************************************************
 // OOP244 Workshop 3: Classes and Privacy
 // File: w3_at_home.cpp
 // Date: Jun 3, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 3 Home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include <iostream>
#include "CRA_Account.h"
#include "CRA_Account.h" // intentional

using namespace std;
using namespace sict;

int main() {
	const int size = 1000;
	char familyName[size];
	char givenName[size];
	sict::CRA_Account myCRA;
	int sin;
	bool quit = false;
	if (sict::max_name_length + 1 > size) {
		cerr << "Increase size to value greater than "
			<< sict::max_name_length + 1 << endl;
		return 1;
	}

	cout << "Canada Revenue Agency Account App" << endl
		<< "=================================" << endl << endl;
	cout << "Checking constants" << endl
		<< "---------------------------------" << endl
		<< "max_name_length: " << sict::max_name_length << endl
		<< "        min_sin: " << sict::min_sin << endl
		<< "        max_sin: " << sict::max_sin << endl
		<< "---------------------------------" << endl << endl;

	do {
		cout << "Please enter your family name: ";
		cin.getline(familyName, max_name_length);
		cout << "Please enter your given name: ";
		cin.getline(givenName, max_name_length);
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
		cin.ignore();
		if (sin != 0) {
			myCRA.set(familyName, givenName, sin);
			if (myCRA.isEmpty()) {
				cout << "Invalid input! Try again." << endl;
			}
			else {
				int year;
				double balance;
				do {
					cout << "Please enter the year of your tax return (0 to quit): ";
					cin >> year;
					cin.ignore();
					if (year != 0) {
						cout << "Please enter the balance owing on your tax return (0 to quit): ";
						cin >> balance;
						cin.ignore();
						myCRA.set(year, balance);
					}
				} while (year != 0);
				quit = true;
			}
		}
		else {
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;

	return 0;
}
