#include "Vegetable.h"

void Vegetable::calculateScore(int &score) // overrides skittle calculateScore() function
{
	score -= this->getWorth();
}