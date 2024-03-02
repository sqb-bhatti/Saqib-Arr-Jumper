#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;

		PlayerController* player_controller;

		sf::Sprite player_sprite;
		sf::Texture player_texture;


		bool loadTexturesFromFile();
		void setPlayerSprite();

		void drawPlayer();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};	
}		

