//
// Created by Saqib Bhatti on 28/11/24.
//

#ifndef PONG_LEVELCONTROLLER_H
#define PONG_LEVELCONTROLLER_H

#include "LevelModel.h"


namespace Level {
    class LevelView;
    class LevelModel;

    class LevelController {
    private:
        LevelModel* level_model;
        LevelView* level_view;

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();

        BlockType getCurrentBoxValue(int currentPosition);
        BoxDimensions getBoxDimensions();
    };
}

#endif //PONG_LEVELCONTROLLER_H
