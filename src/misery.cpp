#include <stdio.h>
#include <vector>
#include <minion.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define ERR(x)\
    fprintf(stderr, x); \
    exit(1);

int main()
{
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
    }
    
    for (auto & x : goodMinionContext)
    {
        x.get_sprite().setTexture(personTexture);
    }

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
        
        window.display();
    }

    return 0;
}