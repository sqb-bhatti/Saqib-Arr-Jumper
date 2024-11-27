//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_UIVIEW_H
#define PONG_UIVIEW_H


#include <SFML/Graphics.hpp>

namespace UI
{
    namespace UIElement
    {
        enum class UIState
        {
            VISIBLE,
            HIDDEN,
        };

        class UIView
        {
        protected:
            sf::RenderWindow* game_window;
            UIState ui_state;

        public:
            UIView();
            virtual ~UIView();

            virtual void initialize();
            virtual void update();
            virtual void render();

            virtual void show();
            virtual void hide();
        };
    }
}


#endif //PONG_UIVIEW_H
