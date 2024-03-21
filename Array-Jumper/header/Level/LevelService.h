#pragma once
#include "../../header/Level/BlockType.h"


namespace Level
{
	class LevelController;
	struct BoxDimentions;
	
	class LevelService
	{
	private:
		LevelController* level_controller;

	public:
		LevelService();
		~LevelService();

		void intialize();
		void update();
		void render();

		BoxDimentions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);
		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();

		void resetLevels();
	};
}

