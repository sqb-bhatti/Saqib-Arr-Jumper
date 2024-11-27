//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_SOUNDSERVICE_H
#define PONG_SOUNDSERVICE_H

#include <SFML/Audio.hpp>


namespace Sound
{
    enum class SoundType
    {
        BUTTON_CLICK,
        MOVE,
        JUMP,
        DEATH,
        LEVEL_COMPLETE,
    };

    class SoundService
    {
    private:
        const int background_music_volume = 30;

        sf::Music background_music;
        sf::Sound sound_effect;
        sf::SoundBuffer buffer_button_click;
        sf::SoundBuffer buffer_move;
        sf::SoundBuffer buffer_jump;
        sf::SoundBuffer buffer_death;
        sf::SoundBuffer buffer_level_complete;

        void loadBackgroundMusicFromFile();
        void loadSoundFromFile();

    public:
        SoundService();

        void initialize();

        void playSound(SoundType soundType);
        void playBackgroundMusic();
    };
}

#endif //PONG_SOUNDSERVICE_H
