/***********************************************************
 // OOP244 Workshop 7: Derived Classes
 // File: Hero.h
 // Date: July 11, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 7 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/


#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
	const int MAX_ROUNDS = 100;
	const int sizeOfName = 40;
	class Hero {
		char nameOfHero[sizeOfName + 1];
		int healthOfHero;
		int strOfHero;
	public:
		Hero();
		Hero(const char* name, int health, int str);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		friend std::ostream& operator <<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif /* Hero_hpp */
