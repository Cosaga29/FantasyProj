#include "Barbarian.hpp"

Barbarian::Barbarian() :
	Character(6, 0, 12, 3) 
{
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
}

int Barbarian::attack()
{
	return roll(2, attack_power);
}

void Barbarian::defend(int damage)
{
	int damage_taken = damage - (roll(2, 6) + armor);

	if (damage_taken > 0) {

		strength -= damage_taken;
	
	}
}

Barbarian::~Barbarian()
{
}
