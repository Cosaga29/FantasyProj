#ifndef MEDUSA_HPP
#define MEDUSA_HPP


#include "Character.hpp"



class Medusa : public Character {

private:


public:

	Medusa();

	int attack() override;

	void defend(int) override;

	~Medusa();
};


#endif