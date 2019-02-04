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
		std::cout << "Medusa rolled \"Snake Eyes\", its super effective!" << std::endl;
		return 5000;
	}
	return roll(2, attack_power);
}

void Medusa::defend(int damage)
{
	int damage_taken = damage - (roll(1, 6) + armor);

	if (damage_taken > 0) {

		strength -= damage_taken;

	}
}

Medusa::~Medusa()
{
}
