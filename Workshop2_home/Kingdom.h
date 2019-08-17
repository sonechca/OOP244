/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File: Kingdom.cpp
 // Date: May 23, 2019
 // Author: Robert Robson
 // Name: Mintae Kim
 // Reason: Workshop 2 Home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {
    
    struct Kingdom {
        char m_name[32];
        int m_population;
    };
    
    void display(const Kingdom& m);
    void display(const Kingdom k[], int size);
}
#endif // !HEADER_KINGDOM_H
