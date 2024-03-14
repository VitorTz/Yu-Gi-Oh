#include "../../include/util/texture_pool.hpp"


yu::TextureMap yu::TexturePool::texture_map;
std::mutex yu::TexturePool::m;


void yu::TexturePool::load(sf::Sprite* sprite, const std::filesystem::path& path) {
    sprite->setTexture(*yu::TexturePool::create(path));
}


sf::Texture* yu::TexturePool::create(const std::filesystem::path& path) {
    m.lock();
    if (texture_map.find(path) == texture_map.end()) {
        const auto& [pair, s] = texture_map.insert(
            {
                path,
                std::make_unique<sf::Texture>()
            }
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);
        std::cout << "[TEXTURE LOAD] [" << path << "]\n";
    }
    m.unlock();
    return texture_map.at(path).get();
}


void yu::TexturePool::destroy(const std::filesystem::path& path) {
    if (texture_map.find(path) != texture_map.end()) {
        texture_map.erase(path);
        std::cout << "[TEXTURE UNLOAD] [" << path << "]\n";
    }
}


void yu::TexturePool::clear() {
    texture_map.clear();
}