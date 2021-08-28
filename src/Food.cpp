#include "Food.h"


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
    this->position = generatePosition(snakeElements, gridSize);
}

Food::~Food(){

}

void Food::draw(sf::Color color, sf::RenderWindow &window){
    this->sprite.setScale(sf::Vector2f(25, 25));
    this->sprite.setFillColor(color);
    this->sprite.setPosition(position);
    window.draw(this->sprite);
}

