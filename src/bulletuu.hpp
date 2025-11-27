#pragma once
#include <raylib.h>

class bulletuu{
    private:
        Vector2 position;//to determine where is the bullet beam on the screen 
        int speed;//to determine how fast it moves on y axis
    public:
        bulletuu(Vector2 position,int speed);//constructor for setting position and speed 
        void update();//update the postion of the laser beam
        void draw();//to draw the bullet on the screen
        Rectangle getRectangle();
        
        bool active;    // if bullet is inside the window or not..
};
