#include <iostream>
#include <vector>
#include <algorithm>

#include "NumGenerator.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"


//sort vector of character points by speed
bool fasterCharacter(Character* first, Character* second) {
	return first->getSpeed() > second->getSpeed();
}



int main() {

	srand(time(NULL));

	std::vector<Character*> characters;

	//pick two characters to fight
	characters.push_back(new HarryPotter());
	characters.push_back(new Medusa());

	//sort pointers to characters based on speed. The character at characters[0] is the fastest.
	std::sort(characters.begin(), characters.end(), &fasterCharacter);


	//In the case of a speed tie, the character that was added first goes first in combat.



	//combat loop
	bool character_died = false;
	


	while (!character_died) {







	}








	//std::cout << "test";
	std::cin.get();

	return 0;
}