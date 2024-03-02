#pragma once

// Each level should be represented as a array of integers
    //     -1   : Obstacle 1
    //     -2   : Obstacle 2
    //      0   : End block
    //  1,2,3   : Numbers

namespace Level
{
    enum BlockType
    {
        OBSTACLE_ONE = -1,
        OBSTACLE_TWO = -2,
        TARGET = 0,
        ONE = 1,
        TWO = 2,
        THREE = 3,
    };

    struct LevelData
    {
        static const int NUMBER_OF_BLOCKS = 10;
        static const int NUMBER_OF_LEVELS = 3;

        int level1[NUMBER_OF_BLOCKS] = { ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET };
        int level2[NUMBER_OF_BLOCKS] = { ONE, TWO, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, THREE, OBSTACLE_ONE, ONE, TARGET };
        int level3[NUMBER_OF_BLOCKS] = { ONE, THREE, OBSTACLE_ONE, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, TWO, ONE, TARGET };
    };
}