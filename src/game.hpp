#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"

class Game{
    private:
        Spaceship spaceship;
        void DeleteInactiveBullets();
        std::vector<Obstacle> obstacles;
        std::vector<Obstacle> CreateObstacles();
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
};