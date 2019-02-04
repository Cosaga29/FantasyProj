#include "HarryPotter.hpp"

bool HarryPotter::isLastDeath()
{
	return m_deathCount > 0;
}

HarryPotter::HarryPotter() :
	Character(6, 0, 10, 3)
{
	characteristic = "Yer a wizard Harry.";
	m_deathCount = 0;
}

int HarryPotter::attack()
{
	return roll(2, attack_power);
}

void HarryPotter::defend(int damage)
{
	int damage_taken = damage - (roll(2, 6) + armor);

	if (damage_taken > 0) {

		strength -= damage_taken;

	}

	if (strength <= 0) {
		if (!isLastDeath()) {
			std::cout << "Harry Potters health reaches 0, he uses \"Dumbledore's Favorte\" and heals back to 20 HP!" << std::endl;
			strength = 20;
		}
	}
}

HarryPotter::~HarryPotter()
{
}
