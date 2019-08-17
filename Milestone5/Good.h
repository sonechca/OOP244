/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: Good.h
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef AID_GOOD_H
#define AID_GOOD_H
#include<iostream>
#include<fstream>
#include "Error.h"
#include "iGood.h"


namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;
	class Good : public iGood
	{
		char a_type;
		char a_SKU[max_sku_length + 1];
		char a_unit[max_unit_length + 1];
		char* a_gName;
		int a_COH;
		int a_need;
		double a_priceOfSingle;
		bool a_taxState;
		Error a_err;
	protected:
		void name(const char* nm);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char* msg);
		bool isClear() const;
	public:
		Good(char type = 'N');
		Good(const char* sku, const char* gName, const char* unit, int coh = 0, bool tState = true, double price = 0.0, int needed = 0);
		Good(const Good& copy);
		Good& operator =(const Good& assign);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* sku) const;
		double total_cost() const;
		void quantity(int uQuant);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* sku) const;
		bool operator>(const iGood& gd) const;
		int operator+=(int nUnit);

	};
	std::ostream& operator<<(std::ostream& ostr, const iGood& good);
	std::istream& operator>>(std::istream& istr, iGood& good);
	double operator+=(double& add, const iGood& good);
}

#endif /* Good_h */
