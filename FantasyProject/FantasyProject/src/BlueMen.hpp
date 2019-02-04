#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include "Character.hpp"


class BlueMen : public Character {

private:


public:

	BlueMen();

	int attack() override;

	void defend(int) override;

	int calcMobDefenseRolls() const;

	~BlueMen();
};



#endif