#pragma once
#include "button.hpp"
#include "rect.hpp"
#include "text.hpp"


namespace yu {


    class TextButton : public yu::Button {

        private:
            yu::Rect rect;
            yu::Text text;          
            yu::style::text_t text_style;  
            yu::style::color_t color_style;
        
        public:
            TextButton(
                const std::string& name,
                const std::string& text,
                const yu::VoidFunc& func,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                int zIndex,
                const yu::style::text_t& text_style,
                const yu::style::color_t& color_style
            );

            const yu::style::text_t& getTextStyle() const;
            const yu::style::color_t& getColorStyle() const;

            void setTextStyle(const yu::style::text_t& style);
            void setColorStyle(const yu::style::color_t& style);
            
            void update(double dt) override;            
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace yu
