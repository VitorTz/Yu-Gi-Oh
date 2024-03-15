#include "../../include/util/card.hpp"


std::filesystem::path yu::card::getCardImagePath(const int cardId) {
    const std::string cardIdStr = std::to_string(cardId);
    std::filesystem::path path = yu::constants::cardsDir + '/' + cardIdStr[0] + cardIdStr + ".jpg";
    return path;
}   


yu::card::CardSpritePool::CardSpritePool(
    const std::size_t maxCards,
    const int zIndex
) : maxCards(maxCards),
    zIndex(zIndex) {

}


void yu::card::CardSpritePool::add(const int cardId) {
    if (sprites.size() >= maxCards) {
        std::cout << "CardSpritePool max size reached!\n";
        sprites.erase(sprites.begin());
    }
    std::filesystem::path cardImage = yu::card::getCardImagePath(cardId);   
    yu::card::card_sprite_t sprite{
        yu::Sprite(cardImage, zIndex),
        cardId
    };
    sprites.push_back(
        {
            yu::Sprite(cardImage, zIndex),
            cardId
        }
    );
}


yu::card::card_sprite_t* yu::card::CardSpritePool::getCardSpriteById(const std::size_t id) {
    return &sprites[id];
}


std::size_t yu::card::CardSpritePool::size() const {
    return sprites.size();
}