#include "../../include/component/flame_animation.hpp"


yu::FlameAnimation::FlameAnimation(
    const int zIndex,
    const yu::Box box
) : yu::Component("FlameAnimation", zIndex),
    box(box) {
    for (const float speed : FLAME_SPEED) {
        flamePool.insert(
            {speed, yu::Image(FLAME_ANIMATION_DIR + '/' + std::to_string( (int) speed) + ".png", sf::Vector2f(), 0)}
        );
    }
    for (std::size_t i = 0; i < flames.size(); i++) {
        flames[i] = randomFlame();        
    }
}


yu::FlameAnimation::~FlameAnimation() {
    for (const auto& p : std::filesystem::directory_iterator(FLAME_ANIMATION_DIR)) {
        yu::TexturePool::erase(p.path());
    }
}


yu::flame_t yu::FlameAnimation::randomFlame() const {
    const float speed = randomSpeed();
    flame_t flame{
        speed, 
        randomPos(), 
        flamePool.at(speed).getSize(),
        randomDirection()
    };
    return flame;
}


float yu::FlameAnimation::randomSpeed() const {
    return FLAME_SPEED[yu::randint(0, yu::FLAME_SPEED.size())];
}


sf::Vector2f yu::FlameAnimation::randomPos() const {
    return {
        (float) yu::randint(box.left(), box.right()),
        (float) yu::randint(box.bottom(), box.bottom() + 100.f)   
    };
}


sf::Vector2f yu::FlameAnimation::randomDirection() const {
    sf::Vector2f d = {
        FLAME_DIRECTIONS[yu::randint(0, FLAME_DIRECTIONS.size())],
        -1.f
    };
    yu::normalizeVector(&d);
    return d;    
}


void yu::FlameAnimation::update(const double dt) {
    for (std::size_t i = 0; i < flames.size(); i++) {
        flame_t& flame = flames[i];
        const float distance = dt * flame.speed * 10.f;
        flame.pos.x += flame.direction.x * distance;
        flame.pos.y += flame.direction.y * distance;        
        if (
            flame.pos.y <= yu::constants::SCREEN_HEIGHT &&
            (
                flame.pos.y < 0 ||
                flame.pos.x < 0 ||
                flame.pos.x + flame.size.x > yu::constants::SCREEN_WIDTH
            )
        ) {
            flame.speed = randomSpeed();
            flame.pos = randomPos();
            flame.size = flamePool.at(flame.speed).getSize();
            flame.direction = randomDirection();
        }
    }
}


void yu::FlameAnimation::draw(sf::RenderWindow& window) {
    for (flame_t& flame : flames) {
        yu::Image& flameImage = flamePool.at(flame.speed);
        flameImage.setPos(flame.pos);
        flameImage.draw(window);
    }
}