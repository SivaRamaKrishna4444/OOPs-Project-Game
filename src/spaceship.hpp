#pragma once
#include <raylib.h>
#include "bulletuu.hpp"
#include<vector>

class Spaceship{
    private:
        Texture2D image;
        Vector2 position;
        double lastPushpatime;
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void Pushpa();
        std::vector<bulletuu> bullets;
};