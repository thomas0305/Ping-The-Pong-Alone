#include <SFML/Graphics.hpp>
#include <iostream>
#include <format>
#include "PlayerMovers.h"

int main()
{
    //Creating the Window
    constexpr int winWidth{ 1600 }, winHeight{ 900 };
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Ping the pong alone :(");
    window.setVerticalSyncEnabled(true);

    //Creating the player
    constexpr int plrWidth{ 220 }, plrHeight{ 15 };
    sf::RectangleShape player;
    player.setSize(sf::Vector2f(plrWidth, plrHeight));
    player.setFillColor(sf::Color::White);
    
    //Setting the player spawn position
    constexpr float plrStartPosX{ 1 }, plrStartPosY{ 600 };
    player.setPosition(sf::Vector2f(plrStartPosX, plrStartPosY));

    float velocity = 0.0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
        {
            //First parameter is the value that will be changed.
            //Second parameter is which x coordinate the function will stop changing x value (i.e border)
            leftVelocity(velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
        {
            //First parameter is the value that will be changed.
            //Second parameter is which x coordinate the function will stop changing x value (i.e border)
            //Third parameter is width of the player, so that the player doesnt move its entire body outside the border to reach desired x value. 
            rightVelocity(velocity, winWidth, plrWidth);
        }

        std::cout << "x velocity is: " << velocity << "\n";
        std::cout << "Velocity: " << velocity << "\n";

        // Updates the positional changes throughout each loop. Only velocity parameter changes, plrStartPosY is only there to fill out the criteria of having two parameters.
        player.setPosition(sf::Vector2f(velocity, plrStartPosY));

        //Render
        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}