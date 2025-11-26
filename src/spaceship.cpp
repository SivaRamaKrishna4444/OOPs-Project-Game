#include "spaceship.hpp"

Spaceship :: Spaceship()
{
    image = LoadTexture("images/spaceship.png");
    position.x = (GetScreenWidth() - image.width)/2;     //to get the position of spaceship initially in bottom middle
    position.y = GetScreenHeight() - image.height- 100;

    lastPushpatime = 0.0;
}

Spaceship :: ~Spaceship()
{
    UnloadTexture(image);   //destructor, it will unload texture of image
}

void Spaceship :: Draw()
{
    DrawTextureV(image,position,WHITE);   //it will draw the image of Spaceshippuu
}

void Spaceship::MoveLeft()
{
    position.x = position.x - 7;  //to move left, position is subtracted
    if(position.x < 25)    //it will move upto left end and if it less than that it will come back to end..
    {
        position.x = 25;
    }
}

void Spaceship::MoveRight()
{
    position.x = position.x + 5;   //to move right, position is added
    if(position.x > (GetScreenWidth() - image.width - 25))    //it will move upto right end, and if it greater than screen width it will come back..
    {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Spaceship::Pushpa()
{
    if(GetTime() - lastPushpatime >= 0.15)    //bullet will be fired at a certain interval of 0.15 (ms)
    {
        bullets.push_back(bulletuu({position.x + image.width/2,position.y},-6));
        lastPushpatime = GetTime();
    }
    
}

Rectangle Spaceship::getRectangle()
{
    return {position.x,position.y,float(image.width),float(image.height)};  //gives the rectangle of the spaceshippp
}

void Spaceship::Reset()
{  //reset the spaceship position 
    position.x = (GetScreenWidth() - image.width)/2.0f;
    position.y = GetScreenHeight() - image.height - 100;
    bullets.clear();
}
