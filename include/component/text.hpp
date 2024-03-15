#ifndef YUGIOH_TEXT_HPP
#define YUGIOH_TEXT_HPP
#include "component.hpp"
#include "../util/font.hpp"
#include <cmath>


namespace yu {

    class Text : public yu::Component {

        private:
            std::string str;
            sf::Text text;
            yu::style::text_style_t style;

        public:
            Text(
                const std::string& name,
                const std::string& txt,                
                const sf::Vector2f pos,
                const yu::style::text_style_t& style,
                int zIndex
            );
            void setPos(const sf::Vector2f p) override;
            void setTop(const float t) override;
            void setBottom(const float b) override;
            void setCenter(const sf::Vector2f c) override;
            void setCenterY(const float y) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif