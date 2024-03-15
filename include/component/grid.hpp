#ifndef YUGIOH_GRID_HPP
#define YUGIOH_GRID_HPP
#include "component.hpp"
#include <memory>
#include <vector>



namespace yu {

    class Grid : public yu::Component {

        private:            
            const int columns;
            const int padding;
        
        private:
            void updateItemsPos();

        public:
            std::vector<std::unique_ptr<yu::Component>> items;

        
        public:
            Grid(
                const std::string& name,
                const sf::Vector2f pos,
                int zIndex,
                int columns,
                int padding
            );
            void addItem(std::unique_ptr<yu::Component>);
            void rmvItem(const std::string& name);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;


    };

}



#endif