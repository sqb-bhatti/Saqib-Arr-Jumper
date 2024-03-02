#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Level
{
	using namespace Global;

	LevelView::LevelView()
	{
		game_window = nullptr;
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		if (loadTexturesFromFile())
		{
			setBackgroundImage();
		}
	}

	void LevelView::render()
	{
		drawLevel();
	}

	bool LevelView::loadTexturesFromFile()
	{
		return background_texture.loadFromFile(Config::array_jumper_bg_texture_path);
	}

	void LevelView::setBackgroundImage()
	{
		setBackgroundSprite();
		scaleBackgroundImage();
	}
	void LevelView::setBackgroundSprite()
	{
		background_sprite.setTexture(background_texture);
		sf::Color color = background_sprite.getColor();
		color.a = background_alpha;
		background_sprite.setColor(color);
	}
	void LevelView::scaleBackgroundImage()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}
	void LevelView::drawLevel()
	{
		game_window->draw(background_sprite);
	}
}