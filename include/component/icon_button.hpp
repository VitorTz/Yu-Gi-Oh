#pragma once
#include "button.hpp"
#include "sprite.hpp"


namespace yu {


    class IconButton : public yu::Button {

        private:
            yu::Sprite icon;

        protected:
            void handleMouseEntry() override;
            void handleMouseExit() override;

        public:
            IconButton(
                const std::string& name,
                const std::filesystem::path& iconFile,
                const yu::VoidFunc& func,
                const sf::Vector2f pos,
                int zIndex
            );
            void draw(sf::RenderWindow& window);

    };
    
} // namespace yu
