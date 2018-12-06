#include "Skittle.h"

void Skittle::setColor(int color)
{

	switch (color)
	{
	case 0: 
		setFillColor(sf::Color(255, 102, 102));
		break;
	case 1:
		setFillColor(sf::Color(102, 178, 255));
		break;
	case 2:
		setFillColor(sf::Color::Green);
		break;
	case 3:
		setFillColor(sf::Color(255, 153, 255));
		break;
	case 4:
		setFillColor(sf::Color::Yellow);
		break; 
	}
}

void Skittle::setSpeed(int speedMode)
{
	switch (speedMode)
	{
	case 1:
		speed = 0.1;
		break;
	case 2:
		speed = 0.3;
		break;
	case 3:
		speed = 0.4;
		break;
	case 4:
		speed = 0.7;
		break;
	case 5:
		speed = 0.9;
		break;
	}
}

void Skittle::setWorth(int newWorth)
{
	worth = newWorth;
}

int Skittle::getWorth()
{
	return worth;
}

void Skittle::skittleFall()
{
	this->move(0, speed);

	if (this->getPosition().y > 800) // reloop it to spawn in a different position
	{
		this->setPosition(rand() % 1130, 0);
	}
}

bool Skittle::isCollision(Bucket &b)
{
	return (b.getGlobalBounds().intersects(this->getGlobalBounds())); // check if the bounding boxes overlap
}

void Skittle::calculateScore(int &score)
{
	score += worth;
}
