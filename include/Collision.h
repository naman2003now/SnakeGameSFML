#pragma once
#include "Food.h"
#include "Snake.h"

class Collision{
private:
public:
    static const int SELF = 1;
    static const int WALL = 2;
    static const int NONE = -1;
    static const int FOOD = 0;
    int check(Snake &snake, Food &food);
    Collision();
    ~Collision();
};  
