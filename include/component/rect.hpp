#ifndef YUGIOH_RECT_HPP
#define YUGIOH_RECT_HPP
#include "component.hpp"
#include "../util/style.hpp"


namespace yu {


    class Rect : public yu::Component {

        private:
            sf::RectangleShape rect;
            yu::style::color_style_t color;
            yu::style::border_t border;

        public:
            Rect(
                const std::string& name,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                int zIndex,
                const yu::style::color_style_t& color,
                const yu::style::border_t& border
            );
            void update(double dt) override;            
            void draw(sf::RenderWindow& window) override;

    };

}

#endif