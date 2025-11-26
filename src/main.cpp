#include <raylib.h>
#include "game.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number,int width){  //for formating the score with leading zeros 
    std::string numberText = std::to_string(number);
    int leadingZeroes = width - numberText.length();   //5 digit long with with remaining digits as zeroes
    return numberText = std::string(leadingZeroes,'0')+numberText;
}

int main()
{
    Color grey = {29,29,27,255};
    Color yellow = {243,216,63,255};
    int offset = 50;
    int window_width = 750;   //width of window
    int window_height = 700;   //height of window

    InitWindow(window_width + offset,window_height + 2*offset,"Space Inavdersssuu");    //initalising windoowww
    
    Font font = LoadFontEx("Font/monogram.tff",64,0,0); //loading the font for text 
    Texture2D spaceshipImage = LoadTexture("images/spaceship.png");  //spaceship image for showing no.of lives remaining

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false)    //until we close that window or press Esc.. 
    {
        game.HandleInput();   //interactive with the input (like pressing left,right,space...)
        game.Update();  
        BeginDrawing();
        ClearBackground(grey);   //backgorund colour to be grey.. 
        DrawRectangleRoundedLinesEx({10,10,780,780},0.18f,20,2,yellow);
        DrawLineEx({25,730},{775,730},3,yellow);  //line below the spaceshipppu

        if(game.run){
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);   //font,text,position,fontsize,spacing,colour
        } else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);    //game over text if gameover(lives ==0)
        }
        float x = 50.0; 
        for(int i = 0; i < game.lives; i ++) {    //gives the spaceship image for no.of lives times
            DrawTextureV(spaceshipImage, {x, 745}, WHITE);
            x += 50;  //with 50 pixels spacing for each one
        }

        DrawTextEx(font,"SCORE",{50,15},34,2,yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score,5);  //format the gamscore with 5 digits of width
        DrawTextEx(font,scoreText.c_str(),{50,40},34,2,yellow);  //c_str will convert the string into const char*(c-style string)

        // DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, yellow);
        // std::string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
        // DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, yellow);

        game.Draw();     //draw the game(spaceship,shield,bullets..)
        EndDrawing();
    }

    CloseWindow();   //closing the window after pressing Esc or closing the windoww..
}