#pragma once
#include "../../header/Event/EventService.h"

namespace Player
{

	enum MovementDirection
	{
		FORWARD,
		BACKWARD
	};

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

		void readInput();
		void move(MovementDirection direction);
		void moveBackward();
		void jump(MovementDirection direction);
		void jumpBackward();
		bool isPositionInBound(int targetPosition);

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();

		void resetPlayer();
		void takeDamage();
	};
}
