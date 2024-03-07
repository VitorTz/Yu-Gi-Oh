#include "../../include/util/style.hpp"

 
yu::style::text_style_t yu::style::createHeaderTxt(const sf::Color color) {
    yu::style::text_style_t s{yu::FontId::Bold, 22, color};
    return s;
}


yu::style::text_style_t yu::style::createNormalTxt(const sf::Color color) {
    yu::style::text_style_t s{yu::FontId::Regular, 16, color};
    return s;
}

