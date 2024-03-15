#include "../../include/component/text.hpp"


yu::Text::Text(
    const std::string& name,
    const std::string& str,
    const sf::Vector2f pos,
    const yu::style::text_style_t& style,
    const int zIndex
) : yu::Component(name, pos, zIndex),
    str(str),
    style(style) {
    yu::FontPool::load(&text, style.fontId);
    text.setString(str);
    text.setFillColor(style.color);
    text.setCharacterSize(style.size);
    sf::FloatRect r = text.getLocalBounds();
    size = {r.width, r.height};    
}


void yu::Text::draw(sf::RenderWindow& window) {
    text.setPosition(
        {
            std::roundf(pos.x),
            std::roundf(pos.y)
        }
    );
    window.draw(text);
}


void yu::Text::setPos(const sf::Vector2f p) {
    pos.x = p.x;
    pos.y = p.y -5.f;
}


void yu::Text::setTop(const float t) {
    pos.y = t -5.f;
}


void yu::Text::setBottom(const float b) {
    pos.y = b - size.y - 5.f;
}


void yu::Text::setCenter(const sf::Vector2f c) {
    setCenterX(c.x);
    pos.y = c.y - size.y / 2 - 5.f;
}


void yu::Text::setCenterY(const float y) {
    pos.y = y - size.y / 2 - 5.f;
}