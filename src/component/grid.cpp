#include "../../include/component/grid.hpp"


yu::Grid::Grid(
    const std::string& name,
    const sf::Vector2f pos,
    const int zIndex,
    const int paddingX,
    const int paddingY,
    const int columns
) : yu::Component(name, zIndex, pos),
    paddingX(paddingX),
    paddingY(paddingY),
    columns(columns) {

}


void yu::Grid::addComponent(
    std::unique_ptr<yu::Component> c 
) {
    const std::size_t n = components.size();    
    const int row = n / columns;
    const int col = n % columns;
    c->setPos(
        {
            pos.x + (c->width() + paddingX) * col,
            pos.y + (c->height() + paddingY) * row
        }
    );
    components.push_back(std::move(c));
}


void yu::Grid::update(const double dt) {
    for (std::unique_ptr<yu::Component>& c : components) {
        c->update(dt);
    }
}


void yu::Grid::draw(sf::RenderWindow& window) {
    for (std::unique_ptr<yu::Component>& c : components) {
        c->draw(window);
    }
}

const std::vector<std::unique_ptr<yu::Component>>& yu::Grid::getComponents() const {
    return components;
}


std::size_t yu::Grid::size() const {
    return components.size();
}