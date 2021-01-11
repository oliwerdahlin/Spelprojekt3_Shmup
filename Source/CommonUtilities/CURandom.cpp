#include "pch.h"
#include "CURandom.h"
#include <random>
namespace CommonUtilities
{
	std::mt19937 rEngine(6);

	float CommonUtilities::RandNumbInRange(int aMinRange, int aMaxRange)
	{
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution<int> distribution(aMinRange, aMaxRange);
		return distribution(device);
	}

	float GetRandomFloat(float aMin, float aMax)
	{
		std::uniform_real_distribution<float> rnd(aMin, aMax);
		return rnd(rEngine);
	}

	double GetRandomDouble(double aMin, double aMax)
	{
		std::uniform_real_distribution<double> rnd(aMin, aMax);
		return rnd(rEngine);
	}

	int GetRandomInt(int aMin, int aMax)
	{
		std::uniform_int_distribution<int> rnd(aMin, aMax);
		return rnd(rEngine);
	}
}

