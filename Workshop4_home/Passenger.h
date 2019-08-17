/***********************************************************
 // OOP244 Workshop 4: Constructors
 // File: Passenger.h
 // Date: Jun 10, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 4 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {
	const int size = 18; // character size without null terminator
	class Passenger {
		char p_name[size + 1];
		char p_destin[size + 1];
		int p_yDepar;
		int p_mDepar;
		int p_dDepar;
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		Passenger(const char* name, const char* destination, int year, int month, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}


#endif
