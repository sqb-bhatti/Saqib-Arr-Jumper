#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"



namespace Player
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		player_image = new ImageView();
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		loadPlayer();
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

	void PlayerView::loadPlayer()
	{
		current_box_dimentions = ServiceLocator::getInstance()->getLevelService()->getBoxDimentions();

		player_height = current_box_dimentions.box_height;
		
		initializePlayerImage();
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path,
			current_box_dimentions.box_width,
			player_height,
			sf::Vector2f(0, 0));
	}

	void PlayerView::drawPlayer()
	{
		float xPosition = current_box_dimentions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimentions.box_width + current_box_dimentions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimentions.box_height - current_box_dimentions.bottom_offset - player_height;

		player_image->setPosition(sf::Vector2f(xPosition, yPosition));
		player_image->render();
	}

}