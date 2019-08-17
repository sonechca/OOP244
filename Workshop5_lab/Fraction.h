/***********************************************************
 // OOP244 Workshop 5: Operator Overload
 // File: Fraction.h
 // Date: Jun 13, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 5 Lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	
	
	class Fraction {
		
		int f_numerator;
		int f_denominator;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		
		Fraction();
		Fraction(int numer, int denom);
		bool isEmpty() const;
		void display() const;
		Fraction operator + (const Fraction& rhs) const;
	};


}



#endif // !SICT_FRACTION_H

