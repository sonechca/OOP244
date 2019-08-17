/***********************************************************
 // OOP244 Workshop 7: Derived Classes
 // File: Hero.cpp
 // Date: July 11, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 7 lab
 // Student#: 141915181
 // E-mail: mkim221@myseneca.ca
 ***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <cstring>
using namespace std;
namespace sict {
	Hero::Hero() {
		nameOfHero[0] = '\0';
		healthOfHero = 0;
		strOfHero = 0;
	}
	Hero::Hero(const char* name, int health, int str) {
		if (name != nullptr && name[0] != '\0' && health >= 0 && str >= 0) {
			strncpy(nameOfHero, name, strlen(name));
			nameOfHero[strlen(name)] = '\0';
			healthOfHero = health;
			strOfHero = str;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			healthOfHero -= attack;
		}

		if (healthOfHero < 0) {
			healthOfHero = 0;
		}
	}
	bool Hero::isAlive() const {
		return (healthOfHero > 0);

	}
	int Hero::attackStrength() const {
		if (isEmpty())
			return 0;
		else
			return strOfHero;
	}
	bool Hero::isEmpty() const {
		return (nameOfHero[0] == '\0' && healthOfHero == 0 && strOfHero == 0);
	
	}
	std::ostream& operator <<(std::ostream& os, const Hero& hero) {
		if (hero.isEmpty())
			os << "No hero";
		else
			os << hero.nameOfHero;
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero firstHero = first;
		Hero secondHero = second;
		Hero result;
		int rounds = 0;
		for (int i = 0; i < MAX_ROUNDS && firstHero.isAlive() && secondHero.isAlive(); i++) {
			firstHero -= secondHero.attackStrength();
			secondHero -= firstHero.attackStrength();
			rounds++;
		}
		if (!firstHero.isAlive()) {
			result = secondHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return second;
		}
		else if (!secondHero.isAlive()) {
			result = firstHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else if (!secondHero.isAlive() && !firstHero.isAlive()) {
			result = firstHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}

	}
}
