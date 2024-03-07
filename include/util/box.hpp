#ifndef YUGIOH_BOX_HPP
#define YUGIOH_BOX_HPP
#include <SFML/System/Vector2.hpp>


namespace yu {


    class Box {

        public:
            sf::Vector2f pos;
            sf::Vector2f size;

        public:            
            Box(
                const sf::Vector2f pos,
                const sf::Vector2f size
            ) : pos(pos), size(size) { }
        
            float left() const { return pos.x; }
            float top() const { return pos.y; }
            float right() const { return pos.x + size.x; }
            float bottom() const { return pos.y + size.y; }

            float width() const { return size.x; }
            float height() const { return size.y; }

            float centerX() const { return pos.x + size.x / 2; }
            float centerY() const { return pos.y + size.y / 2; }
            sf::Vector2f center() const  { 
                return {
                    pos.x + size.x / 2,
                    pos.y + size.y / 2
                };
            }
        
    };

}


#endif