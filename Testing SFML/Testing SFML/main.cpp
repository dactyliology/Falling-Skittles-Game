/********************************************************************************************************************
* Authors: Esteban Alcaraz, Nicolette Dixon, Dana Lu, Abdourahman Sarr
* Date: 12/05/2018
* Class: CptS 122, Fall 2018 WSU
* Assignment: PA 9 - Graphical Game or Application
* Description: Implement a game using SFML Library with 5 test cases. See README.txt for more information.
*********************************************************************************************************************/

#include "Game.h"
#include "Test.h"

int main()
{
	Game g;

	srand(time(NULL)); // for use with rand() function


	// handling music files here so they don't go out of scope and cause problems later on
	sf::Music bMusic;

	bMusic.openFromFile("background.wav");

	sf::SoundBuffer vBuffer, sBuffer, eBuffer;

	vBuffer.loadFromFile("bonk.wav");
	sBuffer.loadFromFile("collectSkittlesSound.wav");
	eBuffer.loadFromFile("gameOver.wav");

	sf::Sound veg, skittle, end;

	veg.setBuffer(vBuffer);
	skittle.setBuffer(sBuffer);
	end.setBuffer(eBuffer);

	bMusic.setVolume(25);
	bMusic.play();
	bMusic.setLoop(true); // repeats the music if end of track is reached

	g.runApp(bMusic, end, veg, skittle);



	// TEST CASES - runTests() function runs all 5 test cases! 
	// Please read the conditions for testing in the Test.cpp file
	
	//Test t;

	//t.runTests();


	return 0;
}