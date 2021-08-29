#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

inline sf::Vector2f RIGHT =    sf::Vector2f(1.0f, 0.0f);
inline sf::Vector2f LEFT =     sf::Vector2f(-1.0f, 0.0f);
inline sf::Vector2f UP =       sf::Vector2f(0.0f, -1.0f);
inline sf::Vector2f DOWN =     sf::Vector2f(0.0f, 1.0f);

class Snake{
private:
    sf::Vector2f currentMovingDirection = LEFT;
    sf::RectangleShape block;
    bool changeApplied = true;
public:
    std::vector<sf::Vector2f> snakeElements;
    Snake();
    ~Snake();
    bool move(sf::Vector2f direction);
    bool update();
    void grow();
    void draw(sf::RenderWindow &window, sf::Color color);
};