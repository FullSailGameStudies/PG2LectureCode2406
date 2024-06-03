#pragma once
class Sample
{
private:
	int mSomeData = 5;
	int WhatIsTheData() const
	{
		//mSomeData += 10;//not allowed on const method
		return mSomeData;
	}
};

