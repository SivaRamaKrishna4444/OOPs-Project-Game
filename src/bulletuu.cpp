#include "bulletuu.hpp"

bulletuu::bulletuu(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void bulletuu::update()
{
    position.y = position.y + speed;
    if(active)
    {
        if(position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
        }
    }
}

void bulletuu::draw()
{
    if(active){
        DrawRectangle(position.x,position.y,4,15,{243,216,63,255});
    }
}
