//////////
// RandomInstance.h
// The header file for the RandomInstance class.
//
// Author: Zachary Gummow
// Date Modified: 3/25/19
//////////

#ifndef RANDOMINSTANCE_H
#define RANDOMINSTANCE_H

#include <Random>

//////////
// The RandomInstance class is a singleton that ensures that we only
// seed the random number generator once.
//////////
class RandomInstance
{
private:

	//////////
	// The static instance of RandomInstance.
	// Only one ever exists.
	//////////
	static RandomInstance* instance;
	
	//////////
	// A Mersenne Twister pseudo-random generator.
	// Used by RandomInstance to generate random floating-point values;
	//////////
	static std::mt19937 gen;
	
	//////////
	// Produces a random floating-point number in a range.
	//////////
	static std::uniform_real_distribution<> dis;
	
	//////////
	// The private constructor for RandomInstance.
	// Ensures that only one instance exists.
	//////////
	RandomInstance();
	
public:

	//////////
	// Returns the instance pointer.
	// If the RandomInstance instance has not be initialized, the GetInstance
	// function calls the private constructor.
	//////////
	static RandomInstance* GetInstance();
	
	//////////
	// Returns a number between [0, 1)
	//////////
	double Random();
};

#endif // RANDOMINSTANCE_H