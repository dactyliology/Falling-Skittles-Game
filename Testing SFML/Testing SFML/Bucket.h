#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <fstream>



using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::to_string;


class Bucket : public sf::RectangleShape
{
public:
	Bucket() : RectangleShape(sf::Vector2f(120, 120)) // size of bucket
	{
		this->setPosition(255, 680); // set spawn position
	};

	// allows user to control the bucket using left and right arrow keys
	void controlBucket(double speed); 
};
