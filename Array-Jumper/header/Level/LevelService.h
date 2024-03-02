#pragma once

namespace Level
{
	class LevelController;
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
	};
}

