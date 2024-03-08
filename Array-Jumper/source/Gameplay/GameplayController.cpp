#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Sound/SoundService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Level;
	using namespace Sound;

	void GameplayController::intialize()
	{//Yet to Implement
	}

	void GameplayController::update()
	{//Yet to Implement
	}

	void GameplayController::render()
	{//Yet to Implement
	}

	void GameplayController::processPosition(int position)
	{
		int value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();
		if (isEndBlock(position))
			processEndBlock();
	}



	bool GameplayController::isObstacle(int value)
	{
		if (value == -1 || value == -2)
			return true;
		return false;
	}

	bool GameplayController::isEndBlock(int position)
	{
		if (position == LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	void GameplayController::processEndBlock()
	{
	}
}