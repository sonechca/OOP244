/***********************************************************
 // OOP244 Workshop 7: Derived Classes
 // File: SuperHero.cpp
 // Date: July 15, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 7 home
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SuperHero.h"
using namespace std;
namespace sict {
	SuperHero::SuperHero() :Hero() {
		s_bonusStr = 0;
		s_defence = 0;
	}
	SuperHero::SuperHero(const char* name, int health, int str, int bonus, int def) : Hero(name, health, str) {
		s_bonusStr = bonus;
		s_defence = def;
	}
	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() != 0)
			return Hero::attackStrength() + s_bonusStr;
		else
			return 0;
	}
	int SuperHero::defend() const {
		if (s_defence != 0)
			return s_defence;
		else
			return 0;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero f_supHero = first;
		SuperHero s_supHero = second;
		SuperHero result;
		int rounds = 0;
		for (int i = 0; i < MAX_ROUNDS && f_supHero.isAlive() && s_supHero.isAlive(); i++) {
			f_supHero -= (s_supHero.attackStrength() - f_supHero.defend());
			s_supHero -= (f_supHero.attackStrength() - s_supHero.defend());
			rounds++;

		}
		if (!f_supHero.isAlive()) {
			result = s_supHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return second;
		}
		else if (!s_supHero.isAlive()) {
			result = f_supHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else if (!s_supHero.isAlive() && !f_supHero.isAlive()) {
			result = f_supHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}

	}

}
