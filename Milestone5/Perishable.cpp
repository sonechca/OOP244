/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: Perishable.cpp
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Perishable.h"


namespace aid {
	Perishable::Perishable() :Good('P') { //Derived class, get the type 'P' 

		expDate = Date();
	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const { 
		Good::store(file, false);
		file << ",";
		expDate.write(file);
		

		if (newLine)
			file << std::endl;
			
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file);
		expDate.read(file);

		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Good::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear) {
				expDate.write(os);
			}
			else {
				os << "\n Expiry date: ";
				expDate.write(os);
			}
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is) {
		Good::read(is);
		if (isClear()) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			expDate.read(is);
			if (expDate.errCode() == 1) {
				message("Invalid Date Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else if (expDate.errCode() == 2) {
				message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else if (expDate.errCode() == 3) {
				message("Invalid Month in Date Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else if (expDate.errCode() == 4) {
				message("Invalid Year in Date Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else if (expDate.errCode() == 5) {
				message("Invalid Expiry in Date Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
		}
		return is;
	}
	const Date& Perishable::expiry() const { //return expired date
		return expDate;
	}
	iGood* CreateProduct(char tag) { //get tag 'N' , 'P'
		
		if (tag == 'n' || tag == 'N') {
			return new Good();
		}
		else if (tag == 'p' || tag == 'P') {
			return new Perishable();
		}
		else {
			return nullptr;
		}
	}
}
