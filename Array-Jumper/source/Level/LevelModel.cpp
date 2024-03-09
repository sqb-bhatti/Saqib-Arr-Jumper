#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelConfiguration.h"

namespace Level
{
	LevelModel::LevelModel()
	{
		current_level_index = -1;
		printf("Level_Model Created\n");
	}
	LevelModel::~LevelModel()
	{
		printf("Destroyed");
	}

	int LevelModel::getCurrentBoxValue(int currentPosition)
	{
		printf("Level: %d \n", current_level_index);
		return level_configuration.levels[current_level_index].level_boxes[currentPosition];
		//return current_level_data.level_boxes[currentPosition];
	}

	bool LevelModel::isLastLevel()
	{
		if(current_level_index == LevelConfiguration::NUMBER_OF_LEVELS-1)
			return true;
		return false;
	}

	void LevelModel::loadNextLevel()
	{
		current_level_index++;
		printf("Load Next Level\n");
	}
}

