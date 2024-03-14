#ifndef SFML_TEMPLATE_TEXTURE_POOL_HPP
#define SFML_TEMPLATE_TEXTURE_POOL_HPP
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <filesystem>
#include <map>
#include <memory>
#include <mutex>


namespace yu {

    typedef std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TextureMap;

    class TexturePool {

        private:
            static TextureMap texture_map;
            static std::mutex m;
        
        public:
            static void load(sf::Sprite* sprite, const std::filesystem::path& path);
            static sf::Texture* create(const std::filesystem::path& path);
            static void destroy(const std::filesystem::path& path);
            static void clear();
    };

}



#endif