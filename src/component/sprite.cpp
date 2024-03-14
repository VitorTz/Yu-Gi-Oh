#include "../../include/component/sprite.hpp"


yu::Sprite::Sprite(
    const std::string& name, 
    const std::filesystem::path& path,
    const sf::Vector2f pos,
    int zIndex
) : yu::Component(name, pos, zIndex) {
    yu::TexturePool::load(&sprite, path);
    size = (sf::Vector2f) sprite.getTexture()->getSize();
    
}


yu::Sprite::Sprite(
    const std::filesystem::path& path,
    const sf::Vector2f pos,
    int zIndex
) : yu::Sprite(path.string(), path, pos, zIndex) {

}


yu::Sprite::Sprite(
    const std::filesystem::path& path,    
    int zIndex
) : yu::Sprite(path.string(), path, sf::Vector2f(), zIndex) {

}


void yu::Sprite::resize(const sf::Vector2f s) {
    const float dx = s.x / size.x;
    const float dy = s.y / size.y;
    size.x *= dx;
    size.y *= dy;
    scale = {dx, dy};
}


void yu::Sprite::resize(const float w, const float h) {
    yu::printVector(size);
    const float dx = w / size.x;
    const float dy = h / size.y;
    size.x *= dx;
    size.y *= dy;
    yu::printVector(size);
    scale = {dx, dy};
}


void yu::Sprite::draw(sf::RenderWindow& window) {
    const sf::Vector2f origin = {size.x / 2, size.y / 2};
    sprite.setOrigin(origin);
    sprite.setPosition(pos + origin);
    sprite.setScale(scale);
    sprite.setRotation(rotation);
    window.draw(sprite);
    sprite.setOrigin(pos);
}