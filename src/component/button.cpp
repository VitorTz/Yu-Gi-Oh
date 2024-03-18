#include "../../include/component/button.hpp"


yu::Button::Button(
    const std::string& name,
    const yu::VoidFunc& func,
    const sf::Vector2f pos,
    const int zIndex
) : yu::Component(name, zIndex, pos),
    func(func) {

}


void yu::Button::handleClick() {
    func();
}


void yu::Button::handleMouseEntry() {

}
