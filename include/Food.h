#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>

class Food{
private:
    sf::RectangleShape sprite;
public:
    sf::Vector2f position;
    void draw(sf::Color color, sf::RenderWindow &window);
    Food(std::vector<sf::Vector2f> snakeElements, sf::Vector2i gridSize);
    ~Food();

};