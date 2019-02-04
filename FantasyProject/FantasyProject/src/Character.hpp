#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "NumGenerator.hpp"
#include <iostream>


//type codes used for printing round information only
enum character_type {BARB, BLUE, HARRY, MEDUSA, VAMPIRE };

static const std::string charactrer_names[5] = { "Barbarian ", "BlueMen ", "Harry Potter ", "Medusa ", "Vampire " };

/*
Abstract class for character
*/


class Character {

protected:

	int attack_power;
	int armor;
	int strength;
	int speed;

	std::string characteristic;


public:

	Character(int, int, int, int);

	virtual int attack() = 0; //return damage from attack

	virtual void defend(int) = 0; //accept an attack, calculate damage infliced

	virtual ~Character();

	int getStrength() const; //return strength

	std::string getCharacteristic() const;

	int getSpeed() const; //return speed
};



#endif