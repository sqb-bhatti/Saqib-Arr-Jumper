#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;

	LevelView::LevelView()
	{
		game_window = nullptr;

		createImages();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackgroundImage();
	}

	void LevelView::update()
	{
		background_image->update();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::createImages()
	{
		background_image = new ImageView();
	}

	void LevelView::initializeBackgroundImage()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
	}
	
	
	void LevelView::drawLevel()
	{
		background_image->render();
	}

	void LevelView::calculateBoxExtents()
	{
		if (game_window)
		{
			float screenWidth = static_cast<float>(game_window->getSize().x);
			int numBoxes = LevelData::NUMBER_OF_BLOCKS;

			float totalBoxes = (numBoxes + box_spacing_percentage * static_cast<float>(numBoxes + 1));

			box_width = screenWidth / totalBoxes;
			box_spacing = box_spacing_percentage * box_width;

			box_height = box_width;
		}
	}
}