#pragma once
#include "component.hpp"
#include <map>
#include <memory>


namespace yu {


    typedef std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TextureMap;

    class Sprite : public yu::Component {

        private:
            static TextureMap textureMap;
        
        public:
            static void textureLoad(sf::Sprite* sprite, const std::filesystem::path& file);
            static sf::Texture* textureCreate(const std::filesystem::path& file);
            static void textureDestroy(const std::filesystem::path& file);            
            static void textureClear();

        private:
            sf::Sprite sprite;
            std::filesystem::path file;
        
        public:    
            Sprite(const std::string& name, int zIndex);
            Sprite(
                const std::string& name,
                const std::filesystem::path& file,
                int zIndex,
                const sf::Vector2f pos
            );
            Sprite(
                const std::filesystem::path& file,
                int zIndex,
                const sf::Vector2f pos
            );
            void resize(const sf::Vector2f pos);
            void resize(float width, float height);
            void changeTexture(const std::filesystem::path& file);
            void deleteTexture();
            void draw(sf::RenderWindow& window) override;
            const std::filesystem::path& getFile() const;

    };
    
} // namespace yu
