#pragma once
#include "component.hpp"
#include <vector>


namespace yu {

    class Grid : public yu::Component {

        private:
            std::vector<std::unique_ptr<yu::Component>> components;
            int columns;

        public:
            Grid(
                const std::string& name,
                const sf::Vector2f pos,
                int zIndex,
                int paddingX,
                int paddingY,
                int columns
            );
            void addComponent(std::unique_ptr<yu::Component> c);
            void update(double dt) override;
            void draw(sf::RenderWindow& window);

    };
    
} // namespace yu
