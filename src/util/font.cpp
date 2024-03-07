#include "../../include/util/font.hpp"


std::map<yu::FontId, std::unique_ptr<sf::Font>> yu::FontPool::fontMap;

void yu::FontPool::load(sf::Text* text, const yu::FontId fontId) {
    if (fontMap.find(fontId) == fontMap.end()) {
        const auto& [p, s] = fontMap.insert({fontId, std::make_unique<sf::Font>()});
        p->second->loadFromFile(fontPathMap.at(fontId));
    }
    sf::Font* font = get(fontId);
    text->setFont(*font);
}


sf::Font* yu::FontPool::get(const yu::FontId fontId) {
    if (fontMap.find(fontId) == fontMap.end()) {
        const auto& [p, s] = fontMap.insert({fontId, std::make_unique<sf::Font>()});
        p->second->loadFromFile(fontPathMap.at(fontId));
    }
    return fontMap.at(fontId).get();
}


void yu::FontPool::erase(const yu::FontId fontId) {
    fontMap.erase(fontId);
}