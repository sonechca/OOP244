/***********************************************************
 // OOP244 Workshop 5: Operator Overload
 // File: Fraction.cpp
 // Date: Jun 13, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 5 Lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/


#include <iostream>
#include "Fraction.h"

using namespace std;
namespace sict {
	Fraction::Fraction(){
		f_numerator = 0;
		f_denominator = -1;
	}
	Fraction::Fraction(int numer, int denom){
		if (numer >= 0 && denom > 0) {
			f_numerator = numer;
			f_denominator = denom;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}
	int Fraction::max() const {
		int greatNum;
		if (f_numerator > f_denominator)
			greatNum = f_numerator;
		else
			greatNum = f_denominator;
		return greatNum;
	}
	int Fraction::min() const {
		int lessNum;
		if (f_numerator < f_denominator)
			lessNum = f_numerator;
		else
			lessNum = f_denominator;
		return lessNum;
	}
// gcd returns the greatest common divisor of num and denom
//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int gcdNum = gcd();
		f_numerator /= gcdNum;
		f_denominator /= gcdNum;
	}
	void Fraction::display() const {
		if (!isEmpty() && f_denominator != 1)
			cout << f_numerator << "/" << f_denominator;
		else if (!isEmpty() && f_denominator == 1)
			cout << f_numerator;
		else
			cout << "no fraction stored";
	}
	bool Fraction::isEmpty() const {
		if (f_numerator == 0 && f_denominator == -1)
			return 1;
		else
			return 0;
	}
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result;
		if (!isEmpty() && !rhs.isEmpty()) {
			result.f_numerator = f_numerator * rhs.f_denominator + f_denominator * rhs.f_numerator;
			result.f_denominator = f_denominator * rhs.f_denominator;
			result.reduce();

		}
		return result;
	}
}
	