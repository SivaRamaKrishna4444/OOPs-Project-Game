#include "game.hpp"
#include<iostream>

Game ::Game()
{
    InitGame();   //initialises the game
}

Game ::~Game()
{
    Alien::UnloadImages();  // to unload texture data..(images)
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

    for(auto& alien : aliens){
        alien.Draw();
    }

    for(auto& bulletuu: alienBulletsuu){
        bulletuu.draw();
    }

    mysteryship.Draw();
}

void Game::Update()
{
    if(run){    //if it is running it will update
        double currentTime = GetTime();
        if(currentTime - timeLastSpawn > mysteryShipSpawnInterval){
            mysteryship.Spawn();
            timeLastSpawn = GetTime();
            mysteryShipSpawnInterval = GetRandomValue(10,20);
        }

        for(auto &bullet : spaceship.bullets)
        {
            bullet.update();
        }

        MoveAliens();   //it should move for enitre game
    
        AlienPushpaBulletuu();

        for(auto&bulletuu : alienBulletsuu){   //for every bullet in alienbulletuu , update the bullet..
            bulletuu.update();
        }
        DeleteInactiveBullets();

        mysteryship.Update();

        CheckForCollisions();
    } else{   //else after the game over if we press enter button it will reset and new game will start
        if(IsKeyDown(KEY_ENTER)){
            Reset();   //reset the entire game
            InitGame();  //initialises the game
        }
    }
}

void Game::HandleInput()
{
    if(run){  //if the game is running
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

    for(auto it = alienBulletsuu.begin(); it!= alienBulletsuu.end();){
        if(!it->active)
        {
            it = alienBulletsuu.erase(it);
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
        obstacles.push_back(Obstacle({offsetX,float(GetScreenHeight() - 200)}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAliens()
{

    std::vector<Alien> aliens;
    for(int row = 0 ; row < 5 ; row++){   //5 rows of aliens

        int alienType;   //for the type of alien(we have 3 types)
        if(row == 0){
            alienType = 3;
        }
        else if (row == 1 || row == 2){
            alienType = 2;
        }
        else {
            alienType = 1;
        }
        for(int column = 0 ; column < 11; column++){   // 11 columns of aliens
            float x = 75 + column * 55;    //cellsize is hardcoded to 55 pixels
            float y = 110 + row * 55;      // 75,110 adding to them for crct position of aliens in centre
            aliens.push_back(Alien(alienType,{x,y}));
        }
    }
    return aliens;
}

void Game::MoveAliens()
{

    for(auto&alien : aliens){
        if(alien.position.x + alien.alienImages[alien.type - 1].width>GetScreenWidth() -25){
            aliensDirection = -1;   //move until the end of right screen and moves leftt direction 
            MoveDownAliens(4); //move all the aliens down by 4 pixels when it hit right screen
        }
        if(alien.position.x < 0){
            aliensDirection = 1;  //move until the end of left screen and moves right directionnn
            MoveDownAliens(4); //move all the aliens down by 4 pixels when it hit left screen
        }

        alien.Update(aliensDirection);  //updates every aliens
    }
}

void Game::MoveDownAliens(int distance)
{
    for(auto&alien : aliens){
        alien.position.y += distance;
    }
}

void Game::AlienPushpaBulletuu()
{
    double currentTime = GetTime();
    if(currentTime - timeLastAlienPushpaad >= AlienBulletPushpainterval && !aliens.empty()){

        int randomIndex = GetRandomValue(0,aliens.size()-1);
        Alien& alien = aliens[randomIndex];
        alienBulletsuu.push_back(bulletuu({ alien.position.x + alien.alienImages[alien.type-1].width/2,
                                            alien.position.y + alien.alienImages[alien.type-1].height},6));  //6 the speed of bullet

        timeLastAlienPushpaad = GetTime();
    }
}


void Game::CheckForCollisions()
{
    // Spaceship bulletsuu
    for(auto& bulletuu : spaceship.bullets){
        auto it = aliens.begin();
        while(it != aliens.end()){
            if(CheckCollisionRecs(it -> getRectangle(),bulletuu.getRectangle()))
            {
                if(it->type == 1){
                    score+= 100;   //increasing score by 100 if type 1
                }else if(it->type == 2){
                    score+= 200;   //increasing by 200 if typw 2
                }else if(it->type == 3){
                    score+= 300;  //increasing by 300 if type 3
                }

                it = aliens.erase(it);
                bulletuu.active = false;
            }else{
                ++it;
            }
        }
        
        for(auto& obstacle: obstacles){
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it-> getRectangle(), bulletuu.getRectangle())){
                    it = obstacle.blocks.erase(it);
                    bulletuu.active = false;
                }else{
                    ++it;
                }
            }
        }

        if(CheckCollisionRecs(mysteryship.getRectangle(),bulletuu.getRectangle())){
            mysteryship.alive = false;
            bulletuu.active = false;
            score+=500;  //if mysteryship is pushpaad, then increase score by 500
        }
    }

    // Alien Bulletsuuu

    for(auto&bulletuu : alienBulletsuu){
        if(CheckCollisionRecs(bulletuu.getRectangle(), spaceship.getRectangle())){
            bulletuu.active = false;
            lives = lives - 1;
            if(lives == 0){
                GameOver();   //if lives is 0, then the game is over
            }
        }

        for(auto& obstacle: obstacles){
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it-> getRectangle(), bulletuu.getRectangle())){
                    it = obstacle.blocks.erase(it);
                    bulletuu.active = false;
                }else{
                    ++it;
                }
            }
        }
    }

    // Alien Collision with Obstacle
    for(auto& alien : aliens){
        for(auto&obstacle : obstacles){
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it -> getRectangle(), alien.getRectangle())){
                    it = obstacle.blocks.erase(it);
                }else{
                    it++;
                }
            }

        }

        if(CheckCollisionRecs(alien.getRectangle(),spaceship.getRectangle())){
            GameOver();  //if spaceship is colliding with aliens then also gameover
        }
    }
    
}

void Game::GameOver()
{
    run = false;  //if game over, then the run will set to false
}

void Game::InitGame()
{  //initialises all the methods
    obstacles = CreateObstacles();
    aliens = CreateAliens();
    aliensDirection = 1;
    timeLastAlienPushpaad = 0.0;
    timeLastSpawn = 0.0;
    lives = 3;
    score = 0; //intially score = 0
    run = true;
    mysteryShipSpawnInterval = GetRandomValue(10,20);   
}

void Game::Reset()
{  //resets all the methods;;
    spaceship.Reset();
    aliens.clear();
    alienBulletsuu.clear();
    obstacles.clear();
}