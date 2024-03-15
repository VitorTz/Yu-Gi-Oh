#ifndef YUGIOH_TEXT_BTN_HPP
#define YUGIOH_TEXT_BTN_HPP
#include "button.hpp"
#include "text.hpp"
#include "rect.hpp"


namespace yu { 


    class TextBtn : public yu::Button {

        private:
            yu::Text text;
            yu::Rect rect;            

        public:
            TextBtn(
                const std::string& name,
                const std::string& text,
                const yu::VoidFunction& func,
                const sf::Vector2f pos,
                const sf::Vector2f size,
                const int zIndex,
                const yu::style::color_style_t& color,
                const yu::style::text_style_t& style,
                const yu::style::border_t& border
            );        
            void update(double dt) override;    
            void draw(sf::RenderWindow& window) override;

    };

}


#endif