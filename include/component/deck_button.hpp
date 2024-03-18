#pragma once
#include "button.hpp"
#include "icon_button.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "text.hpp"
#include <fstream>


namespace yu {


    const sf::Vector2f DeckButtonSize(
        180.f, 
        210.f
    );

    class EmptyDeckButton : public yu::Button {

        public:
            EmptyDeckButton();

    };


    class DeckButton : public yu::Button {

        public:
            DeckButton(
                const std::filesystem::path& file
            );
            

    };

    class DeckButton : public yu::Button {

        public:
            static yu::DeckButton createEmptyDeckButton();
            static yu::DeckButton createDeckButtonFromFile(const std::filesystem::path& deckFile);

        private:            
            yu::Text text;
            yu::Rect text_bg;
            yu::Sprite icon;
            yu::Sprite iconHover; 
            bool isEmptyDeck;
            std::filesystem::path deckFile;

        public:            
            DeckButton(
                const std::string& name,
                const std::filesystem::path& imageFile,
                const bool emptyDeck
            );
            void draw(sf::RenderWindow& window);

            const std::filesystem::path& getDeckFile() const;
            bool emptyDeck() const;

    };
    
} // namespace yu
