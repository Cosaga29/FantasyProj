#include "Vampire.hpp"


Vampire::Vampire() :
	Character(12, 1, 18, 1)
{
	characteristic = "Suave, debonair, but vicious and surprisingly resilient.";
}

int Vampire::attack()
{
	return roll(1, attack_power);
}

void Vampire::getClass() const
{
	std::cout << "Vampire " << std::endl;
}

void Vampire::defend(int damage)
{
	int damage_taken = 0;
	int defense_roll = roll(2, 6);
	//roll for charm special ability
	if (roll(1, 2) == 2) {
		std::cout << "The vampire charmed their opponent into not attacking! " << std::endl;
		std::cout << "Vampire took 0 damage. " << std::endl;
		return;
	}
	else {
		std::cout << "Vampire defense roll: " << defense_roll << std::endl;

		damage_taken = damage - (defense_roll + armor);
		std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

		if (damage_taken > 0) {

			strength -= damage_taken;

		}

	}
	std::cout << "Defenders strength: " << strength << std::endl;
	
}

Vampire::~Vampire()
{
}
