#ifndef YUGIOH_IMAGE_BUTTON_HPP
#define YUGIOH_IMAGE_BUTTON_HPP
#include "button.hpp"
#include "image.hpp"
#include "text.hpp"


namespace yu {

    class ImageButton : public yu::Button {

        private:
            sf::RectangleShape background;
            yu::Image image;
            yu::Text text;

        public:
            ImageButton(
                const std::string& name,
                const sf::Vector2f pos,
                const yu::VoidFunction& func,
                const std::string& button_text,
                const yu::style::button_style_t& style,
                int zIndex
            );
            void draw(sf::RenderWindow& window) override;

    };

}

#endif