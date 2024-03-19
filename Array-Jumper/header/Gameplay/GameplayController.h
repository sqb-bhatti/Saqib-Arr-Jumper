#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:

		bool isObstacle(int value);
		bool isEndBlock(int value);
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

