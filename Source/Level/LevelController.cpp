//
// Created by Saqib Bhatti on 28/11/24.
//

#include "../../Header/Level/LevelController.h"
#include "../../Header/Level/LevelView.h"

namespace Level {

    LevelController::LevelController() {
        level_model = new LevelModel();
        level_view = new LevelView(this);
    }

    LevelController::~LevelController() {

    }

    void LevelController::initialize() {
        level_view->initialize();
    }

    void LevelController::update() {
        level_view->update();
    }

    void LevelController::render() {
        level_view->render();
    }
}