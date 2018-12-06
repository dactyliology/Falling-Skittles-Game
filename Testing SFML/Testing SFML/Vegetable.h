#pragma once

#include "Skittle.h"

class Vegetable : public Skittle
{
public:
	Vegetable() : Skittle() {}; // calls skittle constructor
	void calculateScore(int &score); // overridden virtual function from Skittle class
};