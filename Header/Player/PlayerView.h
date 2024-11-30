//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_PLAYERVIEW_H
#define PONG_PLAYERVIEW_H

#include "../../Header/UI/UIElement/ImageView.h"
#include "PlayerController.h"
#include "../Level/LevelModel.h"


namespace Player {
    class PlayerView {
    private:
        sf::RenderWindow* game_window;
        UI::UIElement::ImageView* player_image;
        PlayerController* player_controller;
        Level::BoxDimensions current_box_dimensions;

        float player_height;
        float player_width;

        void initializePlayerImage(); //Initialize player_image
        void drawPlayer(); //Called every frame to render the sprite on the screen
        void loadPlayer(); //Loads the information needed to render the player
        void calculatePlayerDimensions(); //Calculate the size of image
        void updatePlayerPosition(); //Updates the Player Sprite's position on each frame
        sf::Vector2f calulcatePlayerPosition();

    public:
        PlayerView(PlayerController* player_controller);
        ~PlayerView();
        void initialize();
        void update();
        void render();

    };
}

#endif //PONG_PLAYERVIEW_H
