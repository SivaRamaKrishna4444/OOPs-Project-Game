#include "spaceship.hpp"

Spaceship :: Spaceship()
{
    image = LoadTexture("images/star_trek.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = GetScreenHeight() - image.height;

    lastPushpatime = 0.0;
}

Spaceship :: ~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship :: Draw()
{
    DrawTextureV(image,position,WHITE);
}

void Spaceship::MoveLeft()
{
    position.x = position.x - 5;
    if(position.x < 0)
    {
        position.x = 0;
    }
}

void Spaceship::MoveRight()
{
    position.x = position.x + 5;
    if(position.x > (GetScreenWidth() - image.width))
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void Spaceship::Pushpa()
{
    if(GetTime() - lastPushpatime >= 0.15)
    {
        bullets.push_back(bulletuu({position.x + image.width/2,position.y},-6));
        lastPushpatime = GetTime();
    }
    
}
