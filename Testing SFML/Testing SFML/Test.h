#pragma once

#include "Game.h"

class Test
{
public:
	// graphically tests collision class
	void testIsCollision(); 

	// test game constructor to make sure loading the prev. high score from file is working.
	void testGameConstructor();

	// tests skittles calculate score.
	void testSkittleCalculateScore();

	// tests vegetables calculateScore, which OVERRIDES skittle's calculateScore()
	void testVegCalculateScore();

	// make sure the score is stored successfully to the file (but only if it's a new high score)
	void testStoreScore(); 


	void runTests(); // runs all 5 tests
};