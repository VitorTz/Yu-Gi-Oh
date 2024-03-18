#pragma once
#include <SFML/System/Vector2.hpp>


namespace yu {

    typedef struct box {
        sf::Vector2f pos;
        sf::Vector2f size;
        float left() const {
            return pos.x;
        }
        float top() const {
            return pos.y;
        }
        float right() const {
            return pos.x + size.x;
        }
        float bottom() const {
            return pos.y + size.y;
        }
        float width() const {
            return size.x;
        }
        float height() const {
            return size.y;
        }
    } box_t;
    
} // namespace yu
