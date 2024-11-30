//
// Created by Saqib Bhatti on 28/11/24.
//

#ifndef PONG_PLAYERCONTROLLER_H
#define PONG_PLAYERCONTROLLER_H



namespace Player {
    class PlayerView;
    class PlayerModel;
    enum class PlayerState;

    class PlayerController {
    private:
        PlayerModel* player_model;
        PlayerView* player_view;

        void destroy();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        PlayerState getPlayerState();
        void setPlayerState(PlayerState new_player_state);
        int getCurrentPosition();
    };
}

#endif //PONG_PLAYERCONTROLLER_H
