#pragma once
#include "LevelModel.h"
#include "LevelData.h"
#include "LevelController.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Level
{
	class LevelView
	{
	private:
		
		const float background_alpha = 110.f;

		BoxDimentions box_dimentions;

		sf::RenderWindow* game_window;
		LevelController* level_controller;

		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		LevelData current_level_data;

		void createImages();
		void updateImages();
		void initializeImages();
		void drawLevel();
		void deleteImages();

		void calculateBoxDimentions();
		sf::Vector2f calculateBoxPosition(int index);
		void calculateBoxWidthHeight();
		void calculateBoxSpacing();
		UI::UIElement::ImageView* getBoxOverlayImage(int index);
	public:
		LevelView();
		~LevelView();

		void initialize();
		void update();
		void render();

		BoxDimentions getBoxDimentions();

	};
}

