#include "../../include/component/rect.hpp"


yu::Rect::Rect(
    const std::string& name,
    int zIndex,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const sf::Color color                
) : yu::Component(name, zIndex, pos, size),
    color(yu::style::color_t{color, color}) {

}


yu::Rect::Rect(
    const std::string& name,
    int zIndex,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const yu::style::color_t& color
) : yu::Component(name, zIndex, pos, size),
    color(color) {

    }


yu::Rect::Rect(
    const std::string& name,
    int zIndex,
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const sf::Color color,
    const sf::Color accentColor
) : yu::Component(name, zIndex, pos, size),
    color(yu::style::color_t{color, accentColor}) {

}


void yu::Rect::draw(sf::RenderWindow& window) {
    rect.setPosition(pos);
    rect.setScale(scale);
    rect.setRotation(rotation);
    rect.setSize(size);
    rect.setFillColor(hovered ? color.accentColor : color.color);
    window.draw(rect);
}


const yu::style::color_t& yu::Rect::getColorStyle() const {
    return color;
}


void yu::Rect::setColorStyle(const yu::style::color_t& style) {
    color = style;
    rect.setFillColor(hovered ? color.accentColor : color.color);
}