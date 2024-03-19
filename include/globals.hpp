#ifndef YUGIOH_GLOBALS_HPP
#define YUGIOH_GLOBALS_HPP
#include <SFML/System/Vector2.hpp>
#include <memory>
#include "util/card.hpp"


namespace yu::globals {

    inline sf::Vector2f mousePos;
    inline bool windowHasFocus = false;
    inline bool mouseIsClicked = false;
    inline std::map<std::string, std::unique_ptr<yu::Card>> cards;
}   


#endif