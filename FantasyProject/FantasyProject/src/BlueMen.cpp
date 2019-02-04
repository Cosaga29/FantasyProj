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
	int damage_taken = damage - (roll(calcMobDefenseRolls(), 6) + armor);

	if (damage_taken > 0) {

		strength -= damage_taken;

	}
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
