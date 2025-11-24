#pragma once
#include <raylib.h>
#include "bulletuu.hpp"
#include<vector>

class Spaceship{
    private:
        Texture2D image;   //for image of spaceship
        Vector2 position;   // for the posiiton of spaceship
        double lastPushpatime;   //it wilpl give last fire time
    public: 
        Spaceship();  //coonstructor 
        ~Spaceship();   //destructor
        void Draw();   //to draw spaceship 
        void MoveLeft();   //to move the spaceeship left
        void MoveRight();   //to move spaceship right
        void Pushpa();   // to fire (Pushpa->Firuuuuu)
        std::vector<bulletuu> bullets;
};