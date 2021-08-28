#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include <iostream>

sf::Vector2f RESOLUTION = sf::Vector2f(800, 800);
sf::Color SnakeColor = sf::Color(250, 250, 250);
sf::Color Background = sf::Color(50, 50, 50);
sf::Color FoodColor = sf::Color(250, 125, 50);
sf::Time frameTime = sf::milliseconds(100);

int main()
{
    sf::RenderWindow window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), "SFML works!");
    sf::Event event;
    sf::Clock clock;
    Snake snake;
    Food food(snake.snakeElements, sf::Vector2i(32, 32));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed){
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    snake.move(UP);
                    break;
                case sf::Keyboard::S:
                    snake.move(DOWN);
                    break;
                case sf::Keyboard::A:
                    snake.move(LEFT);
                    break;
                case sf::Keyboard::D:
                    snake.move(RIGHT);
                    break;
                }
            }
        }
        if(clock.getElapsedTime() > frameTime){
            clock.restart();
            snake.update();
        }
        window.clear(Background);
        snake.draw(window, SnakeColor);
        food.draw(FoodColor, window);
        window.display();
    }

    return 0;
}