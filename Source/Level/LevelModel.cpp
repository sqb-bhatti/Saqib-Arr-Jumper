//
// Created by Saqib Bhatti on 28/11/24.
//


#include "../../Header/Level/LevelModel.h"


namespace Level {

    LevelModel::LevelModel() {}
    LevelModel::~LevelModel() {}

    BlockType LevelModel::getCurrentBoxValue(int currentPosition) {
        return current_level_data.level_boxes[currentPosition];
    }
}