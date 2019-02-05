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
	int defense_roll = roll(2, 6);
	std::cout << "Defense roll: " << defense_roll << std::endl;

	int damage_taken = damage - (defense_roll + armor);

	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;


	if (damage_taken > 0) {

		strength -= damage_taken;
	
	}
	std::cout << "Defenders strength: " << strength << std::endl;
}

void Barbarian::getClass() const
{
	std::cout << "Barbarian " << std::endl;
}

Barbarian::~Barbarian()
{
}
