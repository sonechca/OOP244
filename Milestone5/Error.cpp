/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: Error.cpp
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Error.h"

namespace aid { //constructor
	Error::Error(const char* errorMessage) {

		if (errorMessage == nullptr || strlen(errorMessage) == 0) {
			pMessage = nullptr;
		}
		else {
			pMessage = new char[strlen(errorMessage) + 1];
			strcpy(pMessage, errorMessage);
		}

	}

	Error:: ~Error() { //destructor
		delete[] pMessage;
		pMessage = nullptr;
	}
	void Error::clear() {
		pMessage = nullptr;
	}
	bool Error::isClear() const {
		if (pMessage == nullptr)
			return 1;
		else
			return 0;
	}
	//Get a error message from parameter
	void Error::message(const char* str) {
		delete[] pMessage;
		pMessage = nullptr;

		if (strlen(str) != 0) {
			pMessage = new char[strlen(str) + 1];
			strncpy(pMessage, str, strlen(str));
			pMessage[strlen(str)] = '\0';
		}
		else if (strlen(str) == 0) {
			pMessage = nullptr;
		}
	}
	//Return Error Message
	const char* Error::message() const {
		if (!isClear())
			return pMessage;
		else
			return nullptr;
	}
	//Output operator
	std::ostream& operator <<(std::ostream& ostr, Error& e) {
		if (!e.isClear()) {
			ostr << e.message();

		}
		return ostr;
	}
}
