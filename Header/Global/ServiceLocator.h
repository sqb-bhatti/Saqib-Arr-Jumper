//
// Created by Saqib Bhatti on 27/11/24.
//

#ifndef PONG_SERVICELOCATOR_H
#define PONG_SERVICELOCATOR_H


#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../UI/UIService.h"
#include "../Sound/SoundService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
    };
}

#endif //PONG_SERVICELOCATOR_H
