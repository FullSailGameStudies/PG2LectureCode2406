#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

