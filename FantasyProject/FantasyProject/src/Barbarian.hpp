#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP


#include "Character.hpp"


class Barbarian : public Character {

private:



public:

	Barbarian();

	int attack() override;

	void defend(int) override;

	~Barbarian();
};



#endif