#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game{
    private:
        Spaceship spaceship;
        void DeleteInactiveBullets();
        std::vector<Obstacle> obstacles;
        std::vector<Obstacle> CreateObstacles();
        std::vector<Alien> aliens;
        std::vector<Alien> CreateAliens();  //tp create the aliens
        void MoveAliens();  //to move the aliens
        int aliensDirection;
        void MoveDownAliens(int distance);  // to move the aliens downn
        std::vector<bulletuu> alienBulletsuu;  
        void AlienPushpaBulletuu();
        constexpr static float AlienBulletPushpainterval = 0.35; //350 milliseconds  
        // constexpr is the expression of constvalue
        float timeLastAlienPushpaad;
        MysteryShip mysteryship;
        float mysteryShipSpawnInterval;
        float timeLastSpawn;
        void CheckForCollisions();
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
};