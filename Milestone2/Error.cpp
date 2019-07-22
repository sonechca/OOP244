/***********************************************************
 // OOP244 Milestone 2: The Error Module
 // File: Error.cpp
 // Date: July 18, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Milestone 2
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Error.h"

namespace aid {
    Error::Error(const char* errorMessage) {
        
        if (errorMessage == nullptr || strlen(errorMessage) == 0) {
            pMessage = nullptr;
        }
        else {
            pMessage = new char[strlen(errorMessage) + 1];
            strcpy(pMessage, errorMessage);
        }
        
    }
    
    Error:: ~Error() {
        delete[] pMessage;
        pMessage = nullptr;
    }
    void Error::clear() {
        delete[] pMessage;
        pMessage = nullptr;
    }
    bool Error::isClear() const {
        if (pMessage == nullptr)
            return 1;
        else
            return 0;
    }
    void Error::message(const char* str) {
        
        delete[] pMessage;
        pMessage = nullptr;
        if (str == nullptr || strlen(str) == 0) {
            pMessage = nullptr;
        }
        else {
            pMessage = new char[strlen(str) + 1];
            strncpy(pMessage, str, strlen(str));
            pMessage[strlen(str)] = '\0';
        }
        
    }
    const char* Error::message() const {
        if (!isClear())
            return pMessage;
        else
            return nullptr;
    }
    std::ostream& operator <<(std::ostream& ostr, Error& e) {
        if (!e.isClear()) {
            ostr << e.message();
            
        }
        return ostr;
    }
}
