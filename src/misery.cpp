#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <minion.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define ERR(x)\
    fprintf(stderr, x); \
    exit(1);

int main()
{
    srand(time(NULL));

    std::vector <Minion> badMinionContext(10);
    std::vector <Minion> goodMinionContext(10);

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "misery");

    window.setFramerateLimit(60);

    sf::Texture personTexture;

    if (!personTexture.loadFromFile("assets/person.png"))
    {
        ERR("Could not load texture from file!");
    }

    for (auto & x : badMinionContext)
    {
        x.get_sprite().setTexture(personTexture);
        x.get_sprite().setPosition(sf::Vector2f(rand()%500, rand()%500));
    }
    
    for (auto & x : goodMinionContext)
    {
        x.get_sprite().setTexture(personTexture);
        x.get_sprite().setPosition(sf::Vector2f(rand()%200, rand()%200));
    }

    sf::Event event;

    sf::Clock clock;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        for (auto & x : badMinionContext)
        {
            window.draw(x.get_sprite());
            x.get_sprite().setColor(sf::Color::Red);

            if (clock.getElapsedTime().asSeconds() > 0.3)
            {
                x.get_sprite().setPosition(sf::Vector2f(rand()%500, rand()%500));
            }
        }

        for (auto & x : goodMinionContext)
        {
            x.get_sprite().setColor(sf::Color::Blue);
            window.draw(x.get_sprite());

            if (clock.getElapsedTime().asSeconds() > 0.3)
            {
                x.get_sprite().setPosition(sf::Vector2f(rand()%500, rand()%500));
            }
        }

        if (clock.getElapsedTime().asSeconds() > 0.3)
        {
            clock.restart();
        }

        window.display();
    }

    return 0;
}