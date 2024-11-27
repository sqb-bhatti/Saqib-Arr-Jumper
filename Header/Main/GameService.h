//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_GAMESERVICE_H
#define PONG_GAMESERVICE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{

    enum class GameState
    {
        BOOT,
        SPLASH_SCREEN,
        MAIN_MENU,
        GAMEPLAY,
        INSTRUCTIONS,
        CREDITS,
    };

    class GameService
    {
    private:

        static GameState current_state;
        Global::ServiceLocator* service_locator;
        sf::RenderWindow* game_window;

        void initialize();
        void showSplashScreen();

    public:
        GameService();
        virtual ~GameService();

        void ignite();
        void update();
        void render();
        bool isRunning();

        static void setGameState(GameState new_state);
        static GameState getGameState();
    };
}

#endif //PONG_GAMESERVICE_H
