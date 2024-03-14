#ifndef YUGIOH_CARD_POOL_HPP
#define YUGIOH_CARD_POOL_HPP
#include "../component/sprite.hpp"
#include <vector>
#include <cstddef>


namespace yu::card {

    typedef struct card_sprite {
        yu::Sprite sprite;
        int cardId;
    } card_sprite_t;
    
    std::filesystem::path getCardImagePath(int cardId);
 
    class CardSpritePool {

        private:            
            std::vector<yu::card::card_sprite_t> sprites;
            const std::size_t maxCards;
            const int zIndex;

        public:
            CardSpritePool(
                std::size_t maxCards,
                int zIndex
            );            
            void add(int cardId);
            std::vector<yu::card::card_sprite_t>* getCardList();
            std::size_t size() const;
            yu::card::card_sprite_t* getCardSpriteByIndex(std::size_t index);

    };

}

#endif