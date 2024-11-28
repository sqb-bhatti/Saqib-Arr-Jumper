//
// Created by Saqib Bhatti on 27/11/24.
//
#include "../../Header/Main/GameService.h"

namespace Main
{
    using namespace Graphics;
    using namespace UI;
    using namespace Sound;
    using namespace Global;

    GameState GameService::current_state = GameState::BOOT;

    GameService::GameService()
    {
        game_window = nullptr;
        service_locator = nullptr;
    }

    GameService::~GameService() {}

    void GameService::ignite()
    {
        service_locator = ServiceLocator::getInstance();
        initialize();
        showSplashScreen();
    }

    void GameService::initialize()
    {
        service_locator->initialize();
        game_window = service_locator->getGraphicService()->getGameWindow();
    }

    void GameService::showSplashScreen()
    {
        setGameState(GameState::SPLASH_SCREEN);
        service_locator->getUIService()->showSplashScreen();
    }

    // Main Game Loop.
    void GameService::update()
    {
        // Process Events.
        service_locator->getEventService()->processEvents();

        // Update Game Logic.
        service_locator->update();
    }

    void GameService::render()
    {
        game_window->clear();
        service_locator->render();
        game_window->display();
    }

    bool GameService::isRunning() { return service_locator->getGraphicService()->isGameWindowOpen(); }

    void GameService::setGameState(GameState new_state) { current_state = new_state; }

    GameState GameService::getGameState() { return current_state; }
}