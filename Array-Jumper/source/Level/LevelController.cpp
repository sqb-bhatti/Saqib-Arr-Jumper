#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Main/GameService.h"

namespace Level
{

	LevelController::LevelController()
	{
		level_view = new LevelView();
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
	}

	void LevelController::render()
	{
		level_view->render();
	}

}