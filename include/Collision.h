#pragma once
#include "Food.h"
#include "Snake.h"

class Collision{
private:
public:
    const char* check(Snake &snake, Food &food);
    Collision();
    ~Collision();
};  
