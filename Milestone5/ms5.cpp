/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: ms5.cpp
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#include "iGood.h"
#include "iGood.h" // intentional

void testPerishable();
void testGood();
void promptUser(const char* sku, const char* name, const char* unit = "", char Tx = '\0',
	const char* price = "", const char* qty = "", const char* qtyNd = "",
	const char* date = "");
void dumpFile(const char* fname);
void pause_();

using namespace std;
using namespace aid;

int main()
{
	cout << "Test creator:\n";
	iGood* prod;

	prod = CreateProduct('n');
	cout << *prod << endl;
	delete prod;

	prod = CreateProduct('p');
	cout << *prod << endl;
	delete prod;

	cout << "No product: " << (CreateProduct('a') == nullptr ? "true" : "false") << endl;

	testGood();
	cout << endl;
	testPerishable();
}

// testGood tests the processing of Good objects
//
void testGood() {
	fstream goodsFile("good.txt", ios::out);
	iGood* good = CreateProduct('n');
	bool ok = true;
	cout << "--Good test:" << endl;
	cout << "----Taxed validation test:" << endl;
	promptUser("abc", "abc", "abc", 'a');
	cin >> *good;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(2000, '\n');
		cout << "\nPassed!" << endl
			<< " Message should be:  Only (Y)es or (N)o are acceptable" << endl
			<< " Your Error message: " << *good << endl;
	}
	else {
		ok = false;
		cout << " Taxed validation failed" << endl;
	}
	pause_();
	if (ok) {
		cout << "----Price validation test:" << endl;
		promptUser("abc", "abc", "abc", 'y', "abc");
		cin >> *good;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "\nPassed!" << endl
				<< " Message should be:  Invalid Price Entry" << endl
				<< " Your Error message: " << *good << endl;
		}
		else {
			ok = false;
			cout << " Price validation failed" << endl;
		}
		pause_();
	}
	if (ok) {
		cout << "----Quantity validation test:" << endl;
		promptUser("abc", "abc", "abc", 'y', "10", "abc");
		cin >> *good;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "\nPassed!" << endl
				<< " Message should be:  Invalid Quantity Entry" << endl
				<< " Your Error message: " << *good << endl;
		}
		else {
			ok = false;
			cout << " Quantity validaton failed" << endl;
		}
	}
	pause_();
	if (ok) {
		cout << "----Quantity Needed validation test:" << endl;
		promptUser("abc", "abc", "abc", 'y', "10", "10", "abc");
		cin >> *good;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "\nPassed!" << endl
				<< " Message should be:  Invalid Quantity Needed Entry" << endl
				<< " Your Error message: " << *good << endl;
		}
		else {
			ok = false;
			cout << " Quantity Needed validaton failed" << endl;
		}
	}
	pause_();
	if (ok) {
		cout << "----Display test, the output of the Program and yours must match:" << endl;
		promptUser("1234", "box", "kg", 'y', "123.45", "1", "5");
		cin >> *good;
		//cin.ignore(1000, '\n');
		cout << "\n-Compare the output of the Program and your output:" << endl;
		cout << "--Linear------------" << endl;
		cout << " Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
		cout << "   Yours: " << *good << endl;
		cout << "--Form Display------" << endl;
		cout << "--Program: " << endl;
		cout << " Sku: 1234" << endl;
		cout << " Name (no spaces): box" << endl;
		cout << " Price : 123.45" << endl;
		cout << " Price after tax : 139.50" << endl;
		cout << " Quantity on hand : 1 kg" << endl;
		cout << " Quantity needed : 5" << endl;
		cout << "--Yours: " << endl;
		good->write(cout, false) << endl;
	}
	pause_();
	if (ok) {
		cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
		iGood* tempGood = CreateProduct('N');
		good->store(goodsFile);
		good->store(goodsFile);
		goodsFile.close();
		cout << "--Store Good, program: " << endl
			<< "N,1234,box,kg,1,123.45,1,5" << endl
			<< "N,1234,box,kg,1,123.45,1,5" << endl;
		cout << "--Store Good, yours: " << endl;
		dumpFile("good.txt");
		cout << "--Load Good: " << endl;
		goodsFile.open("good.txt", ios::in);
		goodsFile.ignore(2);
		tempGood->load(goodsFile);
		cout << " Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
		cout << "   Yours: " << *tempGood << endl;
		goodsFile.clear();
		goodsFile.close();
		delete tempGood;
	}
	delete good;
}

