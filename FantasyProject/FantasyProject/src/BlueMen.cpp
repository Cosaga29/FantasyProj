#include "BlueMen.hpp"

BlueMen::BlueMen() :
	Character(10, 3, 12, 2)
{
	characteristic =  "They are small, 6 inch tall, but fast and tough.\n";
	characteristic += "They are hard to hit so they can take some damage. \n";
	characteristic += "They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.\n";
}

int BlueMen::attack()
{
	return roll(2, attack_power);
}

void BlueMen::defend(int damage)
{
	int defense_roll = roll(calcMobDefenseRolls(), 6);
	std::cout << "Defense roll: " << defense_roll << std::endl;


	int damage_taken = damage - (defense_roll + armor);
	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

	if (damage_taken > 0) {

		strength -= damage_taken;

	}
	std::cout << "Defenders strength: " << strength << std::endl;
}

void BlueMen::getClass() const
{
	std::cout << "BlueMen " << std::endl;
}

/*
Blue men special ability 

Defensive rolls for strength 12 starts at 3d6
Every 4 points of health lost they lose a die roll


*/
int BlueMen::calcMobDefenseRolls() const
{
	int defense_rolls = std::ceil((double)strength / 4.0);
	return defense_rolls;
}

BlueMen::~BlueMen()
{
}
