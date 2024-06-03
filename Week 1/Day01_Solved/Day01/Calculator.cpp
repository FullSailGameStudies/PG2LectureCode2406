#include "Calculator.h"

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}

bool Calculator::isEven(int number)
{
	return number % 2 == 0;
}

float Calculator::average(std::vector<float> grades)
{
	float sum = 0;
	for (size_t i = 0; i < grades.size(); i++)
	{
		sum += grades[i];
	}
	float avg = sum / grades.size();
	return avg;
}
