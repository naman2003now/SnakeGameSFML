#include "Snake.h"
#include <iostream>

Snake::Snake(){
    this->snakeElements = {
        sf::Vector2f(10, 10),
        sf::Vector2f(11, 10),
        sf::Vector2f(12, 10)
    };
}

Snake::~Snake(){
    std::cout << "Game Over!!!!!!" << std::endl;
}

bool Snake::move(sf::Vector2f direction){
    if(direction != -currentMovingDirection){
        this->currentMovingDirection = direction;
    }
    return true;
}

bool Snake::update(){
    
    return true;
}

