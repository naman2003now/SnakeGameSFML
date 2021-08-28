#include "Food.h"
#include <iostream>

sf::Vector2f generatePosition(std::vector<sf::Vector2f> snakeElements, sf::Vector2i gridSize){
    sf::Vector2f tempPosition = sf::Vector2f(rand()%gridSize.x, rand()%gridSize.y);
    for(int i = 0; i < snakeElements.size(); i++){
        if(snakeElements[i] == tempPosition){
            tempPosition = generatePosition(snakeElements, gridSize);
        }
    }
    return tempPosition;
}

Food::Food(std::vector<sf::Vector2f> snakeElements, sf::Vector2i gridSize){
    srand(time(0));
    this->position = generatePosition(snakeElements, gridSize);
}

Food::~Food(){
    std::cout << "Tasty!!" << std::endl;
}

void Food::draw(sf::Color color, sf::RenderWindow &window){
    this->sprite.setSize(sf::Vector2f(25.0f, 25.0f));
    this->sprite.setFillColor(color);
    this->sprite.setPosition(position*25.0f);
    window.draw(this->sprite);
}

