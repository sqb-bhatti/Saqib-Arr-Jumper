//
// Created by Saqib Bhatti on 28/11/24.
//

/*
 * We have multiple services, each handling a specific set of functionalities. Whenever a service wants to
 * communicate with another service, they use Service Locator.

This is the reason you need Player Service. Player also has to communicate with other classes and
 it’ll use Player Service for it.
 */


#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"


namespace Player {

    PlayerService::PlayerService() {
        player_controller = new PlayerController();
    }

    PlayerService::~PlayerService() {
        destroy();
    }

    void PlayerService::initialize() {
        player_controller->initialize();
    }

    void PlayerService::update() {
        player_controller->update();
    }

    void PlayerService::render() {
        player_controller->render();
    }

    void PlayerService::destroy() {
        delete (player_controller);
    }
}