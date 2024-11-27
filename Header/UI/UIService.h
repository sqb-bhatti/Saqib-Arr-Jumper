//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_UISERVICE_H
#define PONG_UISERVICE_H


#include <SFML/Graphics/RenderWindow.hpp>

#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Instructions/InstructionsUIController.h"
#include "../../Header/UI/Credits/CreditsScreenUIController.h"

namespace UI
{

    class UIService
    {
    private:
        SplashScreen::SplashScreenUIController* splash_screen_ui_controller;
        MainMenu::MainMenuUIController* main_menu_ui_controller;
        Credits::CreditsScreenUIController* credits_screen_ui_controller;
        Instructions::InstructionsUIController* instructions_ui_controller;


        void createControllers();
        void initializeUIElements();
        void initializeControllers();
        void onDestroy();

    public:
        UIService();
        ~UIService();

        void initialize();
        void update();
        void render();

        void showSplashScreen();
    };
}

#endif //PONG_UISERVICE_H
