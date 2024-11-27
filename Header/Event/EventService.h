//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_EVENTSERVICE_H
#define PONG_EVENTSERVICE_H

#include <SFML/Graphics.hpp>


namespace Event
{
    enum class ButtonState
    {
        PRESSED,
        HELD,
        RELEASED,
    };

    class EventService
    {
    private:
        sf::Event game_event;
        sf::RenderWindow* game_window;

        ButtonState left_mouse_button_state;
        ButtonState right_mouse_button_state;
        ButtonState left_arrow_button_state;
        ButtonState right_arrow_button_state;
        ButtonState A_button_state;
        ButtonState D_button_state;
        ButtonState Space_buttonPressed;

        bool isGameWindowOpen();
        bool gameWindowWasClosed();
        bool hasQuitGame();
        bool isKeyboardEvent();
        void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
        void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);

    public:
        EventService();
        ~EventService();

        void initialize();
        void update();
        void processEvents();

        bool pressedEscapeKey();
        bool pressedLeftArrowKey();
        bool pressedRightArrowKey();
        bool pressedAKey();
        bool pressedDKey();
        bool pressedLeftMouseButton();
        bool pressedRightMouseButton();
        bool heldSpaceKey();
    };
}


#endif //PONG_EVENTSERVICE_H
