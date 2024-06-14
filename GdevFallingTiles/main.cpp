#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "InputSystem.h"

int main()
{    
    const int resX = 192, resY = 108;
    sf::RenderWindow window(sf::VideoMode(resX, resY), "Glacier Gladiator");
    //sf::RenderWindow window(sf::VideoMode(192, 108), "Glacier Gladiator", sf::Style::Fullscreen);

    window.setVerticalSyncEnabled(true);
    srand(time(nullptr));

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
    
    Scene* scene = new Scene();
    scene->CreateGameScene1();
    scene->Awake();

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

        scene->Update();   
        scene->PhysicsUpdate();

        // the lack of window.clear() here is intentional, see Scene.cpp
        scene->Render(window, resX, resY);
        window.display();
    }

    scene->CloseScene();
    delete(scene);

    return 0;
}