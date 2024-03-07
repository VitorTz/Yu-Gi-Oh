#include "../../include/component/menu.hpp"
#include <memory>


yu::Menu::Menu(
    const std::string& name,
    const sf::Vector2f pos,
    const int padding,
    const int zIndex
) : yu::Component(name, zIndex, pos),
    padding(padding) {

}


void yu::Menu::updateBtnsPos() {
    float top = pos.y;
    for (std::unique_ptr<yu::Button>& btn : buttons) {
        btn->setLeft(pos.x);
        btn->setTop(top);
        top += padding + btn->height();
    }
}


void yu::Menu::addBtn(
    std::unique_ptr<yu::Button> button
) {
    buttons.push_back(std::move(button));
    updateBtnsPos();
}


void yu::Menu::update([[maybe_unused]] const double dt) {
    clicked_btn = -1;
    for (std::size_t i = 0; i < buttons.size(); i++) {
        std::unique_ptr<yu::Button>& btn = buttons[i];
        if (btn->clicked()) {
            clicked_btn = i;
            break;
        }        
    }    
}


void yu::Menu::draw(sf::RenderWindow& window) {
    for (std::unique_ptr<yu::Button>& btn : buttons) {
        btn->draw(window);
    }
}


void yu::Menu::handleBtnClick() {
    if (clicked_btn != -1) {
        buttons[clicked_btn]->runFunc();
    }
}
