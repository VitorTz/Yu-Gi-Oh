#include "../../include/component/text.hpp"


yu::FontMap yu::Text::fontMap;

sf::Font* yu::Text::fontCreate(const yu::FontId font) {
    if (fontMap.find(font) == fontMap.end()) {
        const auto& [p, s] = fontMap.insert(
            {
                font,
                std::make_unique<sf::Font>()
            }
        );
        p->second->loadFromFile(yu::fontPathById.at(font));
    }
    return fontMap.at(font).get();
}


void yu::Text::fontLoad(sf::Text* text, const yu::FontId font) {
    sf::Font* f = fontCreate(font);
    text->setFont(*f);
}


void yu::Text::fontDestroy(const yu::FontId font) {
    fontMap.erase(font);
}


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
    this->setTextStyle(style);
    this->setStr(str);
}


void yu::Text::draw(sf::RenderWindow& window) {
    pos.y -= 5.f;    
    text.setPosition({std::roundf(pos.x), std::roundf(pos.y)});
    text.setRotation(rotation);
    text.setScale(scale);
    window.draw(text);
    pos.y += 5.f;
}


const yu::style::text_t& yu::Text::getTextStyle() const {
    return style;
}


void yu::Text::setTextStyle(const yu::style::text_t& style) {
    this->style = style;
    yu::Text::fontLoad(&text, style.font);
    this->text.setCharacterSize(style.size);
    this->text.setFillColor(style.color);
}


void yu::Text::setColor(const sf::Color color) {
    style.color = color;
    text.setFillColor(color);
}


std::size_t yu::Text::getStrSize() const {
    return str.size();
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


void yu::Text::shrink(const float width) {
    if (size.x > width) {        
        str += "...";
        while (size.x > width) {
            setStr(str.substr(0, str.size() - 4) + "...");
        }        
    }    
}