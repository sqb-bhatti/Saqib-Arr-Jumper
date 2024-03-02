#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"

namespace Level
{
	Level::LevelController::LevelController()
	{
		level_view = new LevelView();
	}

	Level::LevelController::~LevelController() {}

	void Level::LevelController::initialize()
	{
		level_view->initialize();
	}

	void Level::LevelController::update()
	{
	}

	void Level::LevelController::render()
	{
		level_view->render();
	}

}