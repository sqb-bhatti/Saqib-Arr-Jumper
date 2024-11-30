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

        BoxDimensions box_dimensions;
        UI::UIElement::ImageView* box_image;

        // Declaring Overlay Images
        UI::UIElement::ImageView* target_overlay_image;
        UI::UIElement::ImageView* letter_one_overlay_image;
        UI::UIElement::ImageView* letter_two_overlay_image;
        UI::UIElement::ImageView* letter_three_overlay_image;
        UI::UIElement::ImageView* obstacle_one_overlay_image;
        UI::UIElement::ImageView* obstacle_two_overlay_image;

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

        void calculateBoxDimensions();
        void calculateBoxWidthHeight();
        void calculateBoxSpacing();
        UI::UIElement::ImageView* getBoxOverlayImage(BlockType block_type);
        void drawBox(sf::Vector2f position);
        void drawBoxValue(sf::Vector2f position, BlockType box_value);
        sf::Vector2f calculateBoxPosition(int index);
    };
}

#endif //PONG_LEVELVIEW_H
