#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Main/GameService.h"

namespace Level
{

	LevelController::LevelController()
	{
		level_view = new LevelView();
		level_model = new LevelModel();
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->initialize();
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
		return level_model->getCurrentBoxValue(currentPosition);
	}

}