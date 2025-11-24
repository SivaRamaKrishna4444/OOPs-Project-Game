#include "alien.hpp"

Texture2D Alien :: alienImages[3] = {};  //for the 3 types of aliens

Alien::Alien(int type, Vector2 position)  //type,position of alien
{
    this->type = type;
    this->position = position;

    if(alienImages[type-1].id == 0){

    switch(type){
        case 1:
            alienImages[0] = LoadTexture("images/alien_1.png");  //type 1
            break;
        case 2:
            alienImages[1] = LoadTexture("images/alien_2.png");  //type 2
            break;
        case 3:
            alienImages[2] = LoadTexture("images/alien_3.png");  //type 3
            break;
        default:
            alienImages[0] = LoadTexture("images/alien_1.png");  //type 1
            break;
    }
}
}

void Alien :: Draw(){
    DrawTextureV(alienImages[type-1],position,WHITE);   //draw the texture(image) 
}

int Alien :: GetType(){
    return type;  //give the type of alien(1 or 2 or 3)
}

void Alien::UnloadImages()
{
    for(int i = 0 ; i < 4 ; i++){
        UnloadTexture(alienImages[i]);   //unload texture(immage)  of all alien types
    }
}

Rectangle Alien::getRectangle()   //gives the rectangle position of aliens
{
    return {position.x,position.y,
        float(alienImages[type-1].width),
        float(alienImages[type - 1].height)
    };
}

void Alien :: Update(int direction){   //for the movement of alienss
    position.x += direction;   //adds the direction to position of x
}