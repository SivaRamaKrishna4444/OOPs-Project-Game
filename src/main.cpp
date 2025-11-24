#include "raylib.h"
#include "game.hpp"

int main()
{
    Color grey = {29,29,27,255};
    int window_width = 750;   //width of window
    int window_height = 700;   //height of window

    InitWindow(window_width,window_height,"Space Inavdersssuu");    //initalising windoowww
    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false)    //until we close that window or press Esc.. 
    {
        game.HandleInput();   //interactive with the input (like pressing left,right,space...)
        game.Update();  
        BeginDrawing();
        ClearBackground(grey);   //backgorund colour to be grey.. 
        game.Draw();     //draw the game(spaceship,shield,bullets..)
        EndDrawing();
    }

    CloseWindow();   //closing the window after pressing Esc or closing the windoww..
}