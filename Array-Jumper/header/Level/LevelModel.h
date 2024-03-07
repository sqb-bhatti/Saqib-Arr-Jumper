#pragma once
#include "LevelData.h"

namespace Level
{
	class LevelModel
	{
	private:
		LevelData current_level_data;
		
	public:
		LevelData getCurrentLevelData();
	};
}

