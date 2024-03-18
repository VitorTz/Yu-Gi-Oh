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


yu::Sprite::Sprite(    
    const std::string& name,
    const int zIndex
) : yu::Component(name, zIndex) {
    
}


void yu::Sprite::draw(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    sprite.setScale(scale);
    sprite.setRotation(rotation);
    if (rotation != 0) {
        sprite.setOrigin({size.x / 2, size.y / 2});        
    }
    window.draw(sprite);
    sprite.setOrigin({ });
}


const std::filesystem::path& yu::Sprite::getFile() const {
    return file;
}


void yu::Sprite::changeTexture(
    const std::filesystem::path& file
) {
    this->file = file;
    yu::Sprite::textureLoad(&sprite, file);
    size = (sf::Vector2f) sprite.getTexture()->getSize();
    setCenter(center());
}


void yu::Sprite::deleteTexture() {
    yu::Sprite::textureDestroy(file);
}


void yu::Sprite::resize(const sf::Vector2f newSize) {
    const float dx = newSize.x / size.x;
    const float dy = newSize.y / size.y;
    scale = {dx, dy};
    size.x *= dx;
    size.y *= dy;
}


void yu::Sprite::resize(const float width, const float height) {
    const float dx = width / size.x;
    const float dy = height / size.y;
    scale = {dx, dy};
    size.x *= dx;
    size.y *= dy;
}