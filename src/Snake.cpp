#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Snake::Snake(){
    this->snakeElements = {
        sf::Vector2f(6, 7),
        sf::Vector2f(7, 7),
        sf::Vector2f(8, 7)
    };

    this->block.setSize(sf::Vector2f(25, 25));
}

Snake::~Snake(){
    std::cout << "Game Over!!!!!!" << std::endl;
}

bool Snake::move(sf::Vector2f direction){
    if(direction != -currentMovingDirection && this->changeApplied){
        this->currentMovingDirection = direction;
        this->changeApplied = false;
    }
    return true;
}

bool Snake::update(){
    this->changeApplied = true;
    for(int i = this->snakeElements.size() - 1; i > 0; i--){
        this->snakeElements[i] = this->snakeElements[i - 1];
    }   
    this->snakeElements[0] += this->currentMovingDirection;
    return true;
}

void Snake::draw(sf::RenderWindow &window, sf::Color color){
    for(int i = 0; i < this->snakeElements.size(); i++){
        this->block.setPosition(snakeElements[i]*25.0f);
        window.draw(this->block);
    }
}

void Snake::grow(){
    this->snakeElements.insert(this->snakeElements.begin(), this->snakeElements[0] + currentMovingDirection);
}
