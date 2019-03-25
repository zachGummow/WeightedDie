//////////
// RandomInstance.cpp
// The definitions for RandomInstance members.
//
// Author: Zachary Gummow
// Date Modified: 3/25/19
//////////

#include "RandomInstance.h"

//////////
//Initial static values
//////////
RandomInstance* RandomInstance::instance = NULL;
std::mt19937 RandomInstance::gen;;
std::uniform_real_distribution<> RandomInstance::dis;

RandomInstance::RandomInstance()
{
	std::random_device rd;
	gen = std::mt19937(rd());
	dis = std::uniform_real_distribution<>(0.0, 1.0);
}

RandomInstance* RandomInstance::GetInstance()
{
	if(instance == NULL)
	{
		instance = new RandomInstance();
	}
	
	return instance;
}
	
double RandomInstance::Random()
{
	return dis(gen);
}