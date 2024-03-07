#include "../../include/component/image_button.hpp"


yu::ImageButton::ImageButton(
    const std::string& name,
    const sf::Vector2f pos,
    const yu::VoidFunction& func,
    const std::string& button_text,
    const yu::style::button_style_t& style,
    int zIndex
) : yu::Button(name, pos, func, zIndex, style),
    image(style.icon_path, pos, zIndex),
    text("BtnTxt", button_text, zIndex, pos, style.text_style) {
    size = style.size;    
    background.setSize(style.size);
}


void yu::ImageButton::draw(sf::RenderWindow& window) {
    on_hover() ? background.setFillColor(style.onHoverColor) : background.setFillColor(style.color);
    image.setCenterY(centerY());
    image.setRight(right() - 14.f);
    background.setPosition(pos);
    window.draw(background);
    drawBorder(style.border_style, window);
    text.setCenter(center());
    text.draw(window);
    image.draw(window);
}