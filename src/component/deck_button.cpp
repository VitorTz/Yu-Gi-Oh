#include "../../include/component/deck_button.hpp"


yu::DeckButton yu::DeckButton::createEmptyDeckButton() {
    yu::DeckButton deck("Empty", "assets/icons/plus.png", true);
    return deck;
}


yu::DeckButton yu::DeckButton::createDeckButtonFromFile(
    const std::filesystem::path& path
) {
    std::ifstream file;
    file.open(path);
    
    if (file.is_open()) {
        std::string cardCode;
        std::getline(file, cardCode);        
        file.close();
        std::filesystem::path cardPath = yu::getCardPath(cardCode);        
        yu::DeckButton deck(path.stem().string(), cardPath, false);
        return deck;
    } else {
        std::cerr << "Falha ao abrir o deck " << path << '\n';
        std::exit(1);
    }
}


yu::DeckButton::DeckButton(
    const std::string& name,
    const std::filesystem::path& imageFile,
    const bool isEmptyDeck
) : yu::Button(
    "deck-btn",
    []() { },
    { },
    0
), text("txt", name, yu::style::text_t{yu::FontId::Regular, yu::colors::YELLOW_200, 14}, sf::Vector2f(), 0),  
   text_bg("bg", 0, { }, { yu::DeckButtonSize.x, 30.f }, sf::Color(0, 0, 0, 120)),
   icon("icon", imageFile, 0, sf::Vector2f()),
   iconHover("iconHover", "assets/icons/plus-hover.png", 0, sf::Vector2f()),
   isEmptyDeck(isEmptyDeck),
   deckFile(imageFile) {
    this->size = yu::DeckButtonSize;
    text.shrink(yu::DeckButtonSize.x - 10.f);
    if (icon.width() > 100.f) {
        icon.resize(100.f, 145.f);
    }
}


void yu::DeckButton::draw(sf::RenderWindow& window) {
    text_bg.setLeft(pos.x);
    text_bg.setBottom(bottom());
    text_bg.draw(window);

    yu::drawBorder(
        yu::box_t{pos, yu::DeckButtonSize}, 
        hovered ? yu::colors::YELLOW_600 : yu::colors::YELLOW_200, 
        2.f, 
        window
    );

    text.setLeft(pos.x + 5.f);
    text.setBottom(bottom() - 5.f);
    
    text.setColor(hovered ? yu::colors::YELLOW_600 : yu::colors::YELLOW_200);
    text.draw(window);

    iconHover.setCenter(center());
    icon.setCenter(center());    

    hovered && isEmptyDeck ? iconHover.draw(window) : icon.draw(window);    

}


bool yu::DeckButton::emptyDeck() const {
    return isEmptyDeck;
}


const std::filesystem::path& yu::DeckButton::getDeckFile() const {
    return deckFile;
}