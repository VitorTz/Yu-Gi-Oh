#include "../../include/component/component.hpp"


int yu::Component::componentCount = 0;


yu::Component::Component(
    const std::string& name,
    const int zIndex
) : name(name),
    zIndex(zIndex),
    pos(),
    size(),  
    scale({1.f, 1.f}),
    direction(),
    rotation(0.0),
    speed(0.0) {

}


yu::Component::Component(
    const std::string& name,
    int zIndex,
    const sf::Vector2f pos
) : name(name),
    zIndex(zIndex),
    pos(pos),
    size(),  
    scale({1.f, 1.f}),
    direction(),
    rotation(0.0),
    speed(0.0) {

    }


yu::Component::Component(
    const int zIndex
) : name("component-" + std::to_string(yu::Component::componentCount++)),
    zIndex(zIndex),
    pos(),
    size(),  
    scale({1.f, 1.f}),
    direction(),
    rotation(0.0),
    speed(0.0) {

}



yu::Component::Component(
    const std::string& name,
    const int zIndex,
    const sf::Vector2f pos,
    const sf::Vector2f size
) : name(name),
    zIndex(zIndex),
    pos(pos),
    size(size),  
    scale({1.f, 1.f}),
    direction(),
    rotation(0.0),
    speed(0.0) {

}


yu::Component::Component(
    const std::string& name,
    const int zIndex,
    const sf::Vector2f pos = { },
    const sf::Vector2f size = { },  
    const sf::Vector2f scale = {1.f, 1.f},
    const sf::Vector2f direction = { },
    const double rotation = 0.0,
    const double speed = 0.0
) : name(name),
    zIndex(zIndex),
    pos(pos),
    size(size),
    scale(scale),
    direction(direction),
    rotation(rotation),
    speed(speed) {

    }


yu::Component::~Component() = default;

const std::string& yu::Component::getName() const { 
    return name; 
}

int yu::Component::getZindex() const { 
    return zIndex; 
}

void yu::Component::setSize(const sf::Vector2f x) { 
    size = x; 
}

void yu::Component::setPos(const sf::Vector2f x) { 
    pos = x; 
}

void yu::Component::setScale(const sf::Vector2f x) { 
    scale = x; 
}

const sf::Vector2f& yu::Component::getSize() const { 
    return size; 
}

const sf::Vector2f& yu::Component::getPos() const { 
    return pos; 
}

const sf::Vector2f& yu::Component::getScale() const { 
    return scale; 
}


float yu::Component::width() const { 
    return size.x; 
}

float yu::Component::height() const { 
    return size.y; 
}

void yu::Component::setWidth(const float w) { 
    size.x = w; 
}

void yu::Component::setHeight(const float h) { 
    size.y = h; 
}

float yu::Component::left() const { 
    return pos.x; 
}

float yu::Component::right() const { 
    return pos.x + size.x; 
}

float yu::Component::top() const { 
    return pos.y; 
}

float yu::Component::bottom() const { 
    return pos.y + size.y; 
}

void yu::Component::setLeft(const float l) { 
    pos.x = l; 
}

void yu::Component::setRight(const float r) { 
    pos.x = r - size.x; 
}

void yu::Component::setTop(const float t) { 
    pos.y = t; 
}

void yu::Component::setBottom(const float b) { 
    pos.y = b - size.y; 
}

float yu::Component::centerX() const { 
    return pos.x + size.x / 2; 
}

float yu::Component::centerY() const { 
    return pos.y + size.y / 2; 
}

void yu::Component::setCenterX(const float x) { 
    pos.x = x - size.x / 2; 
}

void yu::Component::setCenterX(const yu::box_t& box) { 
    pos.x = (box.pos.x + box.size.x / 2) - size.x / 2; 
}

void yu::Component::setCenterY(const float y) { 
    pos.y = y - size.y / 2; 
}

void yu::Component::setCenterY(const yu::box_t& box) { 
    pos.y = (box.pos.y + box.size.y / 2) - size.y / 2; 
}

sf::Vector2f yu::Component::center() const { 
    return {pos.x + size.x / 2, pos.y + size.y / 2}; 
}

void yu::Component::setCenter(const sf::Vector2f c) {
    pos.x = c.x - size.x / 2;
    pos.y = c.y - size.y / 2;
}

void yu::Component::setCenter(const yu::box_t& box) {
    pos.x = (box.pos.x + box.size.x / 2) - size.x / 2;
    pos.y = (box.pos.y + box.size.y / 2) - size.y / 2;
}

double yu::Component::getSpeed() const { 
    return speed; 
}

void yu::Component::setSpeed(const double s) { 
    speed = s; 
}

double yu::Component::getRotation() const { 
    return rotation; 
}

void yu::Component::setRotation(const double r) { 
    rotation = r; 
}

bool yu::Component::pointCollide(const sf::Vector2f p) {
    return (
        p.x >= pos.x &&
        p.x <= pos.x + size.x &&
        p.y >= pos.y &&
        p.y <= pos.y + size.y
    );
}

bool yu::Component::componentCollide(const yu::Component& c) {
    return (
        c.left() >= pos.x &&
        c.right() <= pos.x + size.x &&
        c.top() >= pos.y &&
        c.bottom() <= pos.y + size.y
    );
}

bool yu::Component::boxCollide(const yu::box_t& box) {
    return (
        box.pos.x >= pos.x &&
        box.pos.x + box.size.x <= pos.x + size.x &&
        box.pos.y >= pos.y &&
        box.pos.y + box.size.y <= pos.y + size.y
    );
}

void yu::Component::move(const double dt) {
    lastMovement.x = dt * direction.x * speed;
    lastMovement.y = dt * direction.x * speed;
    pos += lastMovement;
}

const sf::Vector2f& yu::Component::getLastMovement() const { 
    return lastMovement; 
}

bool yu::Component::isHovered() const { 
    return hovered; 
}

bool yu::Component::isClicked() const { 
    return clicked; 
}

void yu::Component::handleHover() { }

void yu::Component::handleClick() { }

void yu::Component::handleMouseEntry() { }

void yu::Component::handleMouseExit() { }

void yu::Component::update([[maybe_unused]] const double dt) {
    const bool oldHoverState = hovered;                
    hovered = pointCollide(yu::globals::mousePos);
    clicked = yu::globals::mouseIsClicked && hovered;
    if (yu::globals::windowHasFocus) {
        if (hovered) handleHover();
        if (clicked) handleClick(); 
        if (!oldHoverState && hovered) handleMouseEntry();
        if (oldHoverState && !hovered) handleMouseExit();
    }
}

void yu::Component::draw([[maybe_unused]] sf::RenderWindow& window) {

}