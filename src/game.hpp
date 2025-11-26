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
        void GameOver();   //if the game is over (lives = 0)
        void Reset();   //to reset the entire game 
        void InitGame();  //to initialise the game
        void CheckForHighScore();  //check for high scoruuu
        void SaveHighScoreToFile(int highScore); //to save the high score eeven if we close the game
        int loadHighScorefromFile(); //it will take the highscore saved and load from file
        Sound explosionSound;   //for explosion sound
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        int lives;   //gives lives = 3;
        void HandleInput();
        bool run;   //if the game is running or not
        int score; //for score 
        int highScore; //for highscore in game
        Music music;  //for music(bgm)
};