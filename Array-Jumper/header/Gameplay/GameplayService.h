#pragma once
#include "GameplayController.h"

namespace Gameplay
{
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

		void destroy();

	public:
		GameplayService();
		~GameplayService();

		void intialize();
		void update();
		void render();

		void processPosition(int position);
	};
}

