cmake_minimum_required(VERSION 3.28)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pong main.cpp
        Header/Event/EventService.h
        Header/Global/Config.h
        Header/Global/ServiceLocator.h
        Header/Graphics/GraphicService.h
        Header/Main/GameService.h
        Header/Sound/SoundService.h
        Header/UI/Instructions/InstructionsUIController.h
        Header/UI/MainMenu/MainMenuUIController.h
        Header/UI/SplashScreen/SplashScreenUIController.h
        Header/UI/UIElement/AnimatedImageView.h
        Header/UI/UIElement/ButtonView.h
        Header/UI/UIElement/ImageView.h
        Header/UI/UIElement/TextView.h
        Header/UI/UIElement/UIView.h
        Header/UI/UIService.h
        Source/Event/EventService.cpp
        Source/Global/Config.cpp
        Source/Global/ServiceLocator.cpp
        Source/Graphics/GraphicService.cpp
        Source/Main/GameService.cpp
        Source/Sound/SoundService.cpp
        Source/UI/Credits/CreditsScreenUIController.cpp
        Source/UI/Instructions/InstructionsUIController.cpp
        Source/UI/MainMenu/MainMenuUIController.cpp
        Source/UI/SplashScreen/SplashScreenUIController.cpp
        Source/UI/UIElement/AnimatedImageView.cpp
        Source/UI/UIElement/ButtonView.cpp
        Source/UI/UIElement/ImageView.cpp
        Source/UI/UIElement/TextView.cpp
        Source/UI/UIElement/UIView.cpp
        Source/UI/UIService.cpp
        Header/UI/Credits/CreditsScreenUIController.h
        Header/Player/PlayerModel.h
        Source/Player/PlayerModel.cpp
        Header/Player/PlayerView.h
        Source/Player/PlayerView.cpp
        Header/Player/PlayerController.h
        Source/Player/PlayerController.cpp
        Header/Player/PlayerService.h
        Source/Player/PlayerService.cpp
        Header/Level/LevelModel.h
        Header/Level/LevelView.h
        Header/Level/LevelController.h
        Source/Level/LevelModel.cpp
        Source/Level/LevelView.cpp
        Source/Level/LevelController.cpp
        Header/Level/LevelService.h
        Source/Level/LevelService.cpp)

#add_executable(Pong ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Pong sfml-system sfml-window sfml-graphics sfml-audio sfml-network)