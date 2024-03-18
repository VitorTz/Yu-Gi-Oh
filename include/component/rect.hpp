#pragma once
#include "component.hpp"


namespace yu {


    class Rect : public yu::Component {

        private:
            sf::RectangleShape rect;
            yu::style::color_t color;            

        public:
            Rect(
                const std::string& name,
                int zIndex,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                const sf::Color color                
            );
            Rect(
                const std::string& name,
                int zIndex,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                const yu::style::color_t& color
            );
            Rect(
                const std::string& name,
                int zIndex,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                const sf::Color color,
                const sf::Color accentColor
            );
            void draw(sf::RenderWindow& window);
            const yu::style::color_t& getColorStyle() const;
            void setColorStyle(const yu::style::color_t& color_style);
    };
    
} // namespace yu
