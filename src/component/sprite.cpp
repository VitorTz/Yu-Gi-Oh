#include "../../include/component/sprite.hpp"


yu::TextureMap yu::Sprite::textureMap;


sf::Texture* yu::Sprite::textureCreate(
    const std::filesystem::path& file
) {
    if (textureMap.find(file) == textureMap.end()) {
        const auto& [p, s] = textureMap.insert(
            {
                file,
                std::make_unique<sf::Texture>()
            }
        );
        p->second->setSmooth(true);
        p->second->loadFromFile(file);
    }
    return textureMap.at(file).get();
}


void yu::Sprite::textureLoad(
    sf::Sprite* sprite, 
    const std::filesystem::path& file
) {
    sf::Texture* t = textureCreate(file);
    sprite->setTexture(*t);
}


void yu::Sprite::textureDestroy(
    const std::filesystem::path& file
) {
    textureMap.erase(file);
}


void yu::Sprite::textureClear() {
    textureMap.clear();
}


yu::Sprite::Sprite(
    const std::string& name,
    const std::filesystem::path& file,
    const int zIndex,
    const sf::Vector2f pos
) : yu::Component(name, zIndex, pos) {
    yu::Sprite::textureLoad(&sprite, file);
    size = (sf::Vector2f) sprite.getTexture()->getSize();
}


yu::Sprite::Sprite(    
    const std::filesystem::path& file,
    const int zIndex,
    const sf::Vector2f pos
) : yu::Sprite(file.string(), file, zIndex, pos) {
    
}


void yu::Sprite::draw(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    sprite.setScale(scale);
    sprite.setRotation(rotation);
    window.draw(sprite);
}


const std::filesystem::path& yu::Sprite::getFile() const {
    return file;
}
