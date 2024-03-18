#include "../../include/util/util.hpp"


int yu::randint(const int start, const int end) {
    // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c#13445752
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> d(start, end-1); // distribution in range [1, 6]
    return d(rng);
}


void yu::drawBorder(
    const yu::box_t& box, 
    const sf::Color color, 
    const float thickness,
    sf::RenderWindow& window
) {
    sf::RectangleShape rect;
    
    rect.setFillColor(color);
    rect.setPosition(box.pos);
    rect.setSize({box.width(), thickness});
    window.draw(rect);

    rect.setPosition({box.pos.x, box.bottom()});
    window.draw(rect);

    rect.setSize({thickness, box.height()});
    rect.setPosition(box.pos);
    window.draw(rect);

    rect.setPosition(box.right() - thickness, box.pos.y);
    window.draw(rect);

}


std::filesystem::path yu::getCardPath(const std::string& cardCode) {
    std::filesystem::path path = yu::constants::cardsDir.string() + '/' + cardCode[0] + '/' + cardCode + ".jpg";
    return path;
}