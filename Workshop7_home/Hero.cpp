/***********************************************************
 // OOP244 Workshop 7: Derived Classes
 // File: Hero.cpp
 // Date: July 15, 2019
 // Author: Hong Huang
 // Name: Mintae Kim
 // Reason: Workshop 7 home
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
		if (healthOfHero > 0)
			return true;
		else
			return false;

	}
	int Hero::attackStrength() const {
		if (isEmpty())
			return 0;
		else
			return strOfHero;
	}
	bool Hero::isEmpty() const {
		return (nameOfHero[0] == '\0' && healthOfHero == 0 && strOfHero == 0);
		//return nameOfHero[0] == '\0';
	   //// return true;
	//////else
	   // return false;
	}
	std::ostream& operator <<(std::ostream& os, const Hero& hero) {
		if (hero.isEmpty())
			os << "No hero";
		else
			os << hero.nameOfHero;
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero leftHero = first, rightHero = second, result;
		int rounds = 0;
		for (int i = 0; i < MAX_ROUNDS && leftHero.isAlive() && rightHero.isAlive(); i++) {
			leftHero -= rightHero.attackStrength();
			rightHero -= leftHero.attackStrength();
			rounds++;
		}
		if (!leftHero.isAlive()) {
			result = rightHero;
			cout << "Ancient Battle! " << leftHero << " vs " << rightHero << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return second;
		}
		else if (!rightHero.isAlive()) {
			result = leftHero;
			cout << "Ancient Battle! " << leftHero << " vs " << rightHero << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else if (!rightHero.isAlive() && !leftHero.isAlive()) {
			result = leftHero;
			cout << "Ancient Battle! " << leftHero << " vs " << rightHero << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}

	}
}
