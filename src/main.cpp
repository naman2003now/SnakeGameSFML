#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Collision.h"
#include <iostream>

sf::Vector2f RESOLUTION = sf::Vector2f(800, 800);
sf::Color SnakeColor = sf::Color(250, 250, 250);
sf::Color Background = sf::Color(50, 50, 50);
sf::Color FoodColor = sf::Color(250, 50, 50);
sf::Time frameTime = sf::milliseconds(100);

int main()
{
    sf::RenderWindow window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), "SnakeGame");
    sf::Event event;
    sf::Clock clock;
    Snake snake;
    Food food(snake.snakeElements, sf::Vector2i(32, 32));
    Collision collision;


    while (window.isOpen())
    {

        //EventLoop
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

        //GameLoop
        if(clock.getElapsedTime() > frameTime){
            clock.restart();
            switch(collision.check(snake, food)){
            case Collision::FOOD:
                snake.grow();
                food = Food(snake.snakeElements, sf::Vector2i(32, 32));
                break;
            case Collision::SELF:
                snake = Snake();
                break;
            case Collision::WALL:
                snake =Snake();
                break;
            case Collision::NONE:
                snake.update();
                break;
            }
        }

        //Drawing the Sprites
        window.clear(Background);
        food.draw(FoodColor, window);
        snake.draw(window, SnakeColor);
        window.display();
    }

    return 0;
}