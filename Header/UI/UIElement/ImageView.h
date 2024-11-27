//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_IMAGEVIEW_H
#define PONG_IMAGEVIEW_H


#include "../UIElement/UIView.h"
#include <SFML/Graphics.hpp>

namespace UI
{
    namespace UIElement
    {
        class ImageView : public UIView
        {
        protected:
            sf::Texture image_texture;
            sf::Sprite image_sprite;

        public:
            ImageView();
            virtual ~ImageView();

            virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
            virtual void update() override;
            virtual void render() override;

            virtual void setTexture(sf::String texture_path);
            virtual void setScale(float width, float height);
            virtual void setPosition(sf::Vector2f position);
            virtual void setRotation(float rotation_angle);
            virtual void setOriginAtCentre();
            virtual void setImageAlpha(float alpha);
            virtual void setCentreAlinged();
        };
    }
}


#endif //PONG_IMAGEVIEW_H
