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



#include <iostream>
#include "Kingdom.h"
using namespace std;


namespace sict {
    //This function display Kindom name and Population.
    void display(const Kingdom& m) {
        cout << m.m_name << ", population " << m.m_population  << endl;
    }
    void display(const Kingdom k[], int size){
        int total = 0;
        cout << "------------------------------" << endl << "Kingdoms of SICT" << endl << "------------------------------"<< endl;
        for(int i = 0; i < size; i++){
            cout << i+1 <<". "<< k[i].m_name << ", population " << k[i].m_population << endl;
            total += k[i].m_population;
        }
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << total << endl;
        cout << "------------------------------" << endl;
    }
}
