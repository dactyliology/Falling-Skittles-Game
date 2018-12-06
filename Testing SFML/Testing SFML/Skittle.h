#pragma once

#include "Bucket.h"


class Skittle : public sf::RectangleShape
{
public:
	Skittle(double x = 0, double y = 0) : RectangleShape(sf::Vector2f(50, 50))
	{
		this->setPosition(rand() % 1150, 0);
		worth = 10; // points gained per skittle
	};

	// sets color based on integer "menu" options
	void setColor(int color);

	// sets speed based on integer "menu" options
	void setSpeed(int speedMode);

	// set the point worth of a skittle
	void setWorth(int newWorth);

	// get the point worth of a skittle
	int getWorth();

	// moves a single skittle from top to bottom of screen. at the bottom, the skittle is randomly spawned
	// in a new position at the top of the screen.
	void skittleFall();

	// checks if the skittle collides with any bucket object: true for collion, false otherwise.
	bool isCollision(Bucket &b);

	// adjusts the score as necessary based on the gain of a skittle. is overridden in vegetable class.
	virtual void calculateScore(int &score);

private:
	double speed;
	int worth;

};
