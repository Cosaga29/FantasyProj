#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP	


#include "Character.hpp"

#define LIVES 1;




class HarryPotter : public Character {


private:

	int m_deathCount;	//keeps track of how many times Harry has died.

	bool isLastDeath();

public:

	HarryPotter();

	int attack() override;

	void defend(int) override;

	~HarryPotter();
};




#endif