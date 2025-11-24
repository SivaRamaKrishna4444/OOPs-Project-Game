#pragma once
#include<raylib.h>

class Alien{
    private:

    public:
        Alien(int type,Vector2 position);  //constructor for alien
        void Update(int direction);  //to move the aliens from left<->right
        void Draw();  // to draw the aliens on screen
        int GetType();  //gives the type of aliennn
        static void UnloadImages();  //for unloading the alien images
        static Texture2D alienImages[3];  //for 3 types of aliens
        int type;  //type of alien
        Vector2 position;  //position of alien
        Rectangle getRectangle();   //to get the rectangle of the alien image
};