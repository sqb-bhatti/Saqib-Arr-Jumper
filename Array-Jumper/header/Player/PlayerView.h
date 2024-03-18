#pragma once
#include "../../header/Level/LevelModel.h"
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;

		PlayerController* player_controller;

		UI::UIElement::ImageView* player_image;

		float player_height;
		Level::BoxDimentions current_box_dimentions;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		sf::Vector2f calulcatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();

	};	
}		

