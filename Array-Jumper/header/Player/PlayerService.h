#pragma once
#include "../../header/Player/PlayerController.h"

namespace Player
{
	//class PlayerService
	class PlayerController;
	class PlayerService
	{
	private:
		PlayerController* player_controller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
	};
}