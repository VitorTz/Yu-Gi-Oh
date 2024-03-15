#include "../../include/component/text_btn.hpp"



yu::TextBtn::TextBtn(
    const std::string& name,
    const std::string& text,
    const yu::VoidFunction& func,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const int zIndex,
    const yu::style::color_style_t& color,
    const yu::style::text_style_t& text_style,
    const yu::style::border_t& border
) : yu::Button(name, func, zIndex),
    text("text", text, { }, text_style, zIndex),
    rect("rect", pos, size, zIndex, color, border) {    
    this->pos = pos;
    this->size = size;    
}


void yu::TextBtn::update(const double dt) {
    yu::Button::update(dt);
    this->rect.update(dt);
}

void yu::TextBtn::draw(sf::RenderWindow& window) {
    this->rect.setPos(pos);
    this->rect.setSize(size);
    text.setCenter(center());
    this->rect.draw(window);
    this->text.draw(window);    
}

