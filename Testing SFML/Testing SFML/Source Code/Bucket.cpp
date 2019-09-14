#include "Bucket.h"

void Bucket::controlBucket(double speed)
{
	// controls bucket directions
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getPosition().x >= 0)
	{
		this->move(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getPosition().x < 1080)
	{
		this->move(speed, 0);
	}
}