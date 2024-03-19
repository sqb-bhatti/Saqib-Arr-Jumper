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

		void gameOver();

	public:

		void intialize();
		void update();
		void render();

		void onPositionChanged(int position);
		void onDeath();
	};
}

