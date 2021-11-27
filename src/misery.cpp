#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "../include/minion.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define ERR(x)\
	fprintf(stderr, x); \
	exit(1);

class Game {
private:
	Minion badMinionContext[10];
	Minion goodMinionContext[10];

	sf::RenderWindow window;
	sf::Event event;

	sf::Texture personTexture;
	sf::Sprite minionSprite;

	sf::Clock clock;

public:
	Game() {
		this->setup();
	}

	void setup() {
		window.create(sf::VideoMode::getDesktopMode(), "misery");

		window.setFramerateLimit(60);

		if (!personTexture.loadFromFile("assets/person.png"))
		{
			ERR("Could not load texture from file!");
		}

		for (auto & x : badMinionContext)
		{
			x.set_pos(sf::Vector2f(rand()%500, rand()%500));
		}
		
		for (auto & x : goodMinionContext)
		{
			x.set_pos(sf::Vector2f(rand()%200, rand()%200));
		}

		minionSprite.setTexture(personTexture);
	}

	int loop() {
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (clock.getElapsedTime().asSeconds() > 0.3)
			window.clear(sf::Color::Black);

		sf::Vector2<float> pos;

		for (auto & x : badMinionContext)
		{
			x.get_pos(pos);
			window.draw(minionSprite);
			minionSprite.setColor(sf::Color::Red);

			if (clock.getElapsedTime().asSeconds() > 0.3)
			{
				minionSprite.setPosition(pos);
			}
		}

		for (auto & x : goodMinionContext)
		{
			x.get_pos(pos);
			minionSprite.setColor(sf::Color::Blue);
			window.draw(minionSprite);

			if (clock.getElapsedTime().asSeconds() > 0.3)
			{
				minionSprite.setPosition(pos);
			}
		}

		if (clock.getElapsedTime().asSeconds() > 0.3)
			clock.restart();

		window.display();

		return window.isOpen() ? 0 : 1;
	}
};

int main()
{
	srand(time(NULL));

	Game misery;

	int status = 0;
	while (!status) status = misery.loop();

	return status;
}