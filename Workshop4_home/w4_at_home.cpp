/***********************************************************
 // OOP244 Workshop 4: Constructors
 // File: w4_at_home.cpp
 // Date: Jun 10, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 4 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include <iostream>
#include "Passenger.h"

using namespace std;
using namespace sict;

int main() {
	const int no_travellers = 16;
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto", 2019, 10, 20),
		Passenger("", "Toronto", 2019, 10, 20),
		Passenger("John Smith", nullptr, 2019, 10, 20),
		Passenger("John Smith", "", 2019, 10, 20),
		Passenger("John Smith", "Toronto", 2019, 10, 20), // valid
		Passenger("John Smith", "Toronto", 2028, 10, 20),
		Passenger("John Smith", "Toronto", 2014, 10, 20),
		Passenger("John Smith", "Toronto", 2020, 12, 31), // valid
		Passenger("John Smith", "Toronto", 2019, 40, 20),
		Passenger("John Smith", "Toronto", 2019, 0, 20),
		Passenger("John Smith", "Toronto", 2019, 10, 1), // valid
		Passenger("John Smith", "Toronto", 2019, 10, 0),
		Passenger("John Smith", "Toronto", 2019, 10, 32),
		Passenger("Christopher Szwartenegger", "Toronto"), // valid
		Passenger(nullptr, nullptr, 0, 0, 0),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passengers 5, 8, 11 and 14 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (unsigned int i = 0; i < no_travellers; ++i)
	{
		cout << "Passenger " << i + 1 << ": ";
		travellers[i].display();
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger david("David", "Toronto", 2019, 10, 20);
	const int no_friends = 8;
	Passenger friends[] = {
		Passenger("Vanessa", "Toronto", 2019, 10, 20),
		Passenger("John", "Toronto", 2019, 10, 20),
		Passenger("Alice", "Toronto", 2019, 10, 20),
		Passenger("Bob", "Paris", 2019, 11, 20),
		Passenger("Jennifer", "Toronto", 2019, 10, 20),
		Passenger("Mike", "Toronto", 2019, 10, 20),
		Passenger("Christopher Szwartenegger", "Toronto", 2019, 10, 20), // valid
		Passenger("Sarah", "Toronto", 2019, 10, 20)
	};

	cout << "----------------------------------------" << endl;
	cout << "Testing Passenger::display(...)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < no_friends; ++i)
		friends[i].display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing Passenger::canTravelWith(...)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < no_friends; ++i) {
		if (david.canTravelWith(friends[i]))
			cout << david.name() << " can travel with " << friends[i].name() << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
