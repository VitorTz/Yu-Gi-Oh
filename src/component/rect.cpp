#include "../../include/component/rect.hpp"


yu::Rect::Rect(
    const std::string& name,
    const sf::Vector2f pos, 
    const sf::Vector2f size,
    const int zIndex,
    const sf::Color color,
    const yu::style::border_style_t& border_style
) : yu::Component(name, zIndex, pos, size),
    color(color),
    border_style(border_style) {
    
}


void yu::Rect::draw(sf::RenderWindow& window) {
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setFillColor(color);
    window.draw(rect);    
    drawBorder(border_style, window);    
}