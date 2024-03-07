#ifndef YUGIOH_TEXT_HPP
#define YUGIOH_TEXT_HPP
#include "component.hpp"
#include "../util/font.hpp"


namespace yu {

    class Text : public yu::Component {

        private:
            sf::Text text;

        public:
            Text(
                const std::string& name,
                const std::string& txt,
                const int zIndex,
                const sf::Vector2f pos,
                const yu::style::text_style_t& style
            );
            void draw(sf::RenderWindow& window) override;
            void setCenter(const sf::Vector2f center) override;

    };

}

#endif