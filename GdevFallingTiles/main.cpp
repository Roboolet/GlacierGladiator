#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Components.h"
#include "InputSystem.h"

int main()
{    
    sf::RenderWindow window(sf::VideoMode(192, 108), "Glacier Gladiator");
    //sf::RenderWindow window(sf::VideoMode(192, 108), "Glacier Gladiator", sf::Style::Fullscreen);

    window.setTitle("Glacier Gladiator!");
    window.setFramerateLimit(60);
    srand(129835);

    // create the input mappings
    // ideally i'd do this in a json file or something but that's too complicated for now
    InputMapping inputMappings[] = {
        InputMapping(sf::Keyboard::Key::A, "Left"),
        InputMapping(sf::Keyboard::Key::Left, "Left"),
        InputMapping(sf::Keyboard::Key::S, "Down"),
        InputMapping(sf::Keyboard::Key::Down, "Down"),
        InputMapping(sf::Keyboard::Key::D, "Right"),
        InputMapping(sf::Keyboard::Key::Right, "Right"),
        InputMapping(sf::Keyboard::Key::W, "Up"),
        InputMapping(sf::Keyboard::Key::Up, "Up"),
        InputMapping(sf::Keyboard::Key::Space, "Up")
    };
    auto len = std::size(inputMappings);
    InputSystem::GetInstance().Initialize(inputMappings, len);

    // create objects
    // this too should ideally be done in some format like json or xml
    Scene scene;
    scene.objects.emplace_back(std::vector<Component*>{ 
        new BoxRenderer(0.01) });

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

        scene.Update();

        scene.Render(window);
        window.display();
    }

    scene.CloseScene();

    return 0;
}