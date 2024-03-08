#pragma once
#include "../../header/Event/EventService.h"

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		
		Event::EventService* event_service;

		void destroy();
		void resetPlayer();

		void readInput();
		void moveForward();
		void moveBackward();
		void jumpForward();
		void jumpBackward();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
	};
}
