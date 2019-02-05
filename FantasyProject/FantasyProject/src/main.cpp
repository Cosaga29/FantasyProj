#include <iostream>
#include <vector>
#include <algorithm>

#include "NumGenerator.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Menu.hpp"
#include "Vampire.hpp"


//sort vector of character points by speed
bool fasterCharacter(Character* first, Character* second) {
	return first->getSpeed() > second->getSpeed();
}


void printAttack(Character* attacker, Character* defender) {
	//display attacker
	std::cout << "Attacker: ";
	attacker->getClass();

	//display defender
	std::cout << "Defender: ";
	defender->getClass();

	//display defender stats
	std::cout << "\tArmor:   " << defender->getArmor()
		<< "\tStrength:" << defender->getStrength() << std::endl;


	std::cout << "\n\nCombat:\n" << std::endl;

	//first character attakcs
	int attack_roll = attacker->attack();
	std::cout << "Attack roll: " << attack_roll << std::endl;


	//second character defends against attack
	defender->defend(attack_roll);
	std::cout << "\n\n" << std::endl;
}


Character* selectChar(character_type charCode) {
	
	Character* toReturn = 0;

	switch (charCode) {
	case BARB:
		toReturn = new Barbarian();
		break;

	case BLUE:
		toReturn = new BlueMen();
		break;

	case HARRY:
		toReturn = new HarryPotter();
		break;

	case MEDUSA:
		toReturn = new Medusa();
		break;

	case VAMPIRE:
		toReturn = new Vampire();
		break;

	}

	return toReturn;
}



int main() {

	srand(time(NULL));

	Menu playAgain;
	playAgain.addPrompt("Play again");
	playAgain.addPrompt("Exit");

	Menu characterSelection;
	characterSelection.addPrompt("Barbarian");
	characterSelection.addPrompt("BlueMen");
	characterSelection.addPrompt("Harry Potter");
	characterSelection.addPrompt("Medusa");
	characterSelection.addPrompt("Vampire");


	std::vector<Character*> characters;

	bool playerExit = false;

	while (!playerExit) {
		characterSelection.displayMessage("Pick first character: ");
		int firstChar = characterSelection.getUserChoice();

		characterSelection.displayMessage("Pick second character: ");
		int secondChar = characterSelection.getUserChoice();




		//pick two characters to fight
		characters.push_back(selectChar(static_cast<character_type>(firstChar - 1)));
		characters.push_back(selectChar(static_cast<character_type>(secondChar - 1)));


		//sort pointers to characters based on speed. The character at characters[0] is the fastest.
		std::sort(characters.begin(), characters.end(), &fasterCharacter);


		//In the case of a speed tie, the character that was added first goes first in combat.


		//combat loop
		bool character_died = false;

		while (!character_died) {


			printAttack(characters[0], characters[1]);

			if (characters[1]->getStrength() > 0) {
				printAttack(characters[1], characters[0]);
			}
			else {
				character_died = true;
			}

			if (characters[0]->getStrength() <= 0) {
				character_died = true;
			}

		}


		//clean resources for next playthrough
		for (int i = 0; i < characters.size(); i++) {
			delete characters[i];
		}
		characters.clear();




		if (playAgain.getUserChoice() == playAgain.getExitCode()) {
			playerExit = true;
		}
	}





	//std::cout << "test";
	std::cin.ignore(34747, '\n');
	std::cin.get();

	return 0;
}