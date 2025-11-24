#pragma once
#include <raylib.h>

class bulletuu{
    private:
        Vector2 position;
        int speed;
    public:
        bulletuu(Vector2 position,int speed);
        void update();
        void draw();
        Rectangle getRectangle();
        
        bool active;    // if bullet is inside the window or not..
};