//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef ARRAY_JUMPER_PLAYERMODEL_H
#define ARRAY_JUMPER_PLAYERMODEL_H


namespace Player {
    enum class PlayerState {
        ALIVE,
        DEAD
    };

    class PlayerModel {
    private:
        PlayerState player_state;
        int current_position;

    public:
        void initialize();
        PlayerState getPlayerState();
        void setPlayerState(PlayerState new_player_state);

        int getCurrentPosition();
        void setCurrentPosition(int new_position);
    };
}

#endif //ARRAY_JUMPER_PLAYERMODEL_H
