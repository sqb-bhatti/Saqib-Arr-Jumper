#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Main/GameService.h"

namespace Level
{

	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView(this);
	}

	LevelController::~LevelController() { delete(level_view); delete(level_model); }

	void LevelController::initialize()
	{
		level_view->initialize();
		printf("Current Index: %d\n", level_model->getCurrentBoxValue(1));
	}

	void LevelController::update()
	{
		//Yet to implement
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BoxDimentions LevelController::getBoxDimentions()
	{
		return level_view->getBoxDimentions();
	}

	int LevelController::getCurrentBoxValue(int currentPosition)
	{
		/*printf("Current Index: %d\n", level_model->getCurrentBoxValue(3));

		return level_model->getCurrentBoxValue(currentPosition);*/
		return level_model->current_level_index;
	}

	bool LevelController::isLastLevel()
	{
		return level_model->isLastLevel();
	}

	void LevelController::loadNextLevel()
	{
		level_model->loadNextLevel();
	}

}