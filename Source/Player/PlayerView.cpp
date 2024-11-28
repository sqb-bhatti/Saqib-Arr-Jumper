//
// Created by Saqib Bhatti on 27/11/24.
//

#include "../../Header/Player/PlayerView.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

using namespace UI::UIElement;


namespace Player {

    PlayerView::PlayerView(PlayerController* controller) {
        game_window = nullptr;
        player_image = new ImageView();
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

    }

    void PlayerView::calculatePlayerDimensions() {
        player_width = 1000.f;
        player_height = 1000.f;
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
        return sf::Vector2f(0,0);
    }

    void PlayerView::updatePlayerPosition() {
        player_image->setPosition(calulcatePlayerPosition());
    }

    void PlayerView::drawPlayer() {
        player_image->render();
    }
}