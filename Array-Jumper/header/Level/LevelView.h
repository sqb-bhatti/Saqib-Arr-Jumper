#pragma once
#include <SFML/Graphics.hpp>
#include "LevelData.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Level
{
	class LevelView
	{
	private:
		
		const float bottom_offset = 200.f;
		const float box_spacing_percentage = 0.3f;
		const float background_alpha = 110.f;

		float box_width;
		float box_height;
		float box_spacing;


		sf::RenderWindow* game_window;

		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		UI::UIElement::ImageView* letter_one_image;
		UI::UIElement::ImageView* letter_two_image;
		UI::UIElement::ImageView* letter_three_image;
		UI::UIElement::ImageView* obstacle_one_image;
		UI::UIElement::ImageView* obstacle_two_image;

		LevelData current_level_data;

		void createImages();
		void updateImages();
		void initializeImages();
		void drawLevel();

		void calculateBoxExtents();
	public:
		LevelView();

		void initialize();
		void update();
		void render();
	};
}

