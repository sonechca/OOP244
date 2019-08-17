/***********************************************************
 // OOP244 Workshop 5: Class with a Resource
 // File: Contact.cpp
 // Date: July 5, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 6 Lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() { //constructor without arguement
		c_nameOfCon[0] = '\0';
		c_phoneNum = nullptr;
		c_sizeOfPhone = 0;
	}
	Contact::Contact(const char* name, const long long* phone, int size) { // constructor with 3 arguements
		if (name != nullptr && name[0] != '\0') {
			strncpy(c_nameOfCon, name, MAX_CHAR);
			c_nameOfCon[MAX_CHAR] = '\0';
		}
		else
		{
			c_nameOfCon[0] = '\0';
		}
		if (phone != nullptr && size > 0) {
			c_sizeOfPhone = 0;
			long long* tmp = new long long[size];
			for (int i = 0; i < size; i++) {
				long long digitElev = 10000000000;
				int digitEight = 10000000;
				int cNum = phone[i] / digitElev; //country number
				int areaDigit = (phone[i] % digitElev) / digitEight; //area number
				int digitOfNum = ((phone[i] % digitElev) % digitEight);

				bool check = (cNum > 0 && cNum < 100) && (areaDigit > 99 && areaDigit < 1000) && (digitOfNum > 999999 && digitOfNum < 10000000);
				if (check) {
					tmp[c_sizeOfPhone] = phone[i];
					c_sizeOfPhone++;
				}
			}
			c_phoneNum = new long long[c_sizeOfPhone];
			for (int i = 0; i < c_sizeOfPhone; i++)
			{
				c_phoneNum[i] = tmp[i];
			}
			delete[] tmp;
			
		}
		else {
			c_phoneNum = nullptr;
			c_sizeOfPhone = 0;
		}
			
	}
	Contact::~Contact() { //destructor
		delete[] c_phoneNum;

	}
	bool Contact::isEmpty() const {
		if (c_nameOfCon[0] == '\0' && c_phoneNum == nullptr && c_sizeOfPhone == 0) //check the empty state of arguements
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
				long long c_num = c_phoneNum[i];
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
}
