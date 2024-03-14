#include "../../include/component/rect.hpp"


yu::Rect::Rect(
    const std::string& name,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    int zIndex,
    const yu::style::color_style_t& color,
    const yu::style::border_t& border   
) : yu::Component(name, pos, zIndex),
    color(color),
    border(border) {
    this->size = size;    
}


void yu::Rect::update(const double dt) {
    yu::Component::update(dt);
    rect.setFillColor(hovered ? color.accentColor : color.normalColor);        
}

void yu::Rect::draw(sf::RenderWindow& window) {
    rect.setSize(size);
    rect.setPosition(pos);
    rect.setRotation(rotation);
    rect.setScale(scale);
    window.draw(rect);
}