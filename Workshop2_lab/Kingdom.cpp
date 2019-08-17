/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File: Kingdom.cpp
// Date: May 23, 2019
// Author: Robert Robson
// Name: Mintae Kim
// Reason: Workshop 2 Lab
// Student#: 141915181
// E-mail: mkim221@myseneca.ca
***********************************************************/



#include <iostream>
#include "Kingdom.h"
using namespace std;


namespace sict {
	//This function display Kindom name and Population. 
	void display(const Kingdom& m) {
		cout << m.m_name << ", population " << m.m_population << endl;
	}
}