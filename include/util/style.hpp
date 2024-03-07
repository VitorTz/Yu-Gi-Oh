#ifndef YUGIOH_STYLE_HPP
#define YUGIOH_STYLE_HPP
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <cstddef>
#include "font.hpp"
#include "../colors.hpp"


namespace yu::style {


    typedef struct border_style {
        sf::Color color;
        std::size_t thickness;
    } border_style_t;

    typedef struct text_style {
        yu::FontId font;
        std::size_t size;
        sf::Color color;
    } text_style_t;

    typedef struct button_style {
        text_style_t text_style;
        sf::Color color;
        sf::Color onHoverColor;
        sf::Vector2f size;
        border_style_t border_style;
        std::filesystem::path icon_path;
    } button_style_t;

    const border_style_t NO_BORDER{sf::Color(0, 0, 0, 0), 0};
    const border_style_t WHITE_BORDER{sf::Color::White, 2};    


    text_style_t createHeaderTxt(const sf::Color color);
    text_style_t createNormalTxt(const sf::Color color);

    const button_style_t MENU_SCENE_CAMPAIGN_BTN{
        createNormalTxt(yu::colors::GREY_400),
        yu::colors::YELLOW_200,
        yu::colors::YELLOW_400,
        sf::Vector2f(230, 50),
        NO_BORDER,
        "assets/icons/campaign.png"
    };

}


#endif