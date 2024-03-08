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

	public:

		void intialize();
		void update();
		void render();

		void processPosition(int position);
	};
}

