#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Components.h"
#include "InputSystem.h"

int main()
{    
    const int resX = 192, resY = 108;
    sf::RenderWindow window(sf::VideoMode(resX, resY), "Glacier Gladiator");
    //sf::RenderWindow window(sf::VideoMode(192, 108), "Glacier Gladiator", sf::Style::Fullscreen);

    window.setVerticalSyncEnabled(true);
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
    Scene* scene = new Scene();
    scene->objects.emplace_back(LeaVec2(20, 0), LeaVec2(9, 9), std::vector<Component*>{
        new BoxRenderer(30, 1) });
    scene->objects.emplace_back(LeaVec2(-20,0), LeaVec2(10, 10), std::vector<Component*>{
        new BoxRenderer(30, 30) });
    scene->objects.emplace_back(LeaVec2(-40, 0), LeaVec2(15, 15), std::vector<Component*>{
        new BoxRenderer(30, 60) });
    std::cout << "Objects instantiated: " << scene->objects.size() << std::endl;

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

        // the combination of renderers using BlendAdd and not calling the window clear makes
        // a cool smearing effect
        scene->Render(window, resX, resY);
        window.display();
    }

    scene->CloseScene();
    delete(scene);

    return 0;
}