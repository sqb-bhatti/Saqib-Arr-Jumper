//
// Created by Saqib Bhatti on 28/11/24.
//

#ifndef PONG_LEVELSERVICE_H
#define PONG_LEVELSERVICE_H


#include "LevelModel.h"

namespace Level {
    class LevelController;

    class LevelService {
    private:
        LevelController* level_controller;
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        BoxDimensions getBoxDimensions();
    };
}

#endif //PONG_LEVELSERVICE_H