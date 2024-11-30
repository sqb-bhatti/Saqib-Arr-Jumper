//
// Created by Saqib Bhatti on 28/11/24.
//


#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"


namespace Player {

    PlayerController::PlayerController() {
        player_model = new PlayerModel();
        player_view = new PlayerView(this);  // passed the reference of the controller into the view
    }

    PlayerController::~PlayerController() {
        destroy();
    }

    void PlayerController::initialize() {
        player_model->initialize();
        player_view->initialize();
    }

    void PlayerController::update() {
        player_view->update();
    }

    void PlayerController::render() {
        player_view->render();
    }

    PlayerState PlayerController::getPlayerState() {
        return player_model->getPlayerState();
    }

    int PlayerController::getCurrentPosition() {
        return player_model->getCurrentPosition();
    }

    void PlayerController::setPlayerState(PlayerState new_player_state) {
        player_model->setPlayerState(new_player_state);
    }

    void PlayerController::destroy() {
        delete(player_model);
        delete(player_view);
    }
}