//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_TEXTVIEW_H
#define PONG_TEXTVIEW_H


#include "../UIElement/UIView.h"
#include <SFML/Graphics.hpp>

namespace UI
{
    namespace UIElement
    {
        enum class FontType
        {
            BUBBLE_BOBBLE,
            ZORQUE,
        };

        class TextView : public UIView
        {
        private:
            static const int default_font_size = 55;

            static sf::Font font_bubble_bobble;
            static sf::Font font_zorque;

            sf::Text text;

            static void loadFont();

            void setFont(FontType font_type);
            void setFontSize(int font_size);
            void setTextPosition(sf::Vector2f position);
            void setTextColor(sf::Color color);

        public:
            TextView();
            virtual ~TextView();

            static void initializeTextView();

            virtual void initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::ZORQUE, int font_size = default_font_size, sf::Color color = sf::Color::White);
            virtual void update() override;
            virtual void render() override;

            void setText(sf::String text_value);
            void setTextCentreAligned();
        };
    }
}


#endif //PONG_TEXTVIEW_H
