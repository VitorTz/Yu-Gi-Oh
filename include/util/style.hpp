#pragma once
#include <SFML/Graphics/Color.hpp>
#include "../colors.hpp"
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

    const yu::style::color_t COLOR_STYLE_1{
        yu::colors::YELLOW_200,
        yu::colors::YELLOW_600
    };

    const yu::style::text_t NORMAL_TXT_STYLE{
        yu::FontId::Regular,
        yu::colors::GREY_200,
        16
    };
    
} // namespace yu::style
