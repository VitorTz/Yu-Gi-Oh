#ifndef YUGIOH_COMPONENT_HPP
#define YUGIOH_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>
#include "../util/box.hpp"
#include "../util/util.hpp"
#include "../util/timer.hpp"
#include "../util/style.hpp"
#include "../constants.hpp"
#include "../globals.hpp"
#include "../colors.hpp"


namespace yu {


    class Component {

        private:
            std::string name;
            int zIndex;
        
        protected:
            sf::Vector2f pos;
            sf::Vector2f size;
        
        public:            
            Component(
                const std::string& name_, 
                const int zIndex = 0,
                const sf::Vector2f pos = {0.f, 0.f},
                const sf::Vector2f size = {0.f, 0.f}
            ) : name(name_), zIndex(zIndex), pos(pos), size(size) { }
            virtual ~Component() = default;
            
            virtual void update([[maybe_unused]] double dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            
            const std::string& getName() const { return name; }
            int getZindex() const { return zIndex; }
            
            const sf::Vector2f& getPos() const { return pos; }
            const sf::Vector2f& getSize() const { return size; }
            void setSize(const sf::Vector2f s) { size = s; }
            void setPos(const sf::Vector2f p) { pos = p; }

            float left() const { return pos.x; }
            float right() const { return pos.x + size.x; }
            float top() const { return pos.y; }
            float bottom() const { return pos.y + size.y; }

            virtual void setLeft(const float left) { pos.x = left; }
            virtual void setRight(const float right) { pos.x = right - size.x; }
            virtual void setTop(const float top) { pos.y = top; }
            virtual void setBottom(const float bottom) { pos.x = bottom - size.y; }

            float centerX() const { return pos.x + size.x / 2; };
            float centerY() const { return pos.y + size.y / 2; };
            
            virtual void setCenter(const yu::Box& box) {                
                setCenter(box.center());
            }

            virtual void setCenterX(const float x) { pos.x = x - size.x / 2; }
            virtual void setCenterY(const float y) { pos.y = y - size.y / 2; }

            sf::Vector2f center() const { return {pos.x + size.x / 2, pos.y + size.y / 2}; }
            virtual void setCenter(const sf::Vector2f center) { 
                pos.x = center.x - size.x / 2;
                pos.y = center.y - size.y / 2;
            }
            virtual void setCenter(const float x, const float y) { 
                pos.x = x - size.x / 2;
                pos.y = y - size.y / 2;
            }

            float width() const { return size.x; }
            float height() const { return size.y; }

            void move(const float x, const float y) {
                pos.x += x;
                pos.y += y;
            }

            bool isInsideBox(const yu::Box& box) const {
                return (
                    pos.x >= box.pos.x &&
                    pos.y >= box.pos.y &&
                    bottom() <= box.bottom() &&
                    right() <= box.right()
                );
            }

            bool on_hover() const {
                const sf::Vector2f& mPos = yu::globals::mousePos;
                return (
                    mPos.x >= pos.x && 
                    mPos.x <= pos.x + size.x &&
                    mPos.y >= pos.y &&
                    mPos.y <= pos.y + size.y
                );
            }

            bool clicked() const {
                return yu::globals::mouseIsClicked && on_hover();
            }

            void drawBorder(const yu::style::border_style_t& border, sf::RenderWindow& window) {
                sf::RectangleShape rect;
                if (border.thickness > 0) {
                    const float t = (float) border.thickness;
                    rect.setSize({size.x, t});
                    rect.setFillColor(border.color);
                    window.draw(rect);
                    
                    rect.setPosition({pos.x, bottom()});
                    window.draw(rect);

                    rect.setSize({t, size.y});
                    rect.setPosition(pos);
                    window.draw(rect);

                    rect.setPosition({right() - t, pos.y});
                    window.draw(rect);
                }
            }

    };

}

#endif