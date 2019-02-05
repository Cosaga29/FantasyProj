#include "Medusa.hpp"

Medusa::Medusa() :
	Character(6, 3, 8, 4)
{
	characteristic = "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!";
}

int Medusa::attack()
{
	int attack_damage = roll(2, attack_power);
	if (attack_damage == 12) {
		std::cout << "Medusa rolled \"Snake Eyes\", its super effective and turned her opponent to stone!" << std::endl;
		return 5000;
	}
	return roll(2, attack_power);
}

void Medusa::getClass() const
{
	std::cout << "Medusa " << std::endl;
}

void Medusa::defend(int damage)
{

	int defense_roll = roll(1, 6);
	std::cout << "Defense roll: " << defense_roll << std::endl;

	int damage_taken = damage - (defense_roll + armor);
	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

	if (damage_taken > 0) {

		strength -= damage_taken;
	}
	std::cout << "Defenders strength: " << strength << std::endl;
}

Medusa::~Medusa()
{
}
