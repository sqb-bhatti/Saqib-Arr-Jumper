//
// Created by Saqib Bhatti on 28/11/24.
//

#ifndef PONG_PLAYERSERVICE_H
#define PONG_PLAYERSERVICE_H



namespace Player {
    class PlayerController;

    class PlayerService {
    private:
        PlayerController* player_controller;
        void destroy();

    public:
        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();
    };


}

#endif //PONG_PLAYERSERVICE_H
