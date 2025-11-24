#pragma once
#include <raylib.h>

class MysteryShip{
    private:
        Vector2 position;
        Texture2D image;
        int speed;
    public:
        MysteryShip();
        ~MysteryShip();
        void Update();
        void Draw();
        void Spawn();   //to achieve that only one mysteryship is created and it hides from time to time
        Rectangle getRectangle();   //to get the rectangle of the mysteryship image
        bool alive;
};