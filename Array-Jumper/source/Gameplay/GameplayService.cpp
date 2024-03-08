#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService() { gameplay_controller = new GameplayController(); }
	GameplayService::~GameplayService() { destroy(); }

	void GameplayService::intialize() { gameplay_controller->intialize(); }
	void GameplayService::update() { gameplay_controller->update(); }
	void GameplayService::render() { gameplay_controller->render(); }

	void GameplayService::processPosition(int position) { gameplay_controller->processPosition(position); }

	void GameplayService::destroy() { delete(gameplay_controller); }
}
