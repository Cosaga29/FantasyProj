#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

/*
Abstract class for character
*/


class Character {

protected:

	int attack;
	int defense;
	int armor;
	int strength;

	std::string characteristic;


public:

	Character(int, int, int, int);

	virtual int attack() = 0; //return damage from attack

	virtual void defense(int) = 0; //accept an attack, calculate damage infliced

	virtual ~Character();

	int getStrength() const; //return strength

};



#endif