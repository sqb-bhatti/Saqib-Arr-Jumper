//
// Created by Saqib Bhatti on 28/11/24.
//

#ifndef PONG_LEVELVIEW_H
#define PONG_LEVELVIEW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../UI/UIElement/ImageView.h"
#include "LevelController.h"


namespace Level {

    class LevelView {
    private:
        sf::RenderWindow* game_window;
        LevelController* level_controller;

        UI::UIElement::ImageView* background_image;
        const float background_alpha = 110.f;

        void createImages();
        void initializeImages();
        void updateImages();
        void drawLevel();
        void deleteImages();

    public:
        LevelView(LevelController* controller);
        ~LevelView();

        void initialize();
        void update();
        void render();
    };
}

#endif //PONG_LEVELVIEW_H
