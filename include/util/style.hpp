#pragma once
#include <SFML/Graphics/Color.hpp>
#include "font.hpp"


namespace yu::style {

    typedef struct color {
        sf::Color color;
        sf::Color accentColor;
    } color_t;

    typedef struct text {
        yu::FontId font;
        sf::Color color;
        std::size_t size;
    } text_t;
    
} // namespace yu::style
