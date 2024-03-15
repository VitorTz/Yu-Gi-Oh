#include "../../include/util/deck.hpp"
#include <filesystem>
#include <string>



yu::Deck::Deck(
    const std::filesystem::path& file
) : name(file.stem().string()) {    
    std::ifstream ifs;
    ifs.open(file);   
    std::string line;
    std::size_t i = 0;
    if (ifs.is_open()) {
        while (std::getline(ifs, line) && i < 40) {            
            cards[i] = std::stoi(line);
            ++i;
        }
        ifs.close();
    }
}


void yu::Deck::dump() const {
    std::filesystem::path file("db/decks/" + name + ".txt");
    std::ofstream ofs (file);
    if (ofs.is_open()) {
        for (const int i : cards) {
            ofs << i << '\n';
        }
        ofs.close();        
    }    
}


std::size_t yu::Deck::size() const {
    return cards.size();
}


const std::array<int, 40>& yu::Deck::getCards() const {
    return cards;
}


yu::DeckPool::DeckPool() {
    std::filesystem::path deckDir("db/decks");
    for (const auto& p : std::filesystem::directory_iterator(deckDir)) {
        const std::filesystem::path path = p.path();
        deckMap.insert({path.stem().string(), yu::Deck(path)});
    }
}


bool yu::DeckPool::deckNameIsValid(const std::string& name) {
    return deckMap.find(name) == deckMap.end();
}
