#include "../../header/Level/LevelModel.h"

namespace Level
{

	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}
}

