#pragma once

#include "Skittle.h"
#include "Vegetable.h"

class Game
{
public:
	Game();
	
	// return currentScore
	int getcurrentScore();

	// return highScore
	int gethighScore();

	// return lives remaining
	int getlives();

	// set currentScore - for testing purposes
	void setCurrentScore(int newScore);

	// displays falling objects the screen, checks for collisions, and handles sound effects of collisions
	void fallingObjects(sf::RenderWindow &window, sf::Clock &clock, Bucket b, sf::Sound &veg, sf::Sound &skittle);
	
	// checks if currentScore is a new high score or not
	bool newHighScore();

	// writes currentScore to a file (only if it's a high score)
	void saveScore();

	// display text using consistent font and color (either red or green). Takes in the font,
	// text object, msg to print, green or not, and text character size.
	void gameText(sf::Font &font, sf::Text &text, string msg, bool green, int charSize);

	// displays the end of game stats to the console.
	void displayStats(double timeAlive);

	// runs the entire application with background music, menus, and text feedback to the user
	void runApp(sf::Music &background, sf::Sound &end, sf::Sound &veg, sf::Sound &skittle);

private:
	Skittle allSkittles[6]; // stores all the falling skittles - they are "recycled" once they fall off the screen
	Vegetable allVegetables[12]; // 12 falling broccolis - they are recycled as well since they inherit from skittleClass
	int currentScore; // current score
	int highScore; // high score - read from file
	int lives; // lives - updated when brocolli is hit
	int skittlesEaten; // counts how many skittles are eaten to display at the end
	fstream file;
};