#include "Collision.h"

Collision::Collision(){

}

Collision::~Collision(){

}

int Collision::check(Snake &snake, Food &food){
    if(
        snake.snakeElements[0].x < 0 || 
        snake.snakeElements[0].x >= 32 || 
        snake.snakeElements[0].y < 0 || 
        snake.snakeElements[0].y >= 32
    ){
        return this->WALL;
    }
    
    for(int i = 1; i < snake.snakeElements.size(); i++){
        if(snake.snakeElements[i] == snake.snakeElements[0]){
            return this->SELF;
        }
        else if(snake.snakeElements[i] == food.position){
            return this->FOOD;
        }
    }

    return this->NONE;
}