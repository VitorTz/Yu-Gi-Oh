#include "../../include/component/grid.hpp"
#include <memory>



yu::Grid::Grid(
    const std::string& name,
    const sf::Vector2f pos,
    const int zIndex,    
    const int columns,
    const int padding
) : yu::Component(name, pos, zIndex),    
    columns(columns),
    padding(padding) {

}

void yu::Grid::updateItemsPos() {
    for (std::size_t i = 0; i < items.size(); i++) {
        const int row = i / columns;
        const int col = i % columns;
        std::unique_ptr<yu::Component>& c = items[i];
        std::cout << i << ' ' << row << ' ' << col << '\n';
        c->setPos(
            {
                pos.x + col * (c->width() + padding),
                pos.y + row * (c->height() + padding)
            }
        );
    }
}


void yu::Grid::addItem(std::unique_ptr<yu::Component> c) {    
    const std::size_t i = items.size();
    const int row = i / columns;
    const int col = i % columns; 
    c->setPos(
        {
            pos.x + col * (c->width() + padding),
            pos.y + row * (c->height() + padding)
        }
    );
    items.push_back(std::move(c));
}


void yu::Grid::rmvItem(const std::string& componentName) {
    for (std::size_t i = 0; i < items.size(); i++) {
        if (items[i]->getName() == componentName) {
            items.erase(items.begin() + i);
            updateItemsPos();
            return;
        }
    }
}


void yu::Grid::update(const double dt) {
    yu::Component::update(dt);
    for (std::unique_ptr<yu::Component>& c : items) {
        c->update(dt);        
    }
}


void yu::Grid::draw(sf::RenderWindow& window) {
    for (std::unique_ptr<yu::Component>& c : items) {
        c->draw(window);
    }
}