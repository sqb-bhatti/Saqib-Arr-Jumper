#pragma once
#include <SFML/Graphics.hpp>

namespace Level
{
	class LevelView
	{
	private:
		
		const float background_alpha = 110.f;


		sf::RenderWindow* game_window;

		sf::Texture background_texture;
		sf::Sprite background_sprite;

		bool loadTexturesFromFile();
		void setBackgroundImage();
		void setBackgroundSprite();
		void scaleBackgroundImage();
		void drawLevel();
	public:
		LevelView();

		void initialize();
		void render();
	};
}

