#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;

	LevelView::LevelView()
	{
		game_window = nullptr;

		createImages();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		calculateBoxExtents();
		initializeImages();
	}

	void LevelView::update()
	{
		background_image->update();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	BoxDimentions LevelView::getBoxDimentions()
	{
		return box_dimentions;
	}

	void LevelView::createImages()
	{
		background_image = new ImageView();

		box_image = new ImageView();
		letter_one_image = new ImageView();
		letter_two_image = new ImageView();
		letter_three_image = new ImageView();
		obstacle_one_image = new ImageView();
		obstacle_two_image = new ImageView();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);

		
		box_image->initialize(Config::box_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_one_image->initialize(Config::letter_one_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_two_image->initialize(Config::letter_two_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_three_image->initialize(Config::letter_three_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		obstacle_one_image->initialize(Config::obstacle_01_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		obstacle_two_image->initialize(Config::obstacle_02_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
	}

	void LevelView::updateImages()
	{
		background_image->update();

		box_image->update();
		letter_one_image->update();
		letter_two_image->update();
		letter_three_image->update();
		obstacle_one_image->update();
		obstacle_two_image->update();
	}
	
	void LevelView::drawLevel()
	{
		background_image->render();

		for (int i = 0; i < LevelData::NUMBER_OF_BOXES; ++i)
		{
			// CalculateBoxPosition();

			/*float xPosition = box_dimentions.box_spacing + static_cast<float>(i) * (box_dimentions.box_width + box_dimentions.box_spacing);
			float yPosition = static_cast<float>(game_window->getSize().y) - box_dimentions.box_height - box_dimentions.bottom_offset;
			
			initializeBoxBacground();
			
			box_image->setPosition(sf::Vector2f(xPosition, yPosition));
			box_image->render();*/

			switch (current_level_data.level_boxes[i])
			{
				ImageView image;


			case BlockType::OBSTACLE_ONE:
				image = obstacle_one_image;
				/*obstacle_one_image->setPosition(sf::Vector2f(xPosition, yPosition));
				obstacle_one_image->render();*/
				break;

			case BlockType::OBSTACLE_TWO:
				obstacle_two_image->setPosition(sf::Vector2f(xPosition, yPosition));
				obstacle_two_image->render();
				break;

			case BlockType::ONE:
				letter_one_image->setPosition(sf::Vector2f(xPosition, yPosition));
				letter_one_image->render();
				break;

			case BlockType::TWO:
				letter_two_image->setPosition(sf::Vector2f(xPosition, yPosition));
				letter_two_image->render();
				break;

			case BlockType::THREE:
				letter_three_image->setPosition(sf::Vector2f(xPosition, yPosition));
				letter_three_image->render();
				break;

			case BlockType::TARGET:
				DrawTargetBox(Vector);
				/*sf::RectangleShape overlay(sf::Vector2f(box_dimentions.box_width, box_dimentions.box_height));
				overlay.setPosition(xPosition, yPosition);
				overlay.setFillColor(sf::Color(0, 191, 255, 90));
				game_window->draw(overlay);*/
				break;
			}

			/*setPosition();
			render();*/

		}
	}

	void LevelView::calculateBoxExtents() // Not readable. Add helper functions 
	{
		if (game_window)
		{
			float screenWidth = static_cast<float>(game_window->getSize().x);
			int numBoxes = LevelData::NUMBER_OF_BOXES;

			float totalBoxes = (numBoxes + box_dimentions.box_spacing_percentage * static_cast<float>(numBoxes + 1));

			box_dimentions.box_width = screenWidth / totalBoxes;
			box_dimentions.box_spacing = box_dimentions.box_spacing_percentage * box_dimentions.box_width;

			box_dimentions.box_height = box_dimentions.box_width;
		}
	}


}