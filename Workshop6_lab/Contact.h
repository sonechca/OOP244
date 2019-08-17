/***********************************************************
 // OOP244 Workshop 5: Class with a Resource
 // File: Contact.h
 // Date: July 5, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 6 Lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef Contact_h
#define Contact_h


namespace sict {
	const int MAX_CHAR = 20;
	class Contact {
		char c_nameOfCon[MAX_CHAR + 1];
		long long* c_phoneNum;
		int c_sizeOfPhone;
	public:
		Contact();
		Contact(const char* name, const long long* phone, int size);
		~Contact();
		bool isEmpty() const;
		void display() const;

	};
}
#endif /* Contact_h */
