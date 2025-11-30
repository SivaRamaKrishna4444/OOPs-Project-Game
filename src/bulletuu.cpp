#include "bulletuu.hpp"

bulletuu::bulletuu(Vector2 position, int speed) //constructor to intitialize position and speed
{
    this->position = position;//accesing the objects
    this->speed = speed;//accessing the objects 
    active = true; //bullet is active when created
}

void bulletuu::update()
{
    position.y = position.y + speed; //move the bullet vertically
    if(active) //check if the bullet is inside screen area or not
    {
        if(position.y > GetScreenHeight() - 100 || position.y < 25)     //if it goes outside of the window or top of window. deactivate it so we cannot draw it anymore
        {
            active = false; //bullet will be disappeared
        }
    }
}   

void bulletuu::draw()
{
    if(active){ //only draw the bullet if it is active
        DrawRectangle(position.x,position.y,4,15,{255, 0, 255, 255});   //it will give bullet(as rectangle shape...)
    }
}

Rectangle bulletuu::getRectangle()
{
    Rectangle rect;

    rect.x = position.x; //rectangle position x
    rect.y = position.y; //rectangle position y
    rect.width= 4; //bullet width
    rect.height = 15; //bullet height

    return rect;
}
