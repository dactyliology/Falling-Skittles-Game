#include "Game.h"

Game::Game()
{
	file.open("highScore.txt", std::ios::in);
	currentScore = 0;
	skittlesEaten = 0;
	file >> highScore; // read in high score
	lives = 5; // everyone gets 5 lives
	file.close();
}

int Game::getcurrentScore()
{
	return currentScore;
}

int Game::gethighScore()
{
	return highScore;
}

int Game::getlives()
{
	return lives;
}

void Game::setCurrentScore(int newScore)
{
	currentScore = newScore;
}

void Game::fallingObjects(sf::RenderWindow &window, sf::Clock &clock, Bucket b, sf::Sound &veg, sf::Sound &skittle)
{
	sf::Time timeElapsed;

	timeElapsed = clock.getElapsedTime(); // update time passed


	// skittles falling
	for (int i = 0; i < 5; i++)
	{
		if (timeElapsed.asSeconds() > 2 * i) // stagger the release of skittles
		{
			allSkittles[i].setColor(i); // sets color of skittle 

			allSkittles[i].setSpeed(2); // set speed, see skittle.cpp for speed values

			// check for collision
			if(allSkittles[i].isCollision(b))
			{
				// respawn here - moves the skittle back to top of screen
				allSkittles[i].setPosition(rand() % 1150, 0);
				allSkittles[i].calculateScore(currentScore); // update score
				cout << "Score Updated: " << currentScore << endl;
				skittlesEaten++;
				skittle.setVolume(50);
				skittle.play();
			}
			else
			{
				// let skittle keep falling
				allSkittles[i].skittleFall();

				// draw
				window.draw(allSkittles[i]);
			}

		}
	}	

	// vegetable falling
	for (int i = 0; i < 11; i++)
	{
		if (timeElapsed.asSeconds() > i) // stagger the release of vegs
		{

			allVegetables[i].setSpeed(3); // let user set speed

			// check for collision
			if (allVegetables[i].isCollision(b))
			{
				// respawn here - moves the veg back to top of screen
				allVegetables[i].setPosition(rand() % 1150, 0);
				allVegetables[i].calculateScore(currentScore); // update score
				cout << "Score Updated: " << currentScore << endl;
				veg.play();
				lives--;
				cout << "\n**************Lives Remaining: " << lives << "**************" << endl;
			}
			else
			{
				// let veg keep moving
				allVegetables[i].skittleFall();

				// draw
				window.draw(allVegetables[i]);
			}
		}
	}

	timeElapsed = clock.getElapsedTime(); // update time passed
}

bool Game::newHighScore()
{
	return (currentScore > highScore);
}

void Game::saveScore()
{
	if (newHighScore()) // only store if it's a new high score
	{
		file.open("highScore.txt", std::ios::out);
		file << currentScore << endl;
		file.close();
	}
}

void Game::gameText(sf::Font &font, sf::Text &text, string msg, bool green, int charSize)
{
	text.setFont(font);
	text.setString(msg);
	text.setCharacterSize(charSize);
	text.setPosition(500, 200);
	text.setStyle(sf::Text::Bold);
	
	if (green) // sets text to green
	{
		text.setFillColor(sf::Color::Green);
	}
	else // sets text to red
	{
		text.setFillColor(sf::Color::Red);
	}

	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(6);
}

void Game::displayStats(double timeAlive)
{
	cout << "\nGAME OVER!" << endl;
	cout << "\t\t--STATS--\t\t" << endl;
	cout << "\tTime Alive: " << timeAlive << " seconds" << endl;
	cout << "\tSkittles Eaten: " << skittlesEaten << endl;
	cout << "\tYour Final Score: " << currentScore << endl; // prints out the score to console when game goes out of scope
}

