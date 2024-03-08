#pragma once
#include "LevelData.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Level
{
	class LevelView
	{
	private:
		
		const float background_alpha = 110.f; // ?? Model

		BoxDimentions box_dimentions;

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

		BoxDimentions getBoxDimentions();
		
	};
}

