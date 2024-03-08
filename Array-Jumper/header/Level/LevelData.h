#pragma once

namespace Level
{
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        int level_boxes[NUMBER_OF_BOXES] = { ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET };
    };
}