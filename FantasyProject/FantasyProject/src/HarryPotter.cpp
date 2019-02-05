#include "HarryPotter.hpp"

void HarryPotter::hogwarts()
{
	std::cout << "Harry Potter's health reaches 0, he uses \"Dumbledore's Favorite\" and heals back to 20 HP!" << std::endl;
	strength = 20;
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

	int defense_roll = roll(2, 6);
	std::cout << "Defense Roll: " << defense_roll << std::endl;

 	int damage_taken = damage - (defense_roll + armor);
	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

	if (damage_taken > 0) {

		strength -= damage_taken;

	}

	//if harry dies, check if its his first death
	if (strength <= 0) {
		if (m_deathCount == 0) {	//if its his first death, use hogwarts ability
			hogwarts();				
			m_deathCount++;		
		}
	}

	std::cout << "Defenders strength: " << strength << std::endl;
}

void HarryPotter::getClass() const
{
	std::cout << "Harry Potter " << std::endl;
}

HarryPotter::~HarryPotter()
{
}
