#ifndef YUGIOH_STYLE_HPP
#define YUGIOH_STYLE_HPP
#include <SFML/Graphics/Color.hpp>
#include "../colors.hpp"
#include <cstddef>



namespace yu::style {


    typedef struct border {
        sf::Color color = sf::Color::Black;
        std::size_t thickness = 0u;
    } border_t;

    typedef struct color_style {
        sf::Color normalColor;
        sf::Color accentColor;        
    } color_style_t;


}


#endif