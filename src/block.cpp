#include "block.hpp"

Block::Block(Vector2 position) //constructor to set the  starting position of block
{
    this-> position = position;
}

void Block :: Draw(){ //function to draw the block onn the screen
    DrawRectangle(position.x,position.y,3,3,{243,216,63,255}); //drawing rectangle with 3x3 size with a yelloish color
}

Rectangle Block::getRectangle() //function to return the collision rectangle of block
{
    Rectangle rect;
    rect.x = position.x; //x position of block
    rect.y = position.y; //y postion of block
    rect.width = 3; //width of block
    rect.height = 5; //height of the block
    
    return rect;
}
