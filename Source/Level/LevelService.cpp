//
// Created by Saqib Bhatti on 28/11/24.
//


#include "../../Header/Level/LevelService.h"
#include "../../Header/Level/LevelController.h"


namespace Level {

    LevelService::LevelService() {
        level_controller = new LevelController();
    }

    LevelService::~LevelService() {
        destroy();
    }

    void LevelService::initialize() {
        level_controller->initialize();
    }

    void LevelService::update() {
        level_controller->update();
    }

    void LevelService::render() {
        level_controller->render();
    }

    void LevelService::destroy() {
        delete (level_controller);
    }
}