﻿/***********************************************************
 // OOP244 Milestone 3: The Good Module
 // File: Good.cpp
 // Date: July 27, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 3
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Good.h"
#include"Error.h"

namespace aid {
	void Good::name(const char* nm) { // get name if parametor is not nullptr
		if (nm == nullptr) {
			delete[] a_gName;
			a_gName = nullptr;
		}
		else {

			a_gName = new char[strlen(nm) + 1];
			strncpy(a_gName, nm, strlen(nm));
			a_gName[strlen(nm)] = '\0';
		}
	}

	const char* Good::name() const { //Return the name value using function
		if (a_gName == nullptr || a_gName[0] == '\0') // Check the parameter condition
			return nullptr;
		else
			return a_gName;
	}

	const char* Good::sku() const { //Return the sku value using function
		if (a_SKU[0] == '\0')
			return nullptr;
		else
			return a_SKU;
	}

	const char* Good::unit()const { //Return the unit value using function
		if (a_unit[0] == '\0')
			return nullptr;
		else
			return a_unit;
	}

	bool Good::taxed() const { //Return the tax value true or false
		return a_taxState;
	}

	double Good::itemPrice() const { //Return the itemPrice value using function
		return a_priceOfSingle;
	}

	double Good::itemCost() const { //Return the itemCost value using function
		if (a_taxState)
			return a_priceOfSingle + (a_priceOfSingle * tax_rate); // add to tax
		else
			return a_priceOfSingle;
	}

	void Good::message(const char* msg) { // Give error message with using error object call
		a_err.message(msg);
	}

	bool Good::isClear() const { // Check the Error Message
		if (a_err.isClear())
			return true;
		else
			return false;
	}

	Good::Good(char type) { //Constructor default
		a_type = type;
		a_SKU[0] = '\0';
		a_unit[0] = '\0';
		a_gName = nullptr;
		a_COH = 0;
		a_need = 0;
		a_priceOfSingle = 0.0;
		a_taxState = false;
		Error a_err = Error();
	}

	Good::Good(const char* sku, const char* gName, const char* unit, int coh, bool tState, double price, int needed) { //Constructor with parameter
		if (sku != nullptr && sku[0] != '\0') {
			strncpy(a_SKU, sku, max_sku_length);
			a_SKU[max_sku_length] = '\0';
		}
		else {
			a_SKU[0] = '\0';
		}

		Good::name(gName); // check nullptr or not in Good::name function
		
		if (unit != nullptr && unit[0] != '\0') {
			strncpy(a_unit, unit, max_unit_length);
			a_unit[max_unit_length] = '\0';
		}
		else {
			a_unit[0] = '\0';
		}
		a_COH = coh;
		a_taxState = tState;
		a_priceOfSingle = price;
		a_need = needed;

	}
	Good::Good(const Good& copy) { // Copy Function by using copy operator

		*this = copy;
	}
	Good& Good::operator =(const Good& assign) { // Copy Operator
		if (this != &assign) {
			a_type = assign.a_type;
			strncpy(a_SKU, assign.a_SKU, max_sku_length);
			a_SKU[max_sku_length] = '\0';
			name(assign.a_gName);
			strncpy(a_unit, assign.a_unit, max_unit_length);
			a_unit[max_unit_length] = '\0';
			a_COH = assign.a_COH;
			a_taxState = assign.a_taxState;
			a_priceOfSingle = assign.a_priceOfSingle;
			a_need = assign.a_need;
		}
		return *this;
	}

	Good::~Good() { //Destructor
		delete[] a_gName;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const { //file stream, Print value to file, delimeter is ','
		file << a_type << ',' << a_SKU << ',' << a_gName << ',' << a_unit << ',' << a_COH << ',' << a_need << ',' << a_priceOfSingle << ',' << a_taxState;

		if (newLine)
			file << std::endl;
		return file;
	}

	std::fstream& Good::load(std::fstream& file) {
		Good tmp;
		tmp.a_gName = new char[max_name_length + 1];
		file.getline(tmp.a_SKU, max_sku_length, ','); // Using getline function
		file.getline(tmp.a_gName, max_name_length, ','); 
		file.getline(tmp.a_unit, max_unit_length, ',');
		file >> tmp.a_taxState;
		file.ignore(); // ignore ','
		file >> tmp.a_priceOfSingle;
		file.ignore();
		file >> tmp.a_COH;
		file.ignore();
		file >> tmp.a_need;
		file.ignore();

		*this = tmp;

		return file;
	}

	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (!a_err.isClear()) {
			os << a_err.message();
		}
		else if (!isEmpty() && linear == true) {
			os << std::left << std::setw(max_sku_length) << a_SKU << '|'
				<< std::setw(20) << a_gName << '|'
				<< std::right << std::setw(7) << std::fixed << std::setprecision(2) << itemCost() << '|'
				<< std::setw(4) << a_COH << '|'
				<< std::left << std::setw(10) << a_unit << '|'
				<< std::right << std::setw(4) << a_need << '|';
		}
		else if (!isEmpty() && linear == false) { 
			os << " Sku: " << a_SKU << std::endl;
			os << " Name (no spaces): " << std::setw(max_name_length) << a_gName << std::endl;
			os << " Price: " << itemPrice() << std::endl;
			if (a_taxState == true)
				os << " Price after tax: " << itemCost() << std::endl;
			else
				os << " N/A" << std::endl;
			os << " Quantity on hand: " << a_COH << std::endl;
			os << " Quantity needed: " << a_need << std::endl;

		}
		return os;
	}

	std::istream& Good::read(std::istream& is) {
		Good tmp;
		char tax;
		tmp.a_gName = new char[max_name_length + 1];
		std::cout << " Sku: ";
		is >> tmp.a_SKU;
		std::cout << " Name (no spaces): ";
		is >> tmp.a_gName;
		std::cout << " Unit: ";
		is >> tmp.a_unit;
		std::cout << " Taxed? (y/n): ";
		is >> tax;
		if (tax == 'y' || tax == 'Y') {
			tmp.a_taxState = true;
		}
		else if (tax == 'n' || tax == 'N') {
			tmp.a_taxState = false;
		}
		else {
			a_err.clear();
			a_err.message(" Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}
		if (!is.fail()) {
			std::cout << " Price: ";
			is >> tmp.a_priceOfSingle;
			if (is.fail()) {
				a_err.clear();
				a_err.message(" Invalid Price Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (!is.fail()) {
			std::cout << " Quantity on hand: ";
			is >> tmp.a_COH;
			if (is.fail()) {
				a_err.clear();
				a_err.message(" Invalid Quantity Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (!is.fail()) {
			std::cout << " Quantity needed: ";
			is >> tmp.a_need;
			if (is.fail()) {
				a_err.clear();
				a_err.message(" Invalid Quantity Needed Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (isClear())
			* this = tmp;

		return is;

		
	}

	bool Good::operator==(const char* sku) const {
		if (strcmp(a_SKU, sku) == 0)
			return true;
		else
			return false;
	}

	double Good::total_cost() const {
		return (a_priceOfSingle * a_COH) * (1 + tax_rate);
	}

	void Good::quantity(int uQuant) {
		if (uQuant > 0) {
			a_COH = uQuant;
		}

	}

	bool Good::isEmpty() const {
		if (a_gName == nullptr)
			return true;
		else
			return false;
	}

	int Good::qtyNeeded() const {
		return a_need;
	}

	int Good::quantity() const {
		return a_COH;
	}

	bool Good::operator>(const char* sku) const {
		if (strcmp(a_SKU, sku) > 0)
			return true;
		else
			return false;
	}

	bool Good::operator>(const Good& gd) const {
		if (strcmp(a_gName, gd.name()) > 0)
			return true;
		else
			return false;
	}

	int Good::operator+=(int nUnit) {
		if (nUnit > 0) {
			return a_COH += nUnit;
		}
		return a_COH;

	}

	std::ostream& operator<<(std::ostream& ostr, const Good& good) { //Helper Function
		good.write(ostr, true);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Good& good) {//Helper Function
		good.read(istr);
		return istr;
	}

	double operator+=(double& add, const Good& good) {//Helper Function
		add += good.total_cost();
		return add;
	}

}
