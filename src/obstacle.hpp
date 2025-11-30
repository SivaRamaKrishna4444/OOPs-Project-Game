#pragma once
#include<vector>
#include "block.hpp"

class Obstacle{
    private:

    public:
        Obstacle(Vector2 position); //builds an obstacle at a given position
        void Draw(); //draw function to dsiplay all blocks of obstacles
        Vector2 position;
        std :: vector<Block> blocks; //store all small block pieces that makesup the obstacle
        static std :: vector<std::vector<int>> grid;//2d grid pattern for generating sield shape
};
