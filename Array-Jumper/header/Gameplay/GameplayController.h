#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:

		bool isObstacle(BlockType value);
		bool isEndBlock(int position);
		void processObstacle();
		void processEndBlock();

		bool isLastLevel();
		void loadNextLevel();
		void gameWon();
		void gameOver();

	public:

		void intialize();
		void update();
		void render();

		void startGame();
		void onPositionChanged(int position);
		void onDeath();
	};
}

