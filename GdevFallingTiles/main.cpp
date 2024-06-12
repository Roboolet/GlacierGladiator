#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "InputSystem.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(192, 108), "Glacier Gladiator", sf::Style::Fullscreen);

    /*sf::Texture texture;
    if (!texture.loadFromFile("assets/fireball.png")) {}
    sf::Sprite sprite;
    sprite.setTexture(texture);*/

    Scene* scene = new Scene();

    InputMapping inputMappings[] = {InputMapping(sf::Keyboard::Key::A, "Left")};
    auto len = std::size(inputMappings);
    InputSystem::GetInstance().Initialize(inputMappings, len);

    while (window.isOpen())
    {
        InputSystem::GetInstance().Advance();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputSystem::GetInstance().ProcessEvent(event);
        }

        //window.clear();
        //window.draw(sprite);
        window.display();
    }

    scene->CloseScene();
    delete(scene);

    return 0;
}