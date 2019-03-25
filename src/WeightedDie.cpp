//////////
// WeightedDie.cpp
// The definitions for WeightedDie members.
//
// Author: Zachary Gummow
// Date Modified: 3/25/19
//////////

#include "WeightedDie.h"

WeightedDie::WeightedDie(int _num_sides, std::vector<int> _weights)
{
	try
	{
		if(_weights.size() != 0 && _weights.size() != size_t(_num_sides))
		{
			throw "WeightedDie(num_sides, weights): Length of weights not equal to number of sides.";
		}
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	num_sides = _num_sides;
	weights = setWeights(_weights);
}
	
int WeightedDie::Roll()
{
	int result = 0;
	double randomResult = RandomInstance::GetInstance()->Random();
	do
	{
		result++;
		if(randomResult <= weights[result-1])
		{
			break;
		}
		
		randomResult -= weights[result-1];
	}
	while(result <= num_sides);
	
	return result;
}

std::vector<double> WeightedDie::setWeights(std::vector<int> _weights)
{
	weights = std::vector<double>();
	if(_weights.size() != 0)
	{
		double total = std::accumulate(_weights.begin(), _weights.end(), 0.0);
		for(int weight : _weights)
		{
			weights.push_back(double(weight) / total);
		}
	}
	else{
		for(int i = 0; i < num_sides; i++)
		{
			weights.push_back(1.0 / double(num_sides));
		}
	}
	return weights;
}