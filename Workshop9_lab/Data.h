/***********************************************************
 // OOP244 Workshop 9: Function Templates
 // File: Data.h
 // Date: July 25, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 9 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/


#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <cstring>

namespace sict {
	// These numbers define
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template <typename T> 
	T max(const T* data, int n) {
		T maxValue = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (maxValue < data[i])
				maxValue = data[i];
		}
		return maxValue;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
		T minValue = LARGEST_NUMBER; 
		for (int i = 0; i < n; i++) {
			if (minValue > data[i])
				minValue = data[i];
		}
		return minValue;
	}

	// sum returns the sum of n items in data
	//
	template <typename T>
	T sum(const T* data, int n) {
		T tSum = 0;
		for (int i = 0; i < n; i++) {
			tSum += data[i];
		}
		return tSum;
	}
	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n) {
		double ave = static_cast<double>(sum(data, n)) / n;
		return ave;
	}
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore(); // read ',' from file and ignore
			input >> data[i]; // get data from file
			if (input.fail()) // check the error to read
				return false;
		}
		return true;
	}
	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20); //Column width is 20 for name
		std::cout << std::right << name;
		
		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH); // Column width is 15 for data
			std::cout << data[i];
		}
		std::cout << std::endl;

	}
	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


#endif // !SICT_DATA_H

