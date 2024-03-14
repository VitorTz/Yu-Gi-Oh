#ifndef YUGIOH_CARD_POOL_HPP
#define YUGIOH_CARD_POOL_HPP
#include "../component/sprite.hpp"
#include <vector>
#include <cstddef>


namespace yu {

    typedef struct card_sprite {
        yu::Sprite sprite;
        int cardId;
    } card_sprite_t;
 
    class CardSpritePool {

        private:
            std::vector<yu::Sprite> sprite;
            const std::size_t maxCards;

        public:
            CardSpritePool(std::size_t maxCards);

    };

}

#endif