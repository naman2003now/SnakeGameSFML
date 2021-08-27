#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

inline sf::Vector2f RIGHT =    sf::Vector2f(1.0f, 0.0f);
inline sf::Vector2f LEFT =     sf::Vector2f(-1.0f, 0.0f);
inline sf::Vector2f UP =       sf::Vector2f(0.0f, -1.0f);
inline sf::Vector2f DOWN =     sf::Vector2f(0.0f, 1.0f);

class Snake{
private:
    std::vector<sf::Vector2f> snakeElements;
    sf::Vector2f currentMovingDirection = RIGHT;
public:
    Snake();
    ~Snake();
    bool move(sf::Vector2f direction);
    bool update();
};