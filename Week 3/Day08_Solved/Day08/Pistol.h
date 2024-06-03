#pragma once
#include "Weapon.h"
#include <string>
#include <iostream>

class Pistol : public Weapon
{
public:
	Pistol(int rounds, int magCapacity, int range, int damage)
		: Weapon(range, damage), mRounds(rounds), mMagCapacity(magCapacity)
	{

	}

	Pistol operator+(Pistol const& otherPistol)
	{
		int magCap = std::max<int>(mMagCapacity, otherPistol.mMagCapacity);
		int rounds = std::min<int>(magCap, mRounds + otherPistol.mRounds);
		Pistol newPistol(rounds, magCap, range(), damage());
		return newPistol;
	}

	void showMe() override
	{
		Weapon::showMe();//extending the base version
		std::cout << "\tRounds: " << mRounds << " Magazine Capacity: " << mMagCapacity << "\n";
	}

	//getter (accessor)
	int rounds() const
	{
		return mRounds;
	}

	//setter (mutator)
	void rounds(int newRounds)
	{
		mRounds = newRounds;
	}

	//getter (accessor)
	int magCapacity() const
	{
		return mMagCapacity;
	}

	//setter (mutator)
	void magCapacity(int newMagCapacity)
	{
		mMagCapacity = newMagCapacity;
	}

protected:

private:
	int mRounds;
	int mMagCapacity;
};

