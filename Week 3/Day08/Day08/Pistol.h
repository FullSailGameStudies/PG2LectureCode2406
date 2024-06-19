#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int magCapacity, int rounds)
		: Weapon(range,damage), magCapacity_(magCapacity), rounds_(rounds)
	{
	}

	int MagCapacity() const { return magCapacity_; }
	int Rounds() const { return rounds_; }

	void MagCapacity(int magCap) {
		if (magCap < 150 && magCap > 0)
			magCapacity_ = magCap;
	}
	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}

private:
	int magCapacity_, rounds_;

};

