#ifndef SFML_TEMPLATE_CONSTANTS_HPP
#define SFML_TEMPLATE_CONSTANTS_HPP
#include "colors.hpp"
#include <string>
#include "util/box.hpp"


namespace yu::constants {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_CENTER_X = SCREEN_WIDTH / 2;
    const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;
    const yu::box_t WINDOW_BOX{
        { }, 
        {SCREEN_WIDTH, SCREEN_HEIGHT}
    };
    const char WINDOW_TITLE[] = "Yu-Gi-Oh!";
    const sf::Color WINDOW_BG_COLOR = yu::colors::GREY_200;
    const int FPS = 60;

    const std::string cardsDir("assets/cards");
    
}


#endif