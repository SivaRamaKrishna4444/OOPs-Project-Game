#include "game.hpp"
#include<iostream>

Game ::Game()
{
    obstacles = CreateObstacles();
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

    for(auto& obstacle: obstacles){
        obstacle.Draw();
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
    if(IsKeyDown(KEY_LEFT))     //if key pressed is left, move left
    {
        spaceship.MoveLeft();
    }
    if(IsKeyDown(KEY_RIGHT))   // if key pressed is right, move right
    {
        spaceship.MoveRight(); 
    }
    if(IsKeyDown(KEY_SPACE))   //if key pressed is space, then fire(pushpa)(bullet)
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

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstacleWidth = Obstacle :: grid[0].size()*3;
    float gap = (GetScreenWidth() - (4*obstacleWidth))/5;

    for(int i = 0 ; i < 4 ; i++){
        float offsetX = (i+1)*gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX,float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}