/***********************************************************
 // OOP244 Milestone 3: The Good Module
 // File: ms3_MyGood.cpp
 // Date: July 27, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 3
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ms3_MyGood.h"
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
using namespace std;

namespace aid {
	MyGood::MyGood() : Good("", "", "") {}
	MyGood::MyGood(const char* sku, const char* name, const char* unit, int qty,
		bool isTaxed, double price, int qtyNeeded) :
		Good(sku, name, unit, qty, isTaxed, price, qtyNeeded) {}
	const char* MyGood::sku() const { return Good::sku(); }
	const char* MyGood::name() const { return Good::name(); }
	const char* MyGood::unit() const { return Good::unit(); }
	bool MyGood::taxed() const { return Good::taxed(); }
	double MyGood::price() const { return Good::itemPrice(); }
	double MyGood::cost() const { return Good::itemCost(); }

	Test::Test(const char* file) : filename(file) { }
	Test::Test(const char* file, const char* theSku, const char* theName) :
		product(theSku, theName, ""), filename(file) { }
	std::fstream& Test::store(std::fstream& file, bool addNewLine) const {
		if (!product.isEmpty()) {
			file.open(filename, ios::out | ios::app);
			file << product.sku() << TAB << product.name() << TAB << product.unit() << TAB <<
				(product.taxed() ? 1 : 0) << TAB << fixed << setprecision(2) << product.price() << TAB << product.quantity() << TAB <<
				product.qtyNeeded() << endl;
			file.clear();
			file.close();
		}
		return file;
	}
	std::fstream& Test::load(std::fstream& file) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		file.open(filename, ios::in);
		file >> sku_;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> name;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> unit;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> taxed_;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> price_;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> quantity;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file >> qtyNeeded;
		if (file.fail()) {
			product = MyGood();
			file.clear();
			file.close();
			return file;
		}
		file.clear();
		file.close();
		product = MyGood(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return file;
	}
	std::ostream& Test::write(std::ostream& os, bool linear) const {
		return product.isEmpty() ? os : (os << product.sku() << ": " << product.name() << ", quantity: "
			<< product.quantity() << ", quantity needed:" << product.qtyNeeded()
			<< ", Cost: " << fixed << setprecision(2) << product.cost());
	}
	std::istream& Test::read(std::istream& is) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		cout << " Sku: ";
		is >> sku_;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxed_;
		cout << " Price: ";
		is >> price_;
		cout << " Quantity On hand: ";
		is >> quantity;
		cout << " Quantity Needed: ";
		is >> qtyNeeded;
		product = MyGood(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return is;
	}
	int Test::operator+=(int value) {
		product.quantity(product += value);
		return product.quantity();
	}
	bool Test::operator==(const char* sku) const {
		return !std::strcmp(product.sku(), sku);
	}
	std::ostream& operator<<(std::ostream& os, const Test& test) {
		return test.product.write(os, true);
	}
	double operator+=(double& d, const Test& test) {
		return d += test.product.total_cost();
	}
	std::istream& operator>>(std::istream& is, Test& test) {
		return test.product.read(is);
	}
}
