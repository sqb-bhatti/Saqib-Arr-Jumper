#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Sound/SoundService.h"



namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Level;
	using namespace Sound;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController() { destroy(); }

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();

		event_service = ServiceLocator::getInstance()->getEventService();

		resetPlayer();
	}

	void PlayerController::update()
	{
		player_view->update();
		readInput();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->getCurrentPosition();
	}


	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::resetPlayer()
	{
		player_model->setCurrentPosition(0);
		player_model->setPlayerState(PlayerState::ALIVE);
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
				jumpForward();
			else
				moveForward();
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
				jumpBackward();
			else
				moveBackward();
		}

	}

	void PlayerController::moveForward()
	{
		if (player_model->getCurrentPosition() + 1 < LevelData::NUMBER_OF_BOXES)
		{
			int newPostion = player_model->getCurrentPosition() + 1;
			player_model->setCurrentPosition(newPostion);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
		}
	}

	void PlayerController::moveBackward()
	{
		if (player_model->getCurrentPosition() - 1 >= 0)
		{
			int newPostion = player_model->getCurrentPosition() - 1;
			player_model->setCurrentPosition(newPostion);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
		}
	}

	void PlayerController::jumpForward()
	{
		int current_position = player_model->getCurrentPosition();
		int value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(current_position);


		if (current_position + value < LevelData::NUMBER_OF_BOXES)
		{
			int newPostion = current_position + value;
			player_model->setCurrentPosition(newPostion);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
		}
	}

	void PlayerController::jumpBackward()
	{
		int current_position = player_model->getCurrentPosition();
		int value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(current_position);

		if (current_position - value >= 0)
		{
			int newPostion = current_position - value;
			player_model->setCurrentPosition(newPostion);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
		}
	}




}