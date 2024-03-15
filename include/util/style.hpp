#ifndef YUGIOH_STYLE_HPP
#define YUGIOH_STYLE_HPP
#include <SFML/Graphics/Color.hpp>
#include "../colors.hpp"
#include "../util/font.hpp"
#include <cstddef>



namespace yu::style {


    typedef struct border {
        sf::Color color = sf::Color::Black;
        std::size_t thickness = 0u;
    } border_t;

    typedef struct color_style {
        sf::Color normalColor;
        sf::Color accentColor;        
        color_style(const sf::Color color) {
            normalColor = color;
            accentColor = color;
        }        
        color_style(const sf::Color color, const sf::Color color1) {
            normalColor = color;
            accentColor = color1;
        }        
    } color_style_t;

    typedef struct text_style {
        yu::FontId fontId;
        sf::Color color;
        std::size_t size;
    } text_style_t;

    const text_style_t NORMAL_TXT{
        yu::FontId::Regular, 
        yu::colors::GREY_400, 
        16
    };

    const color_style_t MAIN_COLOR_STYLE{
        yu::colors::YELLOW_200, 
        yu::colors::YELLOW_400
    };
    
    const border_t MAIN_BORDER_STYLE{
        yu::colors::YELLOW_600,
        1
    };

    const border_t NO_BORDER{};

}


#endif