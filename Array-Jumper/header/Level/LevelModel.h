#pragma once
#include "LevelData.h"
#include "LevelConfiguration.h"

namespace Level
{

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
		const int number_of_level = LevelConfiguration::NUMBER_OF_LEVELS;
		LevelConfiguration level_configuration;
		
	public:
		int current_level_index;
		LevelModel();
		~LevelModel();

		int getCurrentBoxValue(int currentPosition);

		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();

		void reset();
	};
}

