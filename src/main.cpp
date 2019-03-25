//////////
// main.cpp
// This main shows usage examples for the WeightedDie
// class as well as empirical tests to prove the 
// correctness of output.
//
// Author: Zachary Gummow
// Date Modified: 3/25/19
//////////

#include <iomanip>
#include <iostream>
#include <vector>

#include "WeightedDie.h"

int main()
{
	// Create an unbiased, six sided die.
	WeightedDie sixSided = WeightedDie();
	// Create a biased, six sided die. 
	// Has a 50% chance of a 1 and an equal chance of all other sides.
	WeightedDie sixSidedBias1 = WeightedDie(6, {5, 1, 1, 1, 1, 1});
	
	// Create an unbiased, ten sided die.
	WeightedDie tenSided = WeightedDie(10);
	// Create a biased, ten sided die. Sides 7, 8, and 9 are twice as likely as other sides.
	WeightedDie tenSidedBias789 = WeightedDie(10, {1, 1, 1, 1, 1, 1, 2, 2, 2, 1});
	
	// The expected value of a die can be calculated using the following formula:
	// E[X] = Σ x*P(x), x = 1 to num_sides
	// Where X is a random variable representing our die, x is a result of the 
	// die, and P(x) is the probability of the specific result.
	
	// The following loops test the WeightedDie class.
	// We roll each die 1,000,000 times and average the results. We should see the average
	// is very close to the calculated expected value.
	
	double sixTotal = 0.0, sixBiasTotal = 0.0, tenTotal = 0.0, tenBiasTotal = 0.0;
	for(int i = 0; i < 1000000; i++)
	{
		sixTotal += sixSided.Roll();
		sixBiasTotal += sixSidedBias1.Roll();
		tenTotal += tenSided.Roll();
		tenBiasTotal += tenSidedBias789.Roll();
	}
	
	sixTotal /= 1000000.0;
	sixBiasTotal /= 1000000.0;
	tenTotal /= 1000000.0;
	tenBiasTotal /= 1000000.0;
	
	std::cout << "Unbiased six sided die expected result: 3.5" << std::endl;
	std::cout << "Averaged result after 1,000,000 trials: " << std::setprecision(5) << sixTotal << std::endl << std::endl;
	
	std::cout << "Biased six sided die expected result: 2.5" << std::endl;
	std::cout << "Averaged result after 1,000,000 trials: " << std::setprecision(5) << sixBiasTotal << std::endl << std::endl;
	
	std::cout << "Unbiased ten sided die expected result: 5.5" << std::endl;
	std::cout << "Averaged result after 1,000,000 trials: " << std::setprecision(5) << tenTotal << std::endl << std::endl;
	
	std::cout << "Biased ten sided die expected result: ~6.0769" << std::endl;
	std::cout << "Averaged result after 1,000,000 trials: " << std::setprecision(5) << tenBiasTotal << std::endl << std::endl;
	
}