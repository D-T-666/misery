#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define ERR(x)\
    fprintf(stderr, x); \
    exit(1);

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "misery");

    window.setFramerateLimit(60);

    sf::Texture personTexture;

    if (!personTexture.loadFromFile("assets/person.png"))
    {
        ERR("Could not load texture from file!");
    }

    sf::Sprite person;
    person.setTexture(personTexture);
    
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(person);
        window.display();
    }

    return 0;
}