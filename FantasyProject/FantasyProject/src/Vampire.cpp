#include "Vampire.hpp"


Vampire::Vampire() :
	Character(12, 1, 18, 1)
{
	characteristic = "Suave, debonair, but vicious and surprisingly resilient.";
}

int Vampire::attack()
{
	return roll(2, attack_power);
}

void Vampire::defend(int damage)
{
	int damage_taken = 0;
	//roll for charm special ability
	if (roll(1, 2) == 2) {
		std::cout << "The vampire charmed their opponent into not attacking! " << std::endl;

	}
	else {
		int defense_roll = roll(2, 6);
		std::cout << "Vampire defense roll: " << defense_roll << std::endl;

		damage_taken = damage - (roll(2, 6) + armor);

		if (damage_taken > 0) {

			strength -= damage_taken;

		}

	}

	std::cout << "Vampire damage taken: " << damage_taken << std::endl;
	
}

Vampire::~Vampire()
{
}
