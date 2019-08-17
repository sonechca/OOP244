/***********************************************************
 // OOP244 Milestone 4: THE IGOOD INTERFACE
 // File: ms4_MyGood.cpp
 // Date: July 27, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 4
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "ms4_MyGood.h"
using namespace std;

namespace aid {

	// constructor
	//
	MyGood::MyGood(const char* n) {
		value = 0;
		strcpy(sku, "sku");
		text_[0] = char(0);
		strcpy(name_, n);
	}

	// store record to file
	//
	fstream& MyGood::store(std::fstream& file, bool addNewLine)const {
		int i = 0;
		while (text_[i]) {
			file << text_[i];
			i++;
		}
		return file;
	}

	// load record from file
	//
	fstream& MyGood::load(std::fstream& file) {
		int i = 0;
		while (!file.fail()) {
			text_[i++] = file.get();
		}
		file.clear();
		if (i > 0) i--;
		text_[i] = 0;
		return file;
	}

	// write to standard output
	//
	ostream& MyGood::write(std::ostream& os, bool linear)const {
		for (int i = 0; text_[i]; i++) {
			if (linear && text_[i] == '\n') {
				os << " ";
			}
			else {
				os << text_[i];
			}
		}
		return os;
	}

	// read from standard input
	//
	istream& MyGood::read(std::istream& is) {
		is.getline(text_, 9999, EOF);
		return is;
	}

	// insertion operator
	//
	std::ostream& operator<<(std::ostream& ostr, const iGood& mf) {
		return mf.write(ostr, true);
	}

	// extraction operator
	//
	std::istream& operator>>(std::istream& istr, iGood& mf) {
		return mf.read(istr);
	}

	// sku equality comparison
	//
	bool MyGood::operator==(const char* str) const {
		return !strcmp(sku, str);
	}

	// total cost
	//
	double MyGood::total_cost() const {
		return 113.50;
	}

	// return MyGood name
	//
	const char* MyGood::name() const {
		return name_;
	}

	// set quantity
	//
	void MyGood::quantity(int i) {
		value = i;
	}

	// return quantity needed
	//
	int MyGood::qtyNeeded() const {
		return 45;
	}

	// return quantity
	//
	int MyGood::quantity() const {
		return value;
	}

	// increment
	//
	int MyGood::operator+=(int i) {
		value += i;
		return value;
	}

	// accumulate total costs
	//
	double operator+=(double& d, const iGood& p) {
		d += p.total_cost();
		return d;
	}

	// compare iProducts
	//
	bool MyGood::operator>(const iGood& p) const {
		return !strcmp(name_, p.name());
	}
}
