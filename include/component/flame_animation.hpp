#ifndef YUGIOH_FLAME_ANIMATION_HPP
#define YUGIOH_FLAME_ANIMATION_HPP
#include <map>
#include <array>
#include "component.hpp"
#include "image.hpp"


namespace yu {
    
    const std::size_t NUM_FLAMES = 30;
    const std::array<float, 4> FLAME_SPEED = {4.f, 6.f, 8.f, 12.f};
    const std::array<float, 3> FLAME_DIRECTIONS = {-1.f, 0.f, 1.f};
    const std::string FLAME_ANIMATION_DIR("assets/FlameAnimation");

    typedef struct flame {
        float speed;
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::Vector2f direction;
    } flame_t;

    class FlameAnimation : public yu::Component {

        private:
            std::map<float, yu::Image> flamePool;
            std::array<flame_t, NUM_FLAMES> flames;            
            yu::Box box;
        
        private:
            float randomSpeed() const;
            sf::Vector2f randomPos() const;
            sf::Vector2f randomDirection() const;
            flame_t randomFlame() const;
        
        public:
            FlameAnimation(const int zIndex, const yu::Box box);
            ~FlameAnimation() override;
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif