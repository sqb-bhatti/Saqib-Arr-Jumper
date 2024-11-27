


#include "Header/Main/GameService.h"

int main()
{
    using namespace Main;

    GameService* game_service = new GameService();
    game_service->ignite(); //Creates all services. Hence, calls the CONSTRUCTOR and triggers INITIALIZE for all services

    while (game_service->isRunning())
    {
        game_service->update();  //Triggers UPDATE for all services
        game_service->render();  //Triggers RENDER for all services
    }

    delete(game_service);  //Deletes all services. Hence calls the DESTRUCTOR for all services
    return 0;
}