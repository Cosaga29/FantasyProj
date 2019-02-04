#include "Character.hpp"

Character::Character(int attack_power, int armor, int strength, int speed) :
	attack_power(attack_power), armor(armor), strength(strength), speed(speed)
{
}

Character::~Character()
{
}

int Character::getStrength() const
{
	return strength;
}

int Character::getSpeed() const
{
	return speed;
}
