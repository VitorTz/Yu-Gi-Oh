#ifndef YUGIOH_BOX_HPP
#define YUGIOH_BOX_HPP
#include <SFML/System/Vector2.hpp>
#include <iostream>


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
            void print() {
                std::cout << "Box(pos=[" << pos.x << ", " << pos.y << "], size=[" << size.x << ", " << size.y << "])\n";
            }

    };

}


#endif