#include "Test.h"


// have the two objects move together until they collide - should print collision to the console window
void Test::testIsCollision()
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "TEST");

	Skittle s;
	Bucket b;

	s.setPosition(10, 0);
	b.setPosition(10, 700);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(s);
		window.draw(b);

		if (s.isCollision(b))
		{
			cout << "Collision!" << endl;
		}
		else
		{
			s.move(0, 0.1);
			b.move(0, -0.1);
		}

		window.display();
	}
}

void Test::testGameConstructor()
{
	Game g;

	if (g.gethighScore() == 100) // ** MUST MANUALLY CHANGE VALUE IN highScore.txt to 100!! **
	{
		cout << "Game Constructor SUCCESS" << endl;
	}
	else
	{
		cout << "Game Constructor FAILURE" << endl;
	}
}

void Test::testSkittleCalculateScore()
{
	Skittle s;

	int score = 10, score_og = 10; // b maintains the original value of a before it was modified

	s.calculateScore(score);

	if (score - score_og == s.getWorth()) // score increase (gains from skittles)
	{
		cout << "Skittle calculateScore() SUCCESS" << endl;
	}
	else
	{
		cout << "Skittle calculateScore() FAILED" << endl;
	}
}

void Test::testVegCalculateScore()
{
	Vegetable v;

	int score = 20, score_og = 20; // store original score

	v.calculateScore(score);

	if (score_og - score == (v.getWorth())) // score DECREASED (penalized for broccoli)
	{
		cout << "Vegetable calculateScore() SUCCESS" << endl;
	}
	else
	{
		cout << "Vegetable calculateScore() FAILED" << endl;
	}

}

void Test::testStoreScore()
{
	Game g;

	g.setCurrentScore(100); 
	g.saveScore();

	Game j;

	if (j.gethighScore() == 100)
	{
		cout << "StoreScore SUCCESS" << endl;
	}
	else
	{
		cout << "StoreScore FAILURE" << endl;
	}


}

// runs all 5 tests
void Test::runTests()
{
	testIsCollision();
	testGameConstructor();
	testSkittleCalculateScore();
	testVegCalculateScore();
	testStoreScore();
}