#ifndef YUGIOH_RECT_HPP
#define YUGIOH_RECT_HPP
#include "component.hpp"


namespace yu {

    class Rect : public yu::Component {

        private:
            sf::Color color;   
            yu::style::border_style_t border_style;
            sf::RectangleShape rect;

        public:
            Rect(
                const std::string& name,
                const sf::Vector2f pos, 
                const sf::Vector2f size,
                const int zIndex,
                const sf::Color color,
                const yu::style::border_style_t& border_style
            );
            
            void draw(sf::RenderWindow& window);            

    };

}

#endif