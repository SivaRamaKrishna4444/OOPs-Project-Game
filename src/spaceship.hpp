#pragma once
#include <raylib.h>
#include "bulletuu.hpp"
#include<vector>

class Spaceship{
    private:
        Texture2D image;   //for image of spaceship
        Vector2 position;   // for the posiiton of spaceship
        double lastPushpatime;   //it wilpl give last fire time
        Sound bulletSound;  //for bulletSOund
    public: 
        Spaceship();  //constructor 
        ~Spaceship();   //destructor
        void Draw();   //to draw spaceship 
        void MoveLeft();   //to move the spaceeship left
        void MoveRight();   //to move spaceship right
        void Pushpa();   // to fire (Pushpa->Firuuuuu)
        Rectangle getRectangle();   //to get the rectangle of the spaceship image
        void Reset();  //to reset the positon of spaceship
        std::vector<bulletuu> bullets;
};
