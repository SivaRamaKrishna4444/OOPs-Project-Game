#include "game.hpp"
#include<iostream>

Game ::Game()
{
}

Game ::~Game()
{
}

void Game ::Draw()
{
    spaceship.Draw();

    for(auto& bullet : spaceship.bullets)
    {
        bullet.draw();
    }
}

void Game::Update()
{
    for(auto &bullet : spaceship.bullets)
    {
        bullet.update();
    }

    DeleteInactiveBullets();
    // std::cout<<"Vector Size: "<<spaceship.bullets.size()<<std::endl;
}

void Game::HandleInput()
{
    if(IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    }
    if(IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }
    if(IsKeyDown(KEY_SPACE))
    {
        spaceship.Pushpa();
    }
}


void Game::DeleteInactiveBullets()
{
    for(auto it = spaceship.bullets.begin(); it!= spaceship.bullets.end();){
        if(!it->active)
        {
            it = spaceship.bullets.erase(it);
        }
        else
        {
            ++ it;
        }
    }
}