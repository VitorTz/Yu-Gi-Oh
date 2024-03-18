#ifndef YUGIOH_COMPONENT_HPP
#define YUGIOH_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "../util/util.hpp"
#include "../util/sound_system.hpp"
#include "../util/style.hpp"
#include "../util/box.hpp"
#include "../util/timer.hpp"
#include "../constants.hpp"
#include "../globals.hpp"


namespace yu {


    class Component {

        private:
            static int componentCount;
         
        private:
            std::string name;
            int zIndex;

        private:
            virtual void handleHover();
            virtual void handleClick();
            virtual void handleMouseEntry();
            virtual void handleMouseExit();
        
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
                int zIndex
            );
            Component(
                const std::string& name,
                int zIndex
            );
            Component(
                const std::string& name,
                int zIndex,
                const sf::Vector2f pos
            );
            Component(
                const std::string& name,
                const int zIndex,
                const sf::Vector2f pos,
                const sf::Vector2f size
            );
            Component(
                const std::string& name,
                int zIndex,
                const sf::Vector2f pos,
                const sf::Vector2f size,   
                const sf::Vector2f scale,
                const sf::Vector2f direction,
                double rotation,
                double speed
            );
            virtual ~Component();

            const std::string& getName() const;
            int getZindex() const;

            virtual void setSize(const sf::Vector2f x);
            virtual void setPos(const sf::Vector2f x);
            virtual void setScale(const sf::Vector2f x);
            
            const sf::Vector2f& getSize() const;
            const sf::Vector2f& getPos() const;
            const sf::Vector2f& getScale() const;

            float width() const;
            float height() const;
            
            virtual void setWidth(const float w);
            virtual void setHeight(const float h);

            float left() const;
            float right() const;
            float top() const;
            float bottom() const;
            
            virtual void setLeft(const float l);
            virtual void setRight(const float r);
            virtual void setTop(const float t);
            virtual void setBottom(const float b);

            float centerX() const;
            float centerY() const;
            
            virtual void setCenterX(const float x);
            virtual void setCenterX(const yu::box_t& box);
            
            virtual void setCenterY(const float y);
            virtual void setCenterY(const yu::box_t& box);
            
            sf::Vector2f center() const;
            virtual void setCenter(const sf::Vector2f c);
            virtual void setCenter(const yu::box_t& box);

            virtual bool pointCollide(const sf::Vector2f p);                        
            virtual bool componentCollide(const yu::Component& c);
            virtual bool boxCollide(const yu::box_t& box);            

            virtual void move(const double dt);
            const sf::Vector2f& getLastMovement() const;

            bool isHovered() const;
            bool isClicked() const;
            
            double getSpeed() const;
            virtual void setSpeed(const double s);

            double getRotation() const;
            virtual void setRotation(const double r);

            virtual void update(double dt);                
            virtual void draw([[maybe_unused]] sf::RenderWindow& window);


    };

}


#endif