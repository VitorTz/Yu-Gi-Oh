#include "../../include/util/card_sprite_pool.hpp"


yu::CardSpritePool::CardSpritePool(
    const std::size_t maxSize
) : maxSize(maxSize) {

}


void yu::CardSpritePool::add(
    const std::filesystem::path& file
) {
    if (files.size() + 1 >= maxSize) {
        yu::Sprite::textureDestroy(files.front());
        files.erase(files.begin());
    }
    files.push_back(file);
    yu::Sprite::textureCreate(file);
}

const std::filesystem::path& yu::CardSpritePool::get(
    const std::size_t i
) const {
    return files[i];
}

std::size_t yu::CardSpritePool::getMaxSize() const {
    return maxSize;
}


std::size_t yu::CardSpritePool::size() const {
    return files.size();
}