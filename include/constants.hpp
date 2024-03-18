#ifndef SFML_TEMPLATE_CONSTANTS_HPP
#define SFML_TEMPLATE_CONSTANTS_HPP
#include "colors.hpp"
#include "util/box.hpp"
#include <SFML/System/Vector2.hpp>
#include <filesystem>


namespace yu::constants {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const yu::box_t WINDOW_BOX{
        { }, 
        {SCREEN_WIDTH, SCREEN_HEIGHT}
    };

    const char WINDOW_TITLE[] = "Yu-Gi-Oh!";
    const sf::Color WINDOW_BG_COLOR = yu::colors::GREY_200;
    const int FPS = 60;

    const std::filesystem::path cardsDir("assets/cards");
    const std::filesystem::path deckDir("db/decks");
    
}


#endif