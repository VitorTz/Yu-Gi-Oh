#include "../../include/component/icon_button.hpp"


yu::IconButton::IconButton(
    const std::string& name,
    const std::filesystem::path& iconFile,
    const yu::VoidFunc& func,
    const sf::Vector2f pos,
    int zIndex
) : yu::Button(name, func, pos, zIndex),
    icon(iconFile, zIndex, pos) {
    this->size = icon.getSize();
}


void yu::IconButton::handleMouseEntry() {
    yu::Button::handleMouseEntry();
    scale.x *= 1.2f;
    scale.y *= 1.2f;
}


void yu::IconButton::handleMouseExit() {
    yu::Button::handleMouseExit();
    scale.x /= 1.2f;
    scale.y /= 1.2f;
}


void yu::IconButton::draw(sf::RenderWindow& window) {
    icon.setPos(pos);
    icon.setRotation(rotation);
    icon.setScale(scale);
    icon.draw(window);
}