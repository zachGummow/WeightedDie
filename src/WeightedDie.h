//////////
// WeightedDie.h
// The header file for the WeightedDie class.
//
// Author: Zachary Gummow
// Date Modified: 3/25/19
//////////

#ifndef WEIGHTEDDIE_H
#define WEIGHTEDDIE_H

#include <iostream>
#include "RandomInstance.h"

//////////
// The WeightedDie class creates a weighted die with a variable number
// of sides and weights.
//////////
class WeightedDie
{
	
private:

	//////////
	// Field for storing the number of sides the die has.
	//////////
	int num_sides;

	/////////
	// Field for storing normalized side weights.
	/////////
	std::vector<double> weights;

	/////////
	// A helper function that normalizes weight values.
	/////////
	std::vector<double> setWeights(std::vector<int> _weights);

public:

	//////////
	// The constructor.
	// _num_sides: The number of sides the die has, default 6.
	// _weights: A list of weights for each side. Weights are normalized from
	//          the total weight in the vector. _weights should have a length 
	//          equal to the number of sides. If not, an exception will be 
	//          thrown unless _weights has a length of 0 in which case each
	//          side will have an equal weight.
	//////////
	WeightedDie(int _num_sides = 6, std::vector<int> _weights = std::vector<int>());
	
	//////////
	// The Roll function returns a random result from [1, num_sides].
	// The chance of each random side is based on the weights specified in 
	// the constructor.
	//////////
	int Roll();
};

#endif // WEIGHTEDDIE_H