/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: Perishable.h
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef Perishable_hpp
#define Perishable_hpp
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Good.h"
namespace aid {
	class Perishable : public Good {
		Date expDate;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif /* Perishable_hpp */
