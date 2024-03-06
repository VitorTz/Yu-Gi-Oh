#include "../../include/util/texture_pool.hpp"


std::mutex yu::TexturePool::m;
yu::TextureMap yu::TexturePool::texture_map;


sf::Texture* yu::TexturePool::get(const std::filesystem::path &path) {
    m.lock();
    if (texture_map.find(path) == texture_map.end()) {
        const auto& [pair, success] = texture_map.insert(
            {path, std::make_unique<sf::Texture>()}
        ); 
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);
        std::cout << "[TEXTURE LOAD] [" << path << "]\n";
    }
    m.unlock();
    return texture_map.at(path).get();
}


void yu::TexturePool::load(sf::Sprite *sprite, const std::filesystem::path &path) {
    sprite->setTexture(*get(path));
}


void yu::TexturePool::erase(const std::filesystem::path &path) {
    if (texture_map.find(path) != texture_map.end()) {
        texture_map.erase(path);
        std::cout << "[TEXTURE UNLOAD] [" << path << "]\n";
    }
}