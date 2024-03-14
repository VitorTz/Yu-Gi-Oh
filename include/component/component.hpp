#ifndef YUGIOH_COMPONENT_HPP
#define YUGIOH_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "../util/box.hpp"
#include "../util/util.hpp"
#include "../util/timer.hpp"
#include "../util/texture_pool.hpp"
#include "../util/font.hpp"
#include "../constants.hpp"
#include "../globals.hpp"


namespace yu {


    class Component {
         
        private:
            std::string name;
            int zIndex;
        
        protected:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Vector2f scale = {1.f, 1.f};
            sf::Vector2f direction;
            sf::Vector2f lastMovement;
            bool hovered = false;
            bool clicked = false;
            double rotation = 0;
            double speed = 0;

        public:
            explicit Component(
                const std::string& name                
            ) : Component(name, sf::Vector2f(), 0) { }
            Component(
                const std::string& name,
                const int zIndex
            ) : Component(name, sf::Vector2f(), zIndex) { }
            Component(
                const std::string& name,
                const sf::Vector2f pos,
                const int zIndex
            ) : name(name), zIndex(zIndex), pos(pos) { }
            virtual ~Component() = default;

            const std::string& getName() const { return name; }
            int getZindex() const { return zIndex; }

            void setSize(const sf::Vector2f x) { size = x; }
            void setPos(const sf::Vector2f x) { pos = x; }
            void setScale(const sf::Vector2f x) { scale = x; }
            
            const sf::Vector2f& getSize() const { return size; }
            const sf::Vector2f& getPos() const { return pos; }
            const sf::Vector2f& getScale() const { return scale; }

            float width() const { return size.x; }
            float height() const { return size.y; }
            
            void setWidth(const float w) { size.x = w; }
            void setHeight(const float h) { size.y = h; }

            float left() const { return pos.x; }
            float right() const { return pos.x + size.x; }
            float top() const { return pos.y; }
            float bottom() const { return pos.y + size.y; }

            float centerX() const { return pos.x + size.x / 2; }
            float centerY() const { return pos.y + size.y / 2; }
            
            void setCenterX(const float x) { pos.x = x - size.x / 2; }
            void setCenterY(const float y) { pos.y = y - size.y / 2; }

            sf::Vector2f center() const { return {pos.x + size.x / 2, pos.y + size.y / 2}; }
            void setCenter(const sf::Vector2f c) {
                pos.x = c.x - size.x / 2;
                pos.y = c.y - size.y / 2;
            }

            bool pointCollide(const sf::Vector2f p) {
                return (
                    p.x >= pos.x &&
                    p.x <= pos.x + size.x &&
                    p.y >= pos.y &&
                    p.y <= pos.y + size.y
                );
            }

            bool componentCollide(const yu::Component& c) {
                return (
                    c.left() >= pos.x &&
                    c.right() <= pos.x + size.x &&
                    c.top() >= pos.y &&
                    c.bottom() <= pos.y + size.y
                );
            }

            bool boxCollide(const yu::Box& b) {
                return (
                    b.pos.x >= pos.x &&
                    b.pos.x + b.size.x <= pos.x + size.x &&
                    b.pos.y >= pos.y &&
                    b.pos.y + b.size.y <= pos.y + size.y
                );
            }

            bool boxCollide(const sf::Vector2f p, const sf::Vector2f s) {
                return (
                    p.x >= pos.x &&
                    p.x + s.x <= pos.x + size.x &&
                    p.y >= pos.y &&
                    p.y + s.y <= pos.y + size.y
                );
            }

            virtual void move(const double dt) {
                lastMovement.x = dt * direction.x * speed;
                lastMovement.y = dt * direction.x * speed;
                pos += lastMovement;
            }

            const sf::Vector2f& getLastMovement() const { return lastMovement; }

            virtual void handleHover() { }
            virtual void handleClick() { }
            virtual void handleMouseEntry() { }
            virtual void handleMouseExit() { }

            bool isHovered() const { return hovered; }
            bool isClicked() const { return clicked; }
            
            virtual void update([[maybe_unused]] const double dt) {
                const bool oldHoverState = hovered;
                hovered = pointCollide(yu::globals::mousePos);
                clicked = yu::globals::mouseIsClicked && hovered;
                if (hovered) handleHover();
                if (!oldHoverState && hovered) handleMouseEntry();
                if (oldHoverState && !hovered) handleMouseExit();
            }

            virtual void draw([[maybe_unused]] sf::RenderWindow& window) {

            }

            double getSpeed() const { return speed; }
            void setSpeed(const double s) { speed = s; }

            double getRotation() const { return rotation; }
            void setRotation(const double r) { rotation = r; }

    };

}


#endif