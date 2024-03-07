#include "../../include/component/image.hpp"


yu::Image::Image(
    const std::filesystem::path& path,
    const sf::Vector2f pos = {0.f, 0.f},
    const int zIndex = 0
) : yu::Image("[image]-[" + path.string() + ']', path, pos, zIndex) {
    
}


yu::Image::Image(
    const std::string& name,
    const std::filesystem::path& path_,
    const sf::Vector2f pos = {0.f, 0.f},
    const int zIndex = 0
) : yu::Component(name, zIndex, pos),
    path(path_) {
    change_image(path);
}


yu::Image::Image(
    const std::string& name,
    const int zIndex
) : yu::Component(name, zIndex, {0.f, 0.f}) {
    
}


yu::Image::~Image() {    
    yu::TexturePool::erase(path);
}


void yu::Image::draw(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    sprite.setScale(scale);
    window.draw(sprite);
}


void yu::Image::change_image(const std::filesystem::path& image_file) {
    yu::TexturePool::erase(this->path);
    yu::TexturePool::load(&sprite, image_file);
    size = (sf::Vector2f) sprite.getTexture()->getSize();
    this->path = image_file;
}


const sf::Vector2f& yu::Image::getScale() const {
    return scale;
}


void yu::Image::setScale(const sf::Vector2f s) {
    scale = s;
}


void yu::Image::resize(const float x, const float y) {
    const float dx = x / size.x;
    const float dy = y / size.y;
    size.x *= dx;
    size.y *= dy;
    scale = {dx, dy};    
}


void yu::Image::resize(const sf::Vector2f s) {
    resize(s.x, s.y);
}
