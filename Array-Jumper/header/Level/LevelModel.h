#pragma once
#include "LevelData.h"

namespace Level
{
    // Each level should be represented as a array of integers
    //     -1   : Obstacle 1
    //     -2   : Obstacle 2
    //      0   : End block
    //  1,2,3   : Numbers

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

	class LevelModel
	{
	private:
		LevelData current_level_data;
		
	public:
		LevelData getCurrentLevelData();
	};
}

