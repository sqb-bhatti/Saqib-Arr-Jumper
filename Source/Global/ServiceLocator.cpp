//
// Created by Saqib Bhatti on 27/11/24.
//
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Event/EventService.h"

namespace Global
{
    using namespace Graphics;
    using namespace Event;
    using namespace Sound;
    using namespace UI;
    using namespace Main;
    using namespace Player;

    ServiceLocator::ServiceLocator()
    {
        graphic_service = nullptr;
        event_service = nullptr;
        sound_service = nullptr;
        ui_service = nullptr;
        player_service = nullptr;

        createServices();
    }

    ServiceLocator::~ServiceLocator() { clearAllServices(); }

    void ServiceLocator::createServices()
    {
        graphic_service = new GraphicService();
        event_service = new EventService();
        sound_service = new SoundService();
        ui_service = new UIService();
        player_service = new PlayerService();
    }

    void ServiceLocator::initialize()
    {
        graphic_service->initialize();
        event_service->initialize();
        sound_service->initialize();
        ui_service->initialize();
        player_service->initialize();
    }

    void ServiceLocator::update()
    {
        graphic_service->update();
        event_service->update();
        ui_service->update();

        if(GameService::getGameState() == Main::GameState::GAMEPLAY) {
            player_service->update();
        }
    }

    void ServiceLocator::render()
    {
        graphic_service->render();
        ui_service->render();

        if(GameService::getGameState() == Main::GameState::GAMEPLAY) {
            player_service->render();
        }
    }

    void ServiceLocator::clearAllServices()
    {
        delete(graphic_service);
        delete(event_service);
        delete(sound_service);
        delete(ui_service);
        delete(player_service);
    }

    ServiceLocator* ServiceLocator::getInstance()
    {
        static ServiceLocator instance;
        return &instance;
    }

    GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

    EventService* ServiceLocator::getEventService() { return event_service; }

    SoundService* ServiceLocator::getSoundService() { return sound_service; }

    UIService* ServiceLocator::getUIService() { return ui_service; }

    PlayerService* ServiceLocator::getPlayerService() { return player_service; }
}