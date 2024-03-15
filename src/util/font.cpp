#include "../../include/util/font.hpp"



std::map<yu::FontId, std::unique_ptr<sf::Font>> yu::FontPool::fontMap;


void yu::FontPool::load(sf::Text* text, const yu::FontId fontId) {
    sf::Font* f = get(fontId);
    text->setFont(*f);
}


sf::Font* yu::FontPool::get(const yu::FontId fontId) {
    if (fontMap.find(fontId) == fontMap.end()) {
        const auto& [pair, s] = fontMap.insert(
            {
                fontId,
                std::make_unique<sf::Font>()
            }
        );        
        pair->second->loadFromFile(yu::fontPathMap.at(fontId));
    }
    return fontMap.at(fontId).get();
}


void yu::FontPool::erase(const yu::FontId fontId) {
    fontMap.erase(fontId);
}