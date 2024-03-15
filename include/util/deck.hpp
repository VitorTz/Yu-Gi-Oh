#ifndef YUGIOH_DECK_HPP
#define YUGIOH_DECK_HPP
#include <filesystem>
#include <map>
#include <string>
#include <fstream>
#include <array>


namespace yu {


    class Deck {

        private:
            std::string name;
            std::array<int, 40> cards;            
        
        public:
            Deck() = default;
            explicit Deck(const std::filesystem::path& file);            
            int operator[](const std::size_t idx) const { return cards[idx]; }
            void dump() const;
            std::size_t size() const;
            const std::array<int, 40>& getCards() const;
            const std::string& getName() const;

    };

    
    class DeckPool {
        
        public:
            std::map<std::string, Deck> deckMap;
        
        public:
            DeckPool();
            yu::Deck* getDeck(const std::string& name);
            bool deckNameIsValid(const std::string& name);
        
    };



}



#endif