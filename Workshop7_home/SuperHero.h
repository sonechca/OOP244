/***********************************************************
 // OOP244 Workshop 7: Derived Classes
 // File: SuperHero.h
 // Date: July 15, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 7 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#ifndef SuperHero_H
#define SuperHero_H
#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int s_bonusStr;
		int s_defence;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int str, int bonus, int def);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif /* SuperHero_hpp */
