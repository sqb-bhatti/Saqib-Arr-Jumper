//
// Created by Saqib Bhatti on 29/11/24.
//

#ifndef PONG_LEVELDATA_H
#define PONG_LEVELDATA_H


#include "BlockType.h"


namespace Level {

    struct LevelData {
        static const int number_of_boxes = 10;
        BlockType level_boxes[number_of_boxes] = {ONE,
                                                  TWO,
                                                  OBSTACLE_ONE,
                                                  TWO,
                                                  THREE,
                                                  ONE,
                                                  OBSTACLE_TWO,
                                                  TWO,
                                                  ONE,
                                                  TARGET};
    };
}

#endif //PONG_LEVELDATA_H
