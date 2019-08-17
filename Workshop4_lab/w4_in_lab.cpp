/***********************************************************
 // OOP244 Workshop 4: Constructors
 // File: w4_in_lab.cpp
 // Date: Jun 6, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 4 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#include <iostream>
#include "Passenger.h"
#include "Passenger.h" // this is intentional

using namespace std;
using namespace sict;

int main() {
	const int no_passengers = 8;
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger("Christopher Szwartenegger", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passengers 5 and 6 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < no_passengers; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger vanessa("Vanessa", "Paris"),
		      mike("Mike", "Tokyo"),
			  chris("Christopher Szwartzenneger", "Toronto"),
		      alice("Alice", "Paris");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	chris.display();
	travellers[0].display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
