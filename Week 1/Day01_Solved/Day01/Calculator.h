#pragma once
#include <vector>
class Calculator
{
public:
	//the declaration of the minus method
	int minus(int number1, int number2);

	static double mult(double num, double factor);

	bool isEven(int number);

	float average(std::vector<float> grades);
};

