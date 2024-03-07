#ifndef YUGIOH_FONT_HPP
#define YUGIOH_FONT_HPP
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <filesystem>
#include <map>


namespace yu {


    enum FontId {
        Light,
        Regular,
        Semibold,
        Bold
    };

    const std::map<yu::FontId, std::filesystem::path> fontPathMap = {
        {yu::FontId::Light, "assets/font/Poppins-Light.ttf"},
        {yu::FontId::Regular, "assets/font/Poppins-Regular.ttf"},
        {yu::FontId::Semibold, "assets/font/Poppins-SemiBold.ttf"},
        {yu::FontId::Bold, "assets/font/Poppins-Bold.ttf"}
    };  

    class FontPool {

        private:
            static std::map<yu::FontId, std::unique_ptr<sf::Font>> fontMap;
        
        public:
            static void load(sf::Text* text, yu::FontId fontId);
            static sf::Font* get(yu::FontId fontId);
            static void erase(yu::FontId fontId);

    };

}


#endif