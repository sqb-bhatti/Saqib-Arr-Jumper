#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelData LevelModel::getCurrentLevelData()
	{
		return current_level_data;
	}

	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}
}

