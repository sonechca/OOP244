/***********************************************************
 // OOP244 Milestone 4: THE IGOOD INTERFACE
 // File: Allocator.cpp
 // Date: July 27, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 4
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include "ms4_MyGood.h"

namespace aid
{
	iGood* CreateProduct(char tag) { // get a tag dynamically
		if (tag == 'n')
			return new MyGood("Good"); //return a Good class
		else
			return new MyGood("Perishable"); //return a Perishable class
	}
}