// testPerishable tests the processing of Perishable objects
//
void testPerishable() {
	fstream goodsShortFile("goodsShortFile.txt", ios::out);
	iGood* perishable = CreateProduct('p');
	bool ok = true;
	cout << "--Perishable Good test:" << endl;
	if (ok) {
		cout << "----Expiry date Validation test:" << endl;
		promptUser("abc", "abc", "abc", 'n', "10", "10", "10", "10/1/1");
		cin >> *perishable;
		if (cin.fail()) {
			cin.clear();
			cout << "\nPassed!" << endl
				<< " Message should be:  Invalid Year in Date Entry" << endl
				<< " Your Error message: " << *perishable << endl;
		}
		else {
			ok = false;
			cout << " Expiry date validaton failed" << endl;
		}
		cin.ignore(2000, '\n');
	}
	pause_();
	if (ok) {
		cout << "----Display test, the output of the Program and yours must match:" << endl;
		promptUser("1234", "water", "liter", 'n', "1.5", "1", "5", "2018/06/30");
		cin >> *perishable;
		if (cin.fail()) {
			cin.clear();
			cout << "\nPassed!" << endl
				<< " Message should be:  Invalid Expiry in Date Entry" << endl
				<< " Your Error message: " << *perishable << endl;
		}
		else {
			ok = false;
			cout << " Expiry date validaton failed" << endl;
		}
		cin.ignore(2000, '\n');
	}
	pause_();
	if (ok) {
		cout << "----Display test, the output of the Program and yours must match:" << endl;
		promptUser("1234", "water", "liter", 'n', "1.5", "1", "5", "2018/12/30");
		cin >> *perishable;
		cin.ignore(2000, '\n');
		cout << "\n-Compare the output of the Program and your output:" << endl;
		cout << "--Linear------------" << endl;
		cout << " Program: 1234   |water               |   1.50|   1|liter     |   5|2018/12/30" << endl;
		cout << "   Yours: " << *perishable << endl;
		cout << "--Form Display------" << endl;
		cout << "--Program: " << endl;
		cout << " Sku: 1234" << endl;
		cout << " Name (no spaces): water" << endl;
		cout << " Price : 1.50" << endl;
		cout << " Price after tax : N/A" << endl;
		cout << " Quantity on hand : 1 liter" << endl;
		cout << " Quantity needed : 5" << endl;
		cout << " Expiry date : 2018/12/30" << endl;
		cout << "--Yours: " << endl;
		perishable->write(cout, false) << endl;
		cout << endl;
	}
	pause_();
	if (ok) {
		cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
		iGood* tempPerishable = CreateProduct('P');
		perishable->store(goodsShortFile);
		perishable->store(goodsShortFile);
		goodsShortFile.close();
		cout << "--Store Perishable, program: " << endl
			<< "P,1234,water,liter,0,1.5,1,5,2018/12/30" << endl
			<< "P,1234,water,liter,0,1.5,1,5,2018/12/30" << endl;
		cout << "--Store Perishable, yours: " << endl;
		dumpFile("goodsShortFile.txt");
		cout << "--Load Perishable: " << endl;
		goodsShortFile.open("goodsShortFile.txt", ios::in);
		goodsShortFile.ignore(2);
		tempPerishable->load(goodsShortFile);
		cout << " Program: 1234   |water               |   1.50|   1|liter     |   5|2018/12/30" << endl;
		cout << "   Yours: " << *tempPerishable << endl;
		goodsShortFile.clear();
		goodsShortFile.close();
		delete tempPerishable;
	}
	delete perishable;
}

// promptUser prompts user with data to be entered
//
void promptUser(const char* sku, const char* name, const char* unit, char Tx,
	const char* price, const char* qty, const char* qtyNd,
	const char* date) {
	cout
		<< "Enter the following: " << endl
		<< " Sku: " << sku << endl
		<< " Name (no spaces): " << name << endl
		<< " Unit: " << unit << endl;
	if (Tx) cout << " Taxed? (y/n): " << Tx << endl;
	if (price[0]) cout << " Price: " << price << endl;
	if (qty[0]) cout << " Quantity on hand: " << qty << endl;
	if (qtyNd[0]) cout << " Quantity needed: " << qtyNd << endl;
	if (date[0]) cout << " Expiry date (YYYY/MM/DD): " << date << endl;
	cout << endl;
}

// dumpFile inserts the contents of fname into cout 
//
void dumpFile(const char* fname) {
	ifstream f(fname);
	char ch;
	while (!f.get(ch).fail()) {
		cout.put(ch);
	}
	f.clear();
	f.close();
}

// pause_ pauses execution until user presses Enter
//
void pause_() {
	cout << "Press enter to continue ... ";
	cin.ignore(1000, '\n');
	cout << endl;
}
