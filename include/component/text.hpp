#pragma once
#include "component.hpp"
#include <cmath>


namespace yu {

    typedef std::map<yu::FontId, std::unique_ptr<sf::Font>> FontMap;

    class Text : public yu::Component {

        private:
            static FontMap fontMap;
            static void fontLoad(sf::Text* text, yu::FontId font);
            static sf::Font* fontCreate(yu::FontId font);
            static void fontDestroy(yu::FontId font);

        private:
            sf::Text text;
            std::string str;
            yu::style::text_t style;

        public:
            Text(
                const std::string& name,
                const std::string& str,
                const yu::style::text_t& style,
                const sf::Vector2f pos,
                int zIndex
            );            
            
            void draw(sf::RenderWindow& window);
            
            std::size_t getStrSize() const;
            const std::string& getStr() const;
            void setStr(const std::string& str);

            const yu::style::text_t& getTextStyle() const;
            void setTextStyle(const yu::style::text_t& style);

            void setColor(const sf::Color color);
            
            void shrink(float width);


    };
    
} // namespace yu
