/***********************************************************
 // OOP244 Milestone 4: THE IGOOD INTERFACE
 // File: ms4_MyGood.h
 // Date: July 27, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 4
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef AID_MYPRODUCT_H__
#define AID_MYPRODUCT_H__
#include "iGood.h"
#include "iGood.h"
#include "iGood.h" // Good.h is included three times on purpose.

namespace aid {
	class MyGood : public iGood { // derived function
		char text_[10000];
		char sku[4];
		char name_[20];
		int value;
	public:
		MyGood(const char* name);
		std::fstream& store(std::fstream& file, bool addNewLine)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		const char* name() const;
		void quantity(int);
		int qtyNeeded() const;
		int quantity() const;
		int operator+=(int);
		bool operator>(const iGood&) const;
	};
}
#endif
