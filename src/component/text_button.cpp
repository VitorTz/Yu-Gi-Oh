#include "../../include/component/text_button.hpp"


yu::TextButton::TextButton(
    const std::string& name,
    const std::string& text,
    const yu::VoidFunc& func,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const int zIndex,
    const yu::style::text_t& text_style,
    const yu::style::color_t& color_style
) : yu::Button(name, func, pos, zIndex),
    rect("rect", zIndex, pos, size, color_style),
    text("text", text, text_style, pos, zIndex),
    text_style(text_style),
    color_style(color_style) {
    this->size = size;
    this->pos = pos;
}

const yu::style::text_t& yu::TextButton::getTextStyle() const {
    return text_style;
}


void yu::TextButton::setTextStyle(const yu::style::text_t& style) {
    text.setTextStyle(style);
    text_style = style;
}


const yu::style::color_t& yu::TextButton::getColorStyle() const {
    return color_style;
}


void yu::TextButton::setColorStyle(const yu::style::color_t& style) {
    rect.setColorStyle(style);
    color_style = style;
}

void yu::TextButton::update(const double dt) {
    yu::Button::update(dt);
    rect.update(dt);
}


void yu::TextButton::draw(sf::RenderWindow& window) {
    rect.setPos(pos);
    rect.setSize(size);
    rect.setScale(scale);
    rect.setRotation(rotation);
    text.setCenter(rect.center());
    rect.draw(window);
    text.draw(window);
}