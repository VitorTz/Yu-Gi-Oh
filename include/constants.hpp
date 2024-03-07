#ifndef SFML_TEMPLATE_CONSTANTS_HPP
#define SFML_TEMPLATE_CONSTANTS_HPP
#include "colors.hpp"
#include "util/box.hpp"
#include <filesystem>


namespace yu::constants {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_CENTER_X = SCREEN_WIDTH / 2;
    const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;
    const char WINDOW_TITLE[] = "Yu-Gi-Oh Forbidden Memories";
    const sf::Color WINDOW_BG_COLOR = yu::colors::GREY_200;
    const int FPS = 60;
    const yu::Box WINDOW_BOX({ }, {SCREEN_WIDTH, SCREEN_HEIGHT});

    const std::filesystem::path ASSETS_PATH("assets");
    const std::filesystem::path MENU_MONSTERS("assets/Monster");
    
}


#endif