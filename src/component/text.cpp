#include "../../include/component/text.hpp"
#include <SFML/System/Vector2.hpp>


yu::Text::Text(
    const std::string& name,
    const std::string& txt,
    const int zIndex,
    const sf::Vector2f pos,
    const yu::style::text_style_t& style    
) : yu::Component(name, zIndex, pos) {
    yu::FontPool::load(&text, style.font);
    text.setCharacterSize(style.size);
    text.setString(txt);
    text.setFillColor(style.color);
    const sf::FloatRect fRect = text.getLocalBounds();
    size = {fRect.width, fRect.height};
}


void yu::Text::setCenter(const sf::Vector2f center) {
    pos.x = center.x - size.x / 2;
    pos.y = center.y - size.y / 2 - 4.f;
}


void yu::Text::draw(sf::RenderWindow& window) {
    sf::Vector2f p = {std::roundf(pos.x), std::roundf(pos.y)};
    text.setPosition(p);
    window.draw(text);
}