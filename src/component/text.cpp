#include "../../include/component/text.hpp"


yu::Text::Text(
    const std::string& name,
    const std::string& str,
    const yu::style::text_t& style,
    const sf::Vector2f pos,
    int zIndex
) : yu::Component(name, zIndex, pos),
    str(str),
    style(style) {
    yu::Text::fontLoad(&this->text, style.font);
}


void yu::Text::draw(sf::RenderWindow& window) {
    pos.y -= 5.f;
    text.setPosition(pos);
    text.setRotation(rotation);
    text.setScale(scale);
    window.draw(text);
    pos.y += 5.f;
}


const std::string& yu::Text::getStr() const {
    return str;
}


void yu::Text::setStr(const std::string& str) {
    this->str = str;
    this->text.setString(str);
    sf::FloatRect r = this->text.getLocalBounds();
    this->size = {r.width, r.height};
    this->setCenter(center());
}


const yu::style::text_t& yu::Text::getTextStyle() const {
    return style;
}


void yu::Text::setTextStyle(const yu::style::text_t& style) {
    this->style = style;
    yu::Text::fontLoad(&text, style.font);
    this->text.setCharacterSize(style.size);
}