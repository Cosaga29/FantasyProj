#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP


#include "Character.hpp"

class Vampire : public Character {


private:


public:

	Vampire();

	int attack() override;

	void defend(int) override;

	~Vampire();
};




#endif