#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"

namespace Player
{
	using namespace Global;

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		if (loadTexturesFromFile())
			setPlayerSprite();
	}

	void PlayerView::update()
	{
		//Yet to implement
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		}
	}

	bool PlayerView::loadTexturesFromFile() { return player_texture.loadFromFile(Config::character_texture_path); }

	void PlayerView::setPlayerSprite() { player_sprite.setTexture(player_texture); }

	void PlayerView::drawPlayer()
	{
		player_sprite.setPosition(0, 0);
		game_window->draw(player_sprite);
	}
}