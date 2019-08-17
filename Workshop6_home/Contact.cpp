/***********************************************************
 // OOP244 Workshop 6: Class with a Resource
 // File: Contact.cpp
 // Date: July 7, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 6 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;


namespace sict {
	// defaut constructor with safety empty state
	Contact::Contact() {
		c_nameOfCon[0] = '\0';
		c_phoneNum = nullptr;
		c_sizeOfPhone = 0;
	}
	// constructor with 3 arguements
	Contact::Contact(const char* name, const long long* phone, int size) {
		if (name != nullptr && name[0] != '\0') {
			Contact tmp;
			c_sizeOfPhone = 0;
			tmp.c_phoneNum = new long long[size];

			strncpy(c_nameOfCon, name, MAX_CHAR);
			c_nameOfCon[MAX_CHAR] = '\0';

			for (int i = 0; i < size && validNum(phone[i]); i++) {
				tmp.c_phoneNum[i] = phone[i];
				c_sizeOfPhone++;	
			}

			c_phoneNum = new long long[c_sizeOfPhone];
			for (int i = 0; i < c_sizeOfPhone; i++) {
				c_phoneNum[i] = tmp.c_phoneNum[i];
			}
			delete[] tmp.c_phoneNum;
			tmp.c_phoneNum = nullptr;
		}
		else {
			*this = Contact();
		}
	}
	//copy constructor
	Contact::Contact(const Contact& copy) {
		* this = copy; //copy operator work

	}
	//destructor
	Contact::~Contact() {
		delete[] c_phoneNum;

	}
	//check empty state
	bool Contact::isEmpty() const {
		if (c_nameOfCon[0] == '\0' && c_phoneNum == nullptr && c_sizeOfPhone == 0)
			return true;
		else
			return false;
	}
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << c_nameOfCon << endl;
			for (int i = 0; i < c_sizeOfPhone; i++) {
				long long c_num = c_phoneNum[i]; // make code readable
				long long digitElev = 10000000000;
				int digitEight = 10000000;
				int digitFive = 10000;

				cout << "(+" << c_num / digitElev << ") ";
				cout << (c_num % digitElev) / digitEight << " ";
				cout << ((c_num % digitElev) % digitEight) / digitFive << "-";
				cout.fill('0');
				cout.width(4);
				cout << ((c_num % digitElev) % digitEight) % digitFive << endl;

			}
		}
	}
	//copy oerator
	Contact& Contact::operator=(const Contact& copy) {
		if (strcmp(c_nameOfCon, copy.c_nameOfCon) == 0 && c_phoneNum == copy.c_phoneNum && c_sizeOfPhone == copy.c_sizeOfPhone) {
			return *this;
		}
		else if (copy.isEmpty()) {
			c_nameOfCon[0] = '\0';
			c_phoneNum = nullptr;
			c_sizeOfPhone = 0;
		}
		else {
			strncpy(c_nameOfCon, copy.c_nameOfCon, MAX_CHAR);
			c_nameOfCon[MAX_CHAR] = '\0';
			c_phoneNum = nullptr;

			if (copy.c_phoneNum != nullptr) {
				c_sizeOfPhone = copy.c_sizeOfPhone;
				c_phoneNum = new long long[c_sizeOfPhone];
				for (int i = 0; i < c_sizeOfPhone; i++) {
					c_phoneNum[i] = copy.c_phoneNum[i];
				}
			}

		}

		return *this;
	}
	Contact& Contact::operator+=(long long newNum) {
		if (validNum(newNum) && !isEmpty()) {
			long long* temp = nullptr;
			temp = new long long[c_sizeOfPhone + 1];

			for (int i = 0; i < c_sizeOfPhone; i++) {
				temp[i] = c_phoneNum[i];
			}
			delete[] c_phoneNum;
			c_phoneNum = nullptr;

			c_phoneNum = temp;
			c_phoneNum[c_sizeOfPhone] = newNum;
			c_sizeOfPhone++;

			temp = nullptr;
		}
		return *this;
	}
	bool validNum(long long newNum) { // helper function for check vaild number
		long long digitElev = 10000000000;
		int digitEight = 10000000;
		int cNum = newNum / digitElev; //country number
		int areaDigit = (newNum % digitElev) / digitEight; //area number
		int digitOfNum = ((newNum % digitElev) % digitEight); //last 7 digits
		if ((cNum > 0 && cNum < 100) && (areaDigit > 99 && areaDigit < 1000) && (digitOfNum > 999999 && digitOfNum < 10000000)) 
			return true;
		else
			return false;
	}
}
