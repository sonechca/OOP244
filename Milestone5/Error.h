/***********************************************************
 // OOP244 Milestone 5: THE GOOD HIERARCHY
 // File: Error.h
 // Date: July 28, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 5
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef AID_ERROR_H
#define AID_ERROR_H

namespace aid {
	class Error {
		char* pMessage;
	public:
		explicit Error(const char* errorMessage = nullptr);
		~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator << (std::ostream& ostr, Error& e);
}


#endif /* Error_h */
