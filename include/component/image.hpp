#ifndef YUGIOH_IMAGE_HPP
#define YUGIOH_IMAGE_HPP
#include <filesystem>
#include "component.hpp"
#include "../util/texture_pool.hpp"


namespace yu {

    class Image : public yu::Component {

        private:
            std::filesystem::path path;
            sf::Sprite sprite;
            sf::Vector2f scale = {1.f, 1.f};

        public:
            Image(Image&& ) = default;
            explicit Image(const std::filesystem::path& path);
            ~Image() override;
            const sf::Vector2f& getScale() const;
            void setScale(const sf::Vector2f scale);
            void resize(sf::Vector2f size);
            void resize(float x, float y);
            void draw(sf::RenderWindow& window) override;            
            void change_image(const std::filesystem::path& path);

    };

}

#endif