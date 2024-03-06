#ifndef YUGIOH_COMPONENT_HPP
#define YUGIOH_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>
#include "../util/util.hpp"
#include "../constants.hpp"


namespace yu {


    class Component {

        private:
            std::string name;
        
        protected:
            sf::Vector2f pos;
            sf::Vector2f size;
        
        public:
            Component(const std::string& name_) : name(name_) { }
            virtual ~Component() = default;
            virtual void update([[maybe_unused]] double dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            const std::string& getName() const { return name; }
            
            const sf::Vector2f& getPos() const { return pos; }
            const sf::Vector2f& getSize() const { return size; }
            void setSize(const sf::Vector2f s) { size = s; }
            void setPos(const sf::Vector2f p) { pos = p; }

            float left() const { return pos.x; }
            float right() const { return pos.x + size.x; }
            float top() const { return pos.y; }
            float bottom() const { return pos.y + size.y; }

            void setLeft(const float left) { pos.x = left; }
            void setRight(const float right) { pos.x = right - size.x; }
            void setTop(const float top) { pos.y = top; }
            void setBottom(const float bottom) { pos.x = bottom - size.y; }

            float centerX() const { return pos.x + size.x / 2; };
            float centerY() const { return pos.y + size.y / 2; };
            void setCenterX(const float x) { pos.x = x - size.x / 2; }
            void setCenterY(const float y) { pos.y = y - size.y / 2; }

            sf::Vector2f center() const { return {pos.x + size.x / 2, pos.y + size.y / 2}; }
            void setCenter(const sf::Vector2f center) { 
                pos.x = center.x - size.x / 2;
                pos.y = center.y - size.y / 2;
            }
            void setCenter(const float x, const float y) { 
                pos.x = x - size.x / 2;
                pos.y = y - size.y / 2;
            }

            float width() const { return size.x; }
            float height() const { return size.y; }

    };

}

#endif