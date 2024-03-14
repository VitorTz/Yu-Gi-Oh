#ifndef YUGIOH_SPRITE_HPP
#define YUGIOH_SPRITE_HPP
#include "component.hpp"


namespace yu {


    class Sprite : public yu::Component {

        private:
            sf::Sprite sprite;

        public:
            Sprite(
                const std::string& name, 
                const std::filesystem::path& path,
                const sf::Vector2f pos,
                int zIndex
            );
            Sprite(
                const std::filesystem::path& path,
                const sf::Vector2f pos,
                int zIndex
            );
            Sprite(
                const std::filesystem::path& path,
                int zIndex
            );
            void resize(const sf::Vector2f size);
            void resize(const float w, const float h);
            void draw(sf::RenderWindow& window);


    };

}


#endif