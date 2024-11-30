//
// Created by Saqib Bhatti on 27/11/24.
//

#include "../../Header/Player/PlayerView.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"


using namespace UI::UIElement;


namespace Player {
    using namespace Global;
    using namespace Level;
    using namespace UI::UIElement;

    PlayerView::PlayerView(PlayerController* controller) {
        game_window = nullptr;
        player_image = new ImageView();
        player_controller = controller;
    }

    PlayerView::~PlayerView() {

    }

    void PlayerView::initialize() {
        game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        loadPlayer();
    }

    void PlayerView::update() {
        updatePlayerPosition();
    }

    void PlayerView::render() {
       switch(player_controller->getPlayerState()) {
           case PlayerState::ALIVE:
               drawPlayer();
               break;
       }
    }

    void PlayerView::calculatePlayerDimensions() {
        current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
        player_height = current_box_dimensions.box_height;
        player_width = current_box_dimensions.box_width;
    }

    void PlayerView::initializePlayerImage() {
        player_image->initialize(Global::Config::character_texture_path, player_width,
                                player_height, sf::Vector2f(0, 0));
    }

    void PlayerView::loadPlayer() {
        calculatePlayerDimensions();
        initializePlayerImage();
    }

    sf::Vector2f PlayerView::calulcatePlayerPosition() {
        float xPosition = current_box_dimensions.box_spacing +
                static_cast<float>(player_controller->getCurrentPosition()) *
                        (current_box_dimensions.box_width + current_box_dimensions.box_spacing);


        float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height -
                current_box_dimensions.bottom_offset - player_height;

        return sf::Vector2f(xPosition, yPosition);
    }

    void PlayerView::updatePlayerPosition() {
        player_image->setPosition(calulcatePlayerPosition());
    }

    void PlayerView::drawPlayer() {
        player_image->render();
    }
}