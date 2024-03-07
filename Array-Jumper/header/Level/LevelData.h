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

    struct BoxDimentions
    {
        float box_width;
        float box_height;
        float box_spacing;

        float box_spacing_percentage = 0.3f;
        float bottom_offset = 200.f;
    };

    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        int level_boxes[NUMBER_OF_BOXES] = { ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET };
    };
}