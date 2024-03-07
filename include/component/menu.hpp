#ifndef YUGIOH_MENU_HPP
#define YUGIOH_MENU_HPP
#include "component.hpp"
#include "button.hpp"
#include <memory>
#include <vector>


namespace yu {


    class Menu : public yu::Component {

        private:
            std::vector<std::unique_ptr<yu::Button>> buttons;
            int clicked_btn = -1;            
            const int padding;
        
        private:
            void updateBtnsPos();

        public:
            Menu(
                const std::string& name,
                const sf::Vector2f pos,
                const int padding,                
                const int zIndex
            );
            void addBtn(std::unique_ptr<yu::Button> btn);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
            void handleBtnClick();            
    };

}

#endif