void Game::runApp(sf::Music &background, sf::Sound &end, sf::Sound &veg, sf::Sound &skittle)
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Game");

	sf::Time duration = sf::seconds(5), countdown = sf::seconds(1), medium = sf::seconds(3); // set some second intervals to pause the screen

	sf::Clock clock; // starts the clock

	sf::Texture skittleTexture, bucketTexture, vegetableTexture;


	// load some textures
	skittleTexture.loadFromFile("skittle.png");
	bucketTexture.loadFromFile("bucket.png");
	vegetableTexture.loadFromFile("vegetable.png");

	Bucket b;

	b.setTexture(&bucketTexture); // set the textures of the vegs and skittles
	for (int i = 0; i < 5; i++)
	{
		allSkittles[i].setTexture(&skittleTexture);
	}
	for (int i = 0; i < 11; i++)
	{
		allVegetables[i].setTexture(&vegetableTexture);
	}

	sf::Font font;
	font.loadFromFile("font.ttf"); // import font 

	sf::Text count;

	bool firstRun = true; // flag so menu doesn't print at every interation of the while loop
	bool play = false; // flag so the title screen is only displayed once

	cout << "Current High Score: " << highScore << endl; // prints current high score to console

	// Graphics window is open
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (firstRun) // displays menu and doesn't continue game until space is pressed
		{
			string menuText = "Falling Skittles!", trigger = "***Press Space to Continue***", instructions = "\t\t\t\t\t\t\t\t\tEat the skittles - don't eat the broccoli!\nMake sure you can see the console window too! (drag and reposition if necessary)";
			sf::Text menu, descript, instruct;

			gameText(font, menu, menuText, true, 180);
			menu.setPosition(50, 120);
			menu.setFillColor(sf::Color::Black);
			window.draw(menu);

			gameText(font, instruct, instructions, true, 30);
			instruct.setPosition(40, 450);
			instruct.setFillColor(sf::Color::White);
			instruct.setOutlineColor(sf::Color::Black);
			window.draw(instruct);

			gameText(font, descript, trigger, true, 75);
			descript.setFillColor(sf::Color::White);
			descript.setOutlineColor(sf::Color::Black);
			descript.setPosition(100, 550);
			descript.setOutlineThickness(3);
			window.draw(descript);

			window.display();

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					play = true;
				}
			}

		}

		if (play)
		{
			if (firstRun) // only execute the countdown one time
			{

				// display a countdown before game starts
				for (int i = 3; i >= 0; i--)
				{
					window.clear();

					if (i != 0) // not the "go" text
					{
						gameText(font, count, to_string(i), true, 300);
					}
					else
					{
						gameText(font, count, "GO!", true, 300);
						count.setPosition(300, 200); // modify the "go" text to be centered

					}
					window.draw(count);
					window.display();

					sf::sleep(countdown); // pause between the display of each digit
				}

				clock.restart(); // restart clock to stagger falling of objects

				firstRun = false; // don't display countdown on subsequent frames
			}

			if (lives != 0)
			{
				window.clear(); // reset screen

				this->fallingObjects(window, clock, b, veg, skittle); // gets the skittles to fall

				window.draw(b); // bucket

				b.controlBucket(0.8); // bucket

				window.display(); // show everything to screen

			}
			else
			{
				double timeAlive = round(clock.getElapsedTime().asSeconds() * 100) / (double)100; // get time alive	
				displayStats(timeAlive); // prints out stats to console
				saveScore(); // saves score (only if it is a new high score)

				background.pause(); // stop the background music
				end.play(); // play game-over sound!


				// Display game-over text
				sf::Text endGame;
				string sStats;

				gameText(font, endGame, "GAME OVER!", false, 100);
				endGame.setPosition(330, 330);

				window.draw(endGame);
				window.display();

				sf::sleep(medium); // pause screen for a bit

				// convert statistics to string
				sStats = "\t\t\t\t-STATS-\n\tTime Alive: " + to_string(timeAlive) + "s" +
					"\n\tSkittles Eaten: " + to_string(skittlesEaten) +
					"\n\tFinal Score: " + to_string(currentScore);

				window.clear();

				// display statistics
				gameText(font, endGame, sStats, false, 100);
				endGame.setPosition(25, 100);
				endGame.setOutlineThickness(3);

				window.draw(endGame);
				window.display();

				sf::sleep(duration); // pause screen for a bit
				window.close(); // close window
			}
		}
	}
}
