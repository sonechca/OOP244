/***********************************************************
 // OOP244 Workshop 4: Constructors
 // File: Passenger.cpp
 // Date: Jun 10, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 4 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/


#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {
	Passenger::Passenger() { // constructor
		p_name[0] = '\0';
		p_destin[0] = '\0';
		p_yDepar = 0;
		p_mDepar = 0;
		p_dDepar = 0;
	}

	// constructor with two parameters
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0') {
			*this = Passenger(); // minimize code duplication

		}
		else {
			strncpy(p_name, name, size);
			p_name[size] = '\0';
			strncpy(p_destin, destination, size);
			p_destin[size] = '\0';
			p_yDepar = 2019;
			p_mDepar = 10;
			p_dDepar = 1;
		}
	}

	// constructor with five parameters
	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
		if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0' || (year < 2019 || year > 2021) || (month < 1 || month > 12) || (day < 1 || day > 31)) {
			*this = Passenger();

		}
		else {
			strncpy(p_name, name, size);
			p_name[size] = '\0';
			strncpy(p_destin, destination, size);
			p_destin[size] = '\0';
			p_yDepar = year;
			p_mDepar = month;
			p_dDepar = day;
		}
	}

	bool Passenger::isEmpty() const {
		if (p_name[0] == '\0' && p_destin[0] == '\0')
			return 1;
		else
			return 0;
	}

	void Passenger::display() const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << p_name << " - " << p_destin << " on " << p_yDepar << "/" << p_mDepar << "/";
			cout.fill('0');
			cout.width(2);
			cout << p_dDepar << endl;
		}
	}

	const char* Passenger::name() const {
		if (isEmpty())
			return "";
		else
			return p_name;
	}

	//check same destination and date
	bool Passenger::canTravelWith(const Passenger & friends) const {
		if (strcmp(this->p_destin, friends.p_destin) == 0 && this->p_yDepar == friends.p_yDepar && this->p_mDepar == friends.p_mDepar && this->p_dDepar == friends.p_dDepar)
			return 1;
		else
			return 0;
	}

}
