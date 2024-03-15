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
    this->rect.setFillColor(color.normalColor);
    this->size = size;    
}


void yu::Rect::handleMouseEntry() { 
    rect.setFillColor(color.accentColor);
}

void yu::Rect::handleMouseExit()  { 
    rect.setFillColor(color.normalColor);
}


void yu::Rect::drawBorder(sf::RenderWindow& window) {
    if (border.thickness == 0u) {
        return;
    }

    const float t = border.thickness;
    const sf::Color oldColor = rect.getFillColor();
    
    rect.setFillColor(border.color);

    rect.setSize({size.x, t});
    window.draw(rect);
    
    rect.setPosition({pos.x, pos.y + size.y - t});
    window.draw(rect);

    rect.setSize({t, size.y});
    rect.setPosition(pos);
    window.draw(rect);

    rect.setPosition({pos.x + size.x - t, pos.y});
    rect.setSize({t, size.y});
    window.draw(rect);
    
    rect.setFillColor(oldColor);
}   

void yu::Rect::draw(sf::RenderWindow& window) {
    rect.setSize(size);
    rect.setPosition(pos);
    rect.setRotation(rotation);
    rect.setScale(scale);
    window.draw(rect);
    drawBorder(window);
}