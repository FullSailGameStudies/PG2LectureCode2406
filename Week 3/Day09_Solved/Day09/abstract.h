#pragma once


//abstract base class
class Weapon
{
public:
	virtual int calcDamage() = 0;//pure virtual
};

class Grenade : public Weapon
{
public:
	//required to implement
	virtual int calcDamage()
	{	}
